// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "IFTDistribution2D.pypp.h"

namespace bp = boost::python;

struct IFTDistribution2D_wrapper : IFTDistribution2D, bp::wrapper< IFTDistribution2D > {

    IFTDistribution2D_wrapper(double coherence_length_x, double coherence_length_y )
    : IFTDistribution2D( coherence_length_x, coherence_length_y )
      , bp::wrapper< IFTDistribution2D >(){
        // constructor
    
    }

    virtual ::IFTDistribution2D * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual double evaluate( double qx, double qy ) const {
        bp::override func_evaluate = this->get_override( "evaluate" );
        return func_evaluate( qx, qy );
    }

    virtual double evaluateLattice( double qx, double qy ) const  {
        if( bp::override func_evaluateLattice = this->get_override( "evaluateLattice" ) )
            return func_evaluateLattice( qx, qy );
        else
            return this->IFTDistribution2D::evaluateLattice( qx, qy );
    }
    
    
    double default_evaluateLattice( double qx, double qy ) const  {
        return IFTDistribution2D::evaluateLattice( qx, qy );
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

    virtual void registerParameter( ::std::string const & name, double * parpointer ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer );
        }
        else{
            IParameterized::registerParameter( name, parpointer );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer ){
        if( dynamic_cast< IFTDistribution2D_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
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

void register_IFTDistribution2D_class(){

    { //::IFTDistribution2D
        typedef bp::class_< IFTDistribution2D_wrapper, bp::bases< IParameterized >, boost::noncopyable > IFTDistribution2D_exposer_t;
        IFTDistribution2D_exposer_t IFTDistribution2D_exposer = IFTDistribution2D_exposer_t( "IFTDistribution2D", bp::init< double, double >(( bp::arg("coherence_length_x"), bp::arg("coherence_length_y") )) );
        bp::scope IFTDistribution2D_scope( IFTDistribution2D_exposer );
        { //::IFTDistribution2D::clone
        
            typedef ::IFTDistribution2D * ( ::IFTDistribution2D::*clone_function_type )(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "clone"
                , bp::pure_virtual( clone_function_type(&::IFTDistribution2D::clone) )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IFTDistribution2D::evaluate
        
            typedef double ( ::IFTDistribution2D::*evaluate_function_type )( double,double ) const;
            
            IFTDistribution2D_exposer.def( 
                "evaluate"
                , bp::pure_virtual( evaluate_function_type(&::IFTDistribution2D::evaluate) )
                , ( bp::arg("qx"), bp::arg("qy") ) );
        
        }
        { //::IFTDistribution2D::evaluateLattice
        
            typedef double ( ::IFTDistribution2D::*evaluateLattice_function_type )( double,double ) const;
            typedef double ( IFTDistribution2D_wrapper::*default_evaluateLattice_function_type )( double,double ) const;
            
            IFTDistribution2D_exposer.def( 
                "evaluateLattice"
                , evaluateLattice_function_type(&::IFTDistribution2D::evaluateLattice)
                , default_evaluateLattice_function_type(&IFTDistribution2D_wrapper::default_evaluateLattice)
                , ( bp::arg("qx"), bp::arg("qy") ) );
        
        }
        { //::IFTDistribution2D::getCoherenceLengthX
        
            typedef double ( ::IFTDistribution2D::*getCoherenceLengthX_function_type )(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "getCoherenceLengthX"
                , getCoherenceLengthX_function_type( &::IFTDistribution2D::getCoherenceLengthX ) );
        
        }
        { //::IFTDistribution2D::getCoherenceLengthY
        
            typedef double ( ::IFTDistribution2D::*getCoherenceLengthY_function_type )(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "getCoherenceLengthY"
                , getCoherenceLengthY_function_type( &::IFTDistribution2D::getCoherenceLengthY ) );
        
        }
        { //::IFTDistribution2D::getDelta
        
            typedef double ( ::IFTDistribution2D::*getDelta_function_type )(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "getDelta"
                , getDelta_function_type( &::IFTDistribution2D::getDelta ) );
        
        }
        { //::IFTDistribution2D::getGamma
        
            typedef double ( ::IFTDistribution2D::*getGamma_function_type )(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "getGamma"
                , getGamma_function_type( &::IFTDistribution2D::getGamma ) );
        
        }
        { //::IFTDistribution2D::setGamma
        
            typedef void ( ::IFTDistribution2D::*setGamma_function_type )( double ) ;
            
            IFTDistribution2D_exposer.def( 
                "setGamma"
                , setGamma_function_type( &::IFTDistribution2D::setGamma )
                , ( bp::arg("gamma") ) );
        
        }
        { //::IFTDistribution2D::transformToStarBasis
        
            typedef void ( ::IFTDistribution2D::*transformToStarBasis_function_type )( double,double,double,double,double,double &,double & ) const;
            
            IFTDistribution2D_exposer.def( 
                "transformToStarBasis"
                , transformToStarBasis_function_type( &::IFTDistribution2D::transformToStarBasis )
                , ( bp::arg("qX"), bp::arg("qY"), bp::arg("alpha"), bp::arg("a"), bp::arg("b"), bp::arg("qa"), bp::arg("qb") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( IFTDistribution2D_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            IFTDistribution2D_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&IFTDistribution2D_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( IFTDistribution2D_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            IFTDistribution2D_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&IFTDistribution2D_wrapper::default_clearParameterPool) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( IFTDistribution2D_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&IFTDistribution2D_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( IFTDistribution2D_wrapper::*default_printParameters_function_type )(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&IFTDistribution2D_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            IFTDistribution2D_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &IFTDistribution2D_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( IFTDistribution2D_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            IFTDistribution2D_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&IFTDistribution2D_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( IFTDistribution2D_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            IFTDistribution2D_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&IFTDistribution2D_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
