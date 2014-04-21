// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "SimpleSelectionRule.pypp.h"

namespace bp = boost::python;

struct SimpleSelectionRule_wrapper : SimpleSelectionRule, bp::wrapper< SimpleSelectionRule > {

    SimpleSelectionRule_wrapper(SimpleSelectionRule const & arg )
    : SimpleSelectionRule( arg )
      , bp::wrapper< SimpleSelectionRule >(){
        // copy constructor
        
    }

    SimpleSelectionRule_wrapper(int a, int b, int c, int modulus )
    : SimpleSelectionRule( a, b, c, modulus )
      , bp::wrapper< SimpleSelectionRule >(){
        // constructor
    
    }

    virtual ::SimpleSelectionRule * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else
            return this->SimpleSelectionRule::clone(  );
    }
    
    
    ::SimpleSelectionRule * default_clone(  ) const  {
        return SimpleSelectionRule::clone( );
    }

    virtual bool coordinateSelected( ::IndexVector3D const & coordinate ) const  {
        if( bp::override func_coordinateSelected = this->get_override( "coordinateSelected" ) )
            return func_coordinateSelected( boost::ref(coordinate) );
        else
            return this->SimpleSelectionRule::coordinateSelected( boost::ref(coordinate) );
    }
    
    
    bool default_coordinateSelected( ::IndexVector3D const & coordinate ) const  {
        return SimpleSelectionRule::coordinateSelected( boost::ref(coordinate) );
    }

};

void register_SimpleSelectionRule_class(){

    { //::SimpleSelectionRule
        typedef bp::class_< SimpleSelectionRule_wrapper, bp::bases< ISelectionRule > > SimpleSelectionRule_exposer_t;
        SimpleSelectionRule_exposer_t SimpleSelectionRule_exposer = SimpleSelectionRule_exposer_t( "SimpleSelectionRule", bp::init< int, int, int, int >(( bp::arg("a"), bp::arg("b"), bp::arg("c"), bp::arg("modulus") )) );
        bp::scope SimpleSelectionRule_scope( SimpleSelectionRule_exposer );
        { //::SimpleSelectionRule::clone
        
            typedef ::SimpleSelectionRule * ( ::SimpleSelectionRule::*clone_function_type )(  ) const;
            typedef ::SimpleSelectionRule * ( SimpleSelectionRule_wrapper::*default_clone_function_type )(  ) const;
            
            SimpleSelectionRule_exposer.def( 
                "clone"
                , clone_function_type(&::SimpleSelectionRule::clone)
                , default_clone_function_type(&SimpleSelectionRule_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::SimpleSelectionRule::coordinateSelected
        
            typedef bool ( ::SimpleSelectionRule::*coordinateSelected_function_type )( ::IndexVector3D const & ) const;
            typedef bool ( SimpleSelectionRule_wrapper::*default_coordinateSelected_function_type )( ::IndexVector3D const & ) const;
            
            SimpleSelectionRule_exposer.def( 
                "coordinateSelected"
                , coordinateSelected_function_type(&::SimpleSelectionRule::coordinateSelected)
                , default_coordinateSelected_function_type(&SimpleSelectionRule_wrapper::default_coordinateSelected)
                , ( bp::arg("coordinate") ) );
        
        }
    }

}
