// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonFitList.h"
#include "FitParameter.pypp.h"

namespace bp = boost::python;

struct FitParameter_wrapper : FitParameter, bp::wrapper< FitParameter > {

    FitParameter_wrapper(FitParameter const & arg )
    : FitParameter( arg )
      , bp::wrapper< FitParameter >(){
        // copy constructor
        
    }

    FitParameter_wrapper( )
    : FitParameter( )
      , bp::wrapper< FitParameter >(){
        // null constructor
    
    }

    FitParameter_wrapper(::std::string const & name, double value, double step=0.0, ::AttLimits const & limits=AttLimits::limitless( ), double error=0.0 )
    : FitParameter( name, value, step, boost::ref(limits), error )
      , bp::wrapper< FitParameter >(){
        // constructor
    
    }

    virtual double getError(  ) const  {
        if( bp::override func_getError = this->get_override( "getError" ) )
            return func_getError(  );
        else{
            return this->FitParameter::getError(  );
        }
    }
    
    double default_getError(  ) const  {
        return FitParameter::getError( );
    }

    virtual double getStep(  ) const  {
        if( bp::override func_getStep = this->get_override( "getStep" ) )
            return func_getStep(  );
        else{
            return this->FitParameter::getStep(  );
        }
    }
    
    double default_getStep(  ) const  {
        return FitParameter::getStep( );
    }

    virtual double getValue(  ) const  {
        if( bp::override func_getValue = this->get_override( "getValue" ) )
            return func_getValue(  );
        else{
            return this->FitParameter::getValue(  );
        }
    }
    
    double default_getValue(  ) const  {
        return FitParameter::getValue( );
    }

    virtual void setError( double value ) {
        if( bp::override func_setError = this->get_override( "setError" ) )
            func_setError( value );
        else{
            this->FitParameter::setError( value );
        }
    }
    
    void default_setError( double value ) {
        FitParameter::setError( value );
    }

    virtual void setStep( double value ) {
        if( bp::override func_setStep = this->get_override( "setStep" ) )
            func_setStep( value );
        else{
            this->FitParameter::setStep( value );
        }
    }
    
    void default_setStep( double value ) {
        FitParameter::setStep( value );
    }

    virtual void setValue( double value ) {
        if( bp::override func_setValue = this->get_override( "setValue" ) )
            func_setValue( value );
        else{
            this->FitParameter::setValue( value );
        }
    }
    
    void default_setValue( double value ) {
        FitParameter::setValue( value );
    }

};

void register_FitParameter_class(){

    { //::FitParameter
        typedef bp::class_< FitParameter_wrapper, bp::bases< INamed > > FitParameter_exposer_t;
        FitParameter_exposer_t FitParameter_exposer = FitParameter_exposer_t( "FitParameter", "Parameter with value, error and limits for fitting routines.", bp::init< >() );
        bp::scope FitParameter_scope( FitParameter_exposer );
        FitParameter_exposer.def( bp::init< std::string const &, double, bp::optional< double, AttLimits const &, double > >(( bp::arg("name"), bp::arg("value"), bp::arg("step")=0.0, bp::arg("limits")=AttLimits::limitless( ), bp::arg("error")=0.0 )) );
        { //::FitParameter::getError
        
            typedef double ( ::FitParameter::*getError_function_type)(  ) const;
            typedef double ( FitParameter_wrapper::*default_getError_function_type)(  ) const;
            
            FitParameter_exposer.def( 
                "getError"
                , getError_function_type(&::FitParameter::getError)
                , default_getError_function_type(&FitParameter_wrapper::default_getError) );
        
        }
        { //::FitParameter::getStep
        
            typedef double ( ::FitParameter::*getStep_function_type)(  ) const;
            typedef double ( FitParameter_wrapper::*default_getStep_function_type)(  ) const;
            
            FitParameter_exposer.def( 
                "getStep"
                , getStep_function_type(&::FitParameter::getStep)
                , default_getStep_function_type(&FitParameter_wrapper::default_getStep) );
        
        }
        { //::FitParameter::getValue
        
            typedef double ( ::FitParameter::*getValue_function_type)(  ) const;
            typedef double ( FitParameter_wrapper::*default_getValue_function_type)(  ) const;
            
            FitParameter_exposer.def( 
                "getValue"
                , getValue_function_type(&::FitParameter::getValue)
                , default_getValue_function_type(&FitParameter_wrapper::default_getValue) );
        
        }
        { //::FitParameter::setError
        
            typedef void ( ::FitParameter::*setError_function_type)( double ) ;
            typedef void ( FitParameter_wrapper::*default_setError_function_type)( double ) ;
            
            FitParameter_exposer.def( 
                "setError"
                , setError_function_type(&::FitParameter::setError)
                , default_setError_function_type(&FitParameter_wrapper::default_setError)
                , ( bp::arg("value") ) );
        
        }
        { //::FitParameter::setStep
        
            typedef void ( ::FitParameter::*setStep_function_type)( double ) ;
            typedef void ( FitParameter_wrapper::*default_setStep_function_type)( double ) ;
            
            FitParameter_exposer.def( 
                "setStep"
                , setStep_function_type(&::FitParameter::setStep)
                , default_setStep_function_type(&FitParameter_wrapper::default_setStep)
                , ( bp::arg("value") ) );
        
        }
        { //::FitParameter::setValue
        
            typedef void ( ::FitParameter::*setValue_function_type)( double ) ;
            typedef void ( FitParameter_wrapper::*default_setValue_function_type)( double ) ;
            
            FitParameter_exposer.def( 
                "setValue"
                , setValue_function_type(&::FitParameter::setValue)
                , default_setValue_function_type(&FitParameter_wrapper::default_setValue)
                , ( bp::arg("value") ) );
        
        }
    }

}
