// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonFitAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonFitList.h"
#include "FitSuiteObjects.pypp.h"

namespace bp = boost::python;

struct FitSuiteObjects_wrapper : FitSuiteObjects, bp::wrapper< FitSuiteObjects > {

    FitSuiteObjects_wrapper( )
    : FitSuiteObjects( )
      , bp::wrapper< FitSuiteObjects >(){
        // null constructor
    
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else
            return this->IParameterized::areParametersChanged(  );
    }
    
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else
            this->IParameterized::clearParameterPool(  );
    }
    
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else
            return this->IParameterized::createParameterTree(  );
    }
    
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else
            this->IParameterized::printParameters(  );
    }
    
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else
            return this->IParameterized::setParameterValue( name, value );
    }
    
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else
            this->IParameterized::setParametersAreChanged(  );
    }
    
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

};

void register_FitSuiteObjects_class(){

    { //::FitSuiteObjects
        typedef bp::class_< FitSuiteObjects_wrapper, bp::bases< IParameterized >, boost::noncopyable > FitSuiteObjects_exposer_t;
        FitSuiteObjects_exposer_t FitSuiteObjects_exposer = FitSuiteObjects_exposer_t( "FitSuiteObjects", bp::init< >() );
        bp::scope FitSuiteObjects_scope( FitSuiteObjects_exposer );
        { //::FitSuiteObjects::add
        
            typedef void ( ::FitSuiteObjects::*add_function_type )( ::Simulation const &,::OutputData< double > const &,::IChiSquaredModule const &,double ) ;
            
            FitSuiteObjects_exposer.def( 
                "add"
                , add_function_type( &::FitSuiteObjects::add )
                , ( bp::arg("simulation"), bp::arg("real_data"), bp::arg("chi2_module"), bp::arg("weight")=1.0e+0 ) );
        
        }
        { //::FitSuiteObjects::calculateChiSquaredValue
        
            typedef double ( ::FitSuiteObjects::*calculateChiSquaredValue_function_type )(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "calculateChiSquaredValue"
                , calculateChiSquaredValue_function_type( &::FitSuiteObjects::calculateChiSquaredValue ) );
        
        }
        { //::FitSuiteObjects::clear
        
            typedef void ( ::FitSuiteObjects::*clear_function_type )(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "clear"
                , clear_function_type( &::FitSuiteObjects::clear ) );
        
        }
        { //::FitSuiteObjects::getChiSquaredValue
        
            typedef double ( ::FitSuiteObjects::*getChiSquaredValue_function_type )(  ) const;
            
            FitSuiteObjects_exposer.def( 
                "getChiSquaredValue"
                , getChiSquaredValue_function_type( &::FitSuiteObjects::getChiSquaredValue ) );
        
        }
        { //::FitSuiteObjects::getObject
        
            typedef ::FitObject const * ( ::FitSuiteObjects::*getObject_function_type )( ::std::size_t ) const;
            
            FitSuiteObjects_exposer.def( 
                "getObject"
                , getObject_function_type( &::FitSuiteObjects::getObject )
                , ( bp::arg("i_item")=(long unsigned int)(0) )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::FitSuiteObjects::getObject
        
            typedef ::FitObject * ( ::FitSuiteObjects::*getObject_function_type )( ::std::size_t ) ;
            
            FitSuiteObjects_exposer.def( 
                "getObject"
                , getObject_function_type( &::FitSuiteObjects::getObject )
                , ( bp::arg("i_item")=(long unsigned int)(0) )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::FitSuiteObjects::getRealData
        
            typedef ::OutputData< double > const * ( ::FitSuiteObjects::*getRealData_function_type )( ::std::size_t ) const;
            
            FitSuiteObjects_exposer.def( 
                "getRealData"
                , getRealData_function_type( &::FitSuiteObjects::getRealData )
                , ( bp::arg("i_item")=(long unsigned int)(0) )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::FitSuiteObjects::getResidualValue
        
            typedef double ( ::FitSuiteObjects::*getResidualValue_function_type )( ::std::size_t ) ;
            
            FitSuiteObjects_exposer.def( 
                "getResidualValue"
                , getResidualValue_function_type( &::FitSuiteObjects::getResidualValue )
                , ( bp::arg("global_index") ) );
        
        }
        { //::FitSuiteObjects::getSimulation
        
            typedef ::Simulation const * ( ::FitSuiteObjects::*getSimulation_function_type )( ::std::size_t ) const;
            
            FitSuiteObjects_exposer.def( 
                "getSimulation"
                , getSimulation_function_type( &::FitSuiteObjects::getSimulation )
                , ( bp::arg("i_item")=(long unsigned int)(0) )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::FitSuiteObjects::getSimulation
        
            typedef ::Simulation * ( ::FitSuiteObjects::*getSimulation_function_type )( ::std::size_t ) ;
            
            FitSuiteObjects_exposer.def( 
                "getSimulation"
                , getSimulation_function_type( &::FitSuiteObjects::getSimulation )
                , ( bp::arg("i_item")=(long unsigned int)(0) )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::FitSuiteObjects::getSimulationData
        
            typedef ::OutputData< double > const * ( ::FitSuiteObjects::*getSimulationData_function_type )( ::std::size_t ) const;
            
            FitSuiteObjects_exposer.def( 
                "getSimulationData"
                , getSimulationData_function_type( &::FitSuiteObjects::getSimulationData )
                , ( bp::arg("i_item")=(long unsigned int)(0) )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::FitSuiteObjects::getSizeOfDataSet
        
            typedef ::std::size_t ( ::FitSuiteObjects::*getSizeOfDataSet_function_type )(  ) const;
            
            FitSuiteObjects_exposer.def( 
                "getSizeOfDataSet"
                , getSizeOfDataSet_function_type( &::FitSuiteObjects::getSizeOfDataSet ) );
        
        }
        { //::FitSuiteObjects::runSimulations
        
            typedef void ( ::FitSuiteObjects::*runSimulations_function_type )(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "runSimulations"
                , runSimulations_function_type( &::FitSuiteObjects::runSimulations ) );
        
        }
        { //::FitSuiteObjects::setNfreeParameters
        
            typedef void ( ::FitSuiteObjects::*setNfreeParameters_function_type )( int ) ;
            
            FitSuiteObjects_exposer.def( 
                "setNfreeParameters"
                , setNfreeParameters_function_type( &::FitSuiteObjects::setNfreeParameters )
                , ( bp::arg("nfree_parameters") ) );
        
        }
        { //::FitSuiteObjects::setRealData
        
            typedef void ( ::FitSuiteObjects::*setRealData_function_type )( ::OutputData< double > const &,::std::size_t ) ;
            
            FitSuiteObjects_exposer.def( 
                "setRealData"
                , setRealData_function_type( &::FitSuiteObjects::setRealData )
                , ( bp::arg("real_data"), bp::arg("i_item")=(long unsigned int)(0) ) );
        
        }
        { //::FitSuiteObjects::setSimulationNormalize
        
            typedef void ( ::FitSuiteObjects::*setSimulationNormalize_function_type )( bool ) ;
            
            FitSuiteObjects_exposer.def( 
                "setSimulationNormalize"
                , setSimulationNormalize_function_type( &::FitSuiteObjects::setSimulationNormalize )
                , ( bp::arg("simulation_normalize") ) );
        
        }
        { //::FitSuiteObjects::size
        
            typedef ::std::size_t ( ::FitSuiteObjects::*size_function_type )(  ) const;
            
            FitSuiteObjects_exposer.def( 
                "size"
                , size_function_type( &::FitSuiteObjects::size ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( FitSuiteObjects_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&FitSuiteObjects_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( FitSuiteObjects_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&FitSuiteObjects_wrapper::default_clearParameterPool) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( FitSuiteObjects_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            FitSuiteObjects_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&FitSuiteObjects_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( FitSuiteObjects_wrapper::*default_printParameters_function_type )(  ) const;
            
            FitSuiteObjects_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&FitSuiteObjects_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( FitSuiteObjects_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            FitSuiteObjects_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&FitSuiteObjects_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( FitSuiteObjects_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&FitSuiteObjects_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
