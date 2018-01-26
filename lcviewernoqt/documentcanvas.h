#pragma once

#include <functional>

#include "painters/lcpainter.h"

#include "cad/dochelpers/entitycontainer.h"
#include "drawitems/lcvdrawitem.h"
#include "events/drawevent.h"
#include <cad/base/cadentity.h>

#include <cad/events/addentityevent.h>
#include <cad/events/commitprocessevent.h>
#include <cad/events/removeentityevent.h>
#include <nano-signal-slot/nano_signal_slot.hpp>

#include <cad/document/document.h>

// Minimum linewidth we render, below this the lines might start to look 'jagged'
// We migth want to consider at lower linewidth to simply reduce alpha to get a similar effect of smaller line?
static const double MINIMUM_READER_LINEWIDTH = 1.0;

namespace LCViewer {
    enum PainterType {
        VIEWER_BACKGROUND,
        VIEWER_DOCUMENT,
        VIEWER_FOREGROUND
    };


    class DocumentCanvas : public std::enable_shared_from_this<DocumentCanvas> {
        public:
            DocumentCanvas(std::shared_ptr<lc::Document> document, std::function<void(double*, double*)> deviceToUser);
            virtual ~DocumentCanvas();

        /**
         * @brief render
         * @param painter Target
         * @param type Painter type
         */
        void render(LcPainter& painter, PainterType type);

        /**
         * @brief drawEntity
         * Draw entity without adding it to the current document
         * @param entity LCVDrawItem_CSPtr
         * @param insert Insert entity if we are rendering a bloc
         */
        void drawEntity(LcPainter& painter, LCVDrawItem_CSPtr entity, lc::entity::Insert_CSPtr insert = nullptr);

        /**
         * @brief autoScale
         * Found the bounds of the current document and scale into this and center on screen
         */
        void autoScale(LcPainter& painter);

        /**
         * @brief Set display area
         * @param area Area to display
         */
        void setDisplayArea(LcPainter& painter, const lc::geo::Area& area);

        void pan(LcPainter& painter, double move_x, double move_y);

        /**
         * @brief zoom
         * into a specific area
         * @param factor
         * @param deviceCenterX
         * @param deviceCenterY
         */
        void zoom(LcPainter& painter, double factor, bool relativezoom, unsigned int deviceCenterX, unsigned int deviceCenterY);

        /**
         * @brief zoom
         * into a specific area with a zoom factor
         * Ensures that the specified user location is located at the device location
         * on a specific zoom factor
         * @param factor
         * @param userCenterX
         * @param userCenterY
         * @param deviceCenterX
         * @param deviceCenterY
         */
        void zoom(LcPainter& painter, double factor, bool relativezoom, double userCenterX, double userCenterY, unsigned int deviceCenterX, unsigned int deviceCenterY);

        /**
         * @brief newSize
         * for the device. When using a pixel based device this is the number of pixels of the painter
         * @param width
         * @param height
         */
        void newDeviceSize(unsigned int width, unsigned int height);



        /**
         * @brief bounds
         * return the approximate size of the current document
         * @return
         */
        lc::geo::Area bounds() const;

        /**
         * @brief makeSelection
         * within the document. It will color the area red/green depending on the occupies flag.
         * The coordinates must be given in user coordinates
         * @param x
         * @param y
         * @param w
         * @param y
         * @param occupies
         * @param addTo -- when set to true, we add it to the current selection
         */
        void makeSelection(double x, double y, double w, double h, bool occupies, bool addTo = false);

        /**
         * @brief makeSelectionDevice
         * based on device coordinate rather then user coordinates
         * @param x
         * @param y
         * @param w
         * @param h
         * @param occupies
         * @param addTo -- when set to true, we add it to the current selection
         */
        void makeSelectionDevice(LcPainter& painter, unsigned int x, unsigned int y, unsigned int w, unsigned int h, bool occupies, bool addTo = false);

        /**
        * @brief closeSelection
        * appends current selection to document
        */
        void closeSelection();

        /**
        * @brief removeSelectionArea removed the colored selection area from the screen
        */
        void removeSelectionArea();

        void removeSelection();

        lc::EntityContainer<lc::entity::CADEntity_SPtr> selection();

        /**
         *
         */
        void setPositionDevice(int x, int y);



        Nano::Signal<void(DrawEvent const & drawEvent)> & background () ;
        Nano::Signal<void(DrawEvent const & drawEvent)> & foreground () ;

        /**
         * Return the underlaying document
         */
        std::shared_ptr<lc::Document> document() const;

        /**
         * Get the current entity container,
         * do not store this as a reference, always call it
         */
        const lc::EntityContainer<lc::entity::CADEntity_SPtr>& entityContainer() const;

        /**
         * Return CADEntity as LCVDrawItem
         */
        static LCVDrawItem_SPtr asDrawable(lc::entity::CADEntity_CSPtr entity);

        /**
         * @brief Convert device coordinate to user coordinate
         * @param x
         * @param y
         */
        inline void device_to_user(double* x, double* y) const;

    private:
        void on_addEntityEvent(const lc::AddEntityEvent&);
        void on_removeEntityEvent(const lc::RemoveEntityEvent&);
        void on_commitProcessEvent(const lc::CommitProcessEvent&);

        double drawWidth(lc::entity::CADEntity_CSPtr entity, lc::entity::Insert_CSPtr insert);
        std::vector<double> drawLinePattern(
                lc::entity::CADEntity_CSPtr entity,
                lc::entity::Insert_CSPtr insert,
                double width
        );
        lc::Color drawColor(lc::entity::CADEntity_CSPtr entity, lc::entity::Insert_CSPtr insert, bool selected);

        // Original document
        std::shared_ptr<lc::Document> _document;

        // Local entity container
        lc::EntityContainer<lc::entity::CADEntity_SPtr> _entityContainer;

        Nano::Signal<void(DrawEvent const & event)> _background;
        Nano::Signal<void(DrawEvent const & event)> _foreground;

        // Maximum and minimum allowed scale factors
        double _zoomMin;
        double _zoomMax;

        // Current's device width and height
        unsigned int _deviceWidth;
        unsigned int _deviceHeight;

        // When !=null it show's a selected area
        lc::geo::Area* _selectedArea;

        // When set to true, an entity will be selected if it intersects or occupies,
        // when false it will only select when the entity is fully contained
        bool _selectedAreaIntersects;

        // Functor to draw a selected area, that's the green or read area...
        std::function<void(LcPainter&, lc::geo::Area, bool)> _selectedAreaPainter;

        lc::EntityContainer<lc::entity::CADEntity_SPtr> _selectedEntities;
        lc::EntityContainer<lc::entity::CADEntity_SPtr> _newSelection;

        std::function<void(double*, double*)> _deviceToUser;
    };

    void DocumentCanvas::device_to_user(double* x, double* y) const {
            _deviceToUser(x, y);
    }

DECLARE_SHORT_SHARED_PTR(DocumentCanvas)
}
