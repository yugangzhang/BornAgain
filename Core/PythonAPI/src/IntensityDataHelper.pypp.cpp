// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence 
//! @brief automatically generated boost::python code for PythonCoreAPI  

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "PythonCoreList.h"
#include "IntensityDataHelper.pypp.h"

namespace bp = boost::python;

void register_IntensityDataHelper_class(){

    { //::IntensityDataHelper
        typedef bp::class_< IntensityDataHelper > IntensityDataHelper_exposer_t;
        IntensityDataHelper_exposer_t IntensityDataHelper_exposer = IntensityDataHelper_exposer_t( "IntensityDataHelper" );
        bp::scope IntensityDataHelper_scope( IntensityDataHelper_exposer );
        { //::IntensityDataHelper::setEllipticMask
        
            typedef void ( *setEllipticMask_function_type )( ::OutputData< double > &,double,double,double,double );
            
            IntensityDataHelper_exposer.def( 
                "setEllipticMask"
                , setEllipticMask_function_type( &::IntensityDataHelper::setEllipticMask )
                , ( bp::arg("data"), bp::arg("xc"), bp::arg("yc"), bp::arg("rx"), bp::arg("ry") ) );
        
        }
        { //::IntensityDataHelper::setRectangularMask
        
            typedef void ( *setRectangularMask_function_type )( ::OutputData< double > &,double,double,double,double );
            
            IntensityDataHelper_exposer.def( 
                "setRectangularMask"
                , setRectangularMask_function_type( &::IntensityDataHelper::setRectangularMask )
                , ( bp::arg("data"), bp::arg("x1"), bp::arg("y1"), bp::arg("x2"), bp::arg("y2") ) );
        
        }
        IntensityDataHelper_exposer.staticmethod( "setEllipticMask" );
        IntensityDataHelper_exposer.staticmethod( "setRectangularMask" );
    }

}
