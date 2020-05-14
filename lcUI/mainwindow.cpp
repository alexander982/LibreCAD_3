#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace lc::ui;

MainWindow::MainWindow()
    :
    ui(new Ui::MainWindow),
    linePatternSelect(&cadMdiChild, this, true, true),
    lineWidthSelect(cadMdiChild.metaInfoManager(), this, true, true),
    colorSelect(cadMdiChild.metaInfoManager(), this, true, true),
    cliCommand(this),
    toolbar(&luaInterface, this)
{
    ui->setupUi(this);
    // new document and set mainwindow attributes
    cadMdiChild.newDocument();
    setWindowTitle(QObject::tr("LibreCAD"));
    setUnifiedTitleAndToolBarOnMac(true);
    setCentralWidget(&cadMdiChild);
    
    layers.setMdiChild(&cadMdiChild);

    // add widgets to correct positions
    addDockWidget(Qt::RightDockWidgetArea, &layers);
    addDockWidget(Qt::BottomDockWidgetArea, &cliCommand);
    addDockWidget(Qt::TopDockWidgetArea, &toolbar);

    toolbar.initializeToolbar(&linePatternSelect, &lineWidthSelect, &colorSelect);
    cadMdiChild.viewer()->autoScale();

    // connect required signals and slots
    ConnectInputEvents();
    showMaximized();

    // open qt bridge and run lua scripts
    luaInterface.initLua(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

lc::ui::widgets::CliCommand* MainWindow::getCliCommand(){
    return &cliCommand;
}

lc::ui::CadMdiChild* MainWindow::getCadMdiChild() {
    return &cadMdiChild;
}

lc::ui::widgets::Toolbar* MainWindow::getToolbar() {
    return &toolbar;
}

void MainWindow::ConnectInputEvents()
{   
    QObject::connect(cadMdiChild.viewerProxy(), &LCADViewerProxy::mousePressEvent, this, &MainWindow::triggerMousePressed);
    QObject::connect(cadMdiChild.viewerProxy(), &LCADViewerProxy::mouseReleaseEvent, this, &MainWindow::triggerMouseReleased);
    QObject::connect(cadMdiChild.viewerProxy(), &LCADViewerProxy::mouseMoveEvent, this, &MainWindow::triggerMouseMoved);
    QObject::connect(cadMdiChild.viewerProxy(), &LCADViewerProxy::keyPressEvent, this, &MainWindow::triggerKeyPressed);
    QObject::connect(&cadMdiChild, &CadMdiChild::keyPressed, &cliCommand, &widgets::CliCommand::onKeyPressed);

    QObject::connect(&cliCommand, &widgets::CliCommand::coordinateEntered, this, &MainWindow::triggerCoordinateEntered);
    QObject::connect(&cliCommand, &widgets::CliCommand::relativeCoordinateEntered, this, &MainWindow::triggerRelativeCoordinateEntered);
    QObject::connect(&cliCommand, &widgets::CliCommand::numberEntered, this, &MainWindow::triggerNumberEntered);
    QObject::connect(&cliCommand, &widgets::CliCommand::textEntered, this, &MainWindow::triggerTextEntered);
    QObject::connect(&cliCommand, &widgets::CliCommand::finishOperation, this, &MainWindow::triggerFinishOperation);
    QObject::connect(&cliCommand, &widgets::CliCommand::commandEntered, this, &MainWindow::triggerCommandEntered);

    QObject::connect(&layers, &widgets::Layers::layerChanged, &linePatternSelect, &widgets::LinePatternSelect::onLayerChanged);
    QObject::connect(&layers, &widgets::Layers::layerChanged, &lineWidthSelect, &widgets::LineWidthSelect::onLayerChanged);
    QObject::connect(&layers, &widgets::Layers::layerChanged, &colorSelect, &widgets::ColorSelect::onLayerChanged);

    QObject::connect(this, &MainWindow::point, this, &MainWindow::triggerPoint);
    QObject::connect(this->findChild<QAction*>("actionExit"), &QAction::triggered, this, &MainWindow::close);
}

/* Menu functions */

void MainWindow::connectMenuItem(const std::string& itemName, kaguya::LuaRef callback)
{
    luaInterface.luaConnect(this->findChild<QAction*>(QString(itemName.c_str())), "triggered(bool)", callback);
}

/* Trigger slots */

void MainWindow::triggerMousePressed()
{
    lc::geo::Coordinate cursorPos = cadMdiChild.cursor()->position();
    auto state = luaInterface.luaState();
    kaguya::LuaTable data(state);
    data["position"] = cursorPos;
    data["widget"] = &cadMdiChild;
    luaInterface.triggerEvent("point", data);

    emit point(cursorPos);
}

void MainWindow::triggerMouseReleased()
{
    auto state = luaInterface.luaState();
    kaguya::LuaTable data(state);
    data["widget"] = &cadMdiChild;
    luaInterface.triggerEvent("selectionChanged", data);
}

void MainWindow::triggerMouseMoved()
{
    lc::geo::Coordinate cursorPos = cadMdiChild.cursor()->position();
    auto state = luaInterface.luaState();
    kaguya::LuaTable data(state);
    data["position"] = cursorPos;
    data["widget"] = &cadMdiChild;
    luaInterface.triggerEvent("mouseMove", data);
}

void MainWindow::triggerKeyPressed(int key)
{
    if (key == Qt::Key_Escape)
    {
        // run finish operation
        auto state = luaInterface.luaState();
        luaInterface.triggerEvent("finishOperation", kaguya::LuaRef(state));
    }
    else
    {
        auto state = luaInterface.luaState();
        kaguya::LuaTable data(state);
        data["key"] = key;
        data["widget"] = &cadMdiChild;
        luaInterface.triggerEvent("keyPressed", data);
    }
}

void MainWindow::triggerCoordinateEntered(lc::geo::Coordinate coordinate)
{
    auto state = luaInterface.luaState();
    kaguya::LuaTable data(state);
    data["position"] = coordinate;
    data["widget"] = &cadMdiChild;
    luaInterface.triggerEvent("point", data);

    emit point(coordinate);
}

void MainWindow::triggerRelativeCoordinateEntered(lc::geo::Coordinate coordinate)
{
    auto state = luaInterface.luaState();
    kaguya::LuaTable data(state);
    data["position"] = lastPoint + coordinate;
    data["widget"] = &cadMdiChild;
    luaInterface.triggerEvent("point", data);

    emit point(lastPoint + coordinate);
}

void MainWindow::triggerNumberEntered(double number)
{
    auto state = luaInterface.luaState();
    kaguya::LuaTable data(state);
    data["number"] = number;
    data["widget"] = &cadMdiChild;
    luaInterface.triggerEvent("number", data);
}

void MainWindow::triggerTextEntered(QString text)
{
    auto state = luaInterface.luaState();
    kaguya::LuaTable data(state);
    data["text"] = text;
    data["widget"] = &cadMdiChild;
    luaInterface.triggerEvent("text", data);
}

void MainWindow::triggerFinishOperation()
{
    auto state = luaInterface.luaState();
    luaInterface.triggerEvent("operationFinished", kaguya::LuaRef(state));
    luaInterface.triggerEvent("finishOperation", kaguya::LuaRef(state));
}

void MainWindow::triggerCommandEntered(QString command)
{
    cliCommand.runCommand(command);
}

void MainWindow::triggerPoint(lc::geo::Coordinate coordinate)
{
    lastPoint = coordinate;
    cadMdiChild.viewer()->docCanvas()->selectPoint(coordinate.x(), coordinate.y());
}
