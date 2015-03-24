#pragma once

#include "cad/const.h"
#include <memory>
#include <iostream>
#include "cad/base/cadentity.h"
namespace lc {
    namespace geo {
        class Vector;
        class Arc;
    }

    /**
    * Base class for visitor pattern using double dispatch
    * TODO: See if we can split this into a GeoVisotor and EntityVisitor. It might be very lickly we only need double
    * displatch for geometric entities because it's very unlicklt that we want to calculate intersections
    * between for example dimensions. However, it 'could' be we want to have this. For
    * example when we connect different entities together at a high level. But this will be more
    * on a component level, eg, can component A be connected on component B. I am not sure yet....
    */
    class EntityVisitor {
    public:
        virtual void visit(const geo::Vector&, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(Point_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Point_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(Line_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Line_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(Circle_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr , Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Circle_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(Arc_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Arc_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(Ellipse_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Ellipse_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(Text_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Text_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(Spline_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(Spline_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(MText_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(MText_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(DimAligned_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAligned_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(DimAngular_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimAngular_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(DimDiametric_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimDiametric_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(DimLinear_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimLinear_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(DimRadial_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(DimRadial_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

        virtual void visit(LWPolyline_CSPtr, const geo::Vector&) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, Point_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, Line_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, Circle_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, Arc_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, Ellipse_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, Spline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, LWPolyline_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, Text_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, MText_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, DimAligned_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, DimAngular_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, DimDiametric_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, DimLinear_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};
        virtual void visit(LWPolyline_CSPtr, DimRadial_CSPtr) {std::cerr << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;};

    };
}

#define ENTITYINTERACTION(Entity) virtual void accept(Entity o, EntityVisitor& ei) const { ei.visit(o, o);}

// ENTITYINTERACTION_H
