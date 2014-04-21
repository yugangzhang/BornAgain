// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "vector_kvector_t.pypp.h"

namespace bp = boost::python;

void register_vector_kvector_t_class(){

    { //::std::vector< Geometry::BasicVector3D<double> >
        typedef bp::class_< std::vector< Geometry::BasicVector3D<double> > > vector_kvector_t_exposer_t;
        vector_kvector_t_exposer_t vector_kvector_t_exposer = vector_kvector_t_exposer_t( "vector_kvector_t" );
        bp::scope vector_kvector_t_scope( vector_kvector_t_exposer );
        //WARNING: the next line of code will not compile, because "::Geometry::BasicVector3D<double>" does not have operator== !
        vector_kvector_t_exposer.def( bp::vector_indexing_suite< ::std::vector< Geometry::BasicVector3D<double> > >() );
    }

}
