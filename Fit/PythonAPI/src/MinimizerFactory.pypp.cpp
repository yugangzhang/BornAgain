// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "AttLimits.h"
#include "IChiSquaredModule.h"
#include "IMinimizer.h"
#include "ChiSquaredModule.h"
#include "FitSuite.h"
#include "MinimizerFactory.h"
#include "OutputData.h"
#include "PythonPlusplusFitHelper.h"
#include "MinimizerFactory.pypp.h"

namespace bp = boost::python;

void register_MinimizerFactory_class(){

    bp::class_< MinimizerFactory >( "MinimizerFactory" )    
        .def( 
            "createMinimizer"
            , (::IMinimizer * (*)( ::std::string const &,::std::string const &,::std::string const & ))( &::MinimizerFactory::createMinimizer )
            , ( bp::arg("minimizer"), bp::arg("algorithm")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >(), bp::arg("options")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() )
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "print_catalogue"
            , (void (*)(  ))( &::MinimizerFactory::print_catalogue ) )    
        .staticmethod( "createMinimizer" )    
        .staticmethod( "print_catalogue" );

}