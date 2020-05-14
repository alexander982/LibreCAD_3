#pragma once

#include "luainterface.h"
#include <kaguya/kaguya.hpp>

#include <QMainWindow>
#include "widgets/clicommand.h"
#include "Widgets/layers.h"
#include "widgets/linepatternselect.h"
#include "widgets/linewidthselect.h"
#include "widgets/colorselect.h"
#include "widgets/toolbar.h"
#include "cadmdichild.h"

namespace Ui {
    class MainWindow;
}

namespace lc
{
    namespace ui
    {
        /*
            MainWindow GUI Initialization and Menu GUI API functions
        */
        class MainWindow : public QMainWindow
        {
            Q_OBJECT
        public:
            /**
            * \brief Constructor for MainWindow
            */
            explicit MainWindow();

            ~MainWindow();

            /**
            * \brief Trigger appropriate signals for input events
            */
            void ConnectInputEvents();

            /**
            * \brief Gettters for clicommand,cadmdichild and toolbar for use in lua
            */
            lc::ui::widgets::CliCommand* getCliCommand();
            lc::ui::CadMdiChild* getCadMdiChild();
            lc::ui::widgets::Toolbar* getToolbar();

            /**
            * \brief Connect existing menu item to lua callback function
            * \param itemName item name , callback - function callback
            */
            void connectMenuItem(const std::string& itemName, kaguya::LuaRef callback);

        public slots:
            // CadMdiChild slots
            void triggerMousePressed();
            void triggerMouseReleased();
            void triggerMouseMoved();
            void triggerKeyPressed(int key);

            // CliCommand slots
            void triggerCoordinateEntered(lc::geo::Coordinate coordinate);
            void triggerRelativeCoordinateEntered(lc::geo::Coordinate coordinate);
            void triggerNumberEntered(double number);
            void triggerTextEntered(QString text);
            void triggerFinishOperation();
            void triggerCommandEntered(QString command);

            // Slot to deal with things to do in C++ after a point is triggered
            void triggerPoint(lc::geo::Coordinate coordinate);

        signals:
            void point(lc::geo::Coordinate coordinate);

        private:
            Ui::MainWindow* ui;
            lc::ui::LuaInterface luaInterface;

            lc::ui::CadMdiChild cadMdiChild;
            lc::ui::widgets::Layers layers;
            lc::ui::widgets::CliCommand cliCommand;
            lc::ui::widgets::Toolbar toolbar;

            // Select tools
            lc::ui::widgets::LinePatternSelect linePatternSelect;
            lc::ui::widgets::LineWidthSelect lineWidthSelect;
            lc::ui::widgets::ColorSelect colorSelect;

            lc::geo::Coordinate lastPoint;
        };
    }
}
