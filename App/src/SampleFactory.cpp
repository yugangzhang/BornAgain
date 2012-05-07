#include "SampleFactory.h"
#include "Exceptions.h"

#include <iostream>

SampleFactory *SampleFactory::m_instance = 0;
bool SampleFactory::m_destroyed = false;


SampleFactory::SampleFactory()
{

}


SampleFactory::~SampleFactory()
{
    std::cout << "SampleFactory::~SampleFactory() -> Info. Deleting SampleFactory" << std::endl;
    m_instance = 0;
    m_destroyed = true;
}


/* ************************************************************************* */
// access to material manager
/* ************************************************************************* */
SampleFactory &SampleFactory::instance()
{
    // check if exists, if not, then initialise
    if( !m_instance) {
        // check for dead reference (i.e. object has been initialised but then somebody managed to delete it)
        if( m_destroyed ) {
            onDeadReference();
        } else {
            // first call initalise
            create();
        }
    }
    std::cout << "SampleFactory::Instance() -> Info. Accesing instance... " << m_instance << std::endl;
    return *m_instance;
}


/* ************************************************************************* */
// create single instance of the manager
/* ************************************************************************* */
void SampleFactory::create() {
    std::cout << "MaterialManager::Create() -> Info. Creating material manager" << std::endl;
    static SampleFactory theInstance;
    m_instance = &theInstance;
}


/* ************************************************************************* */
// Action for abnormal situation when object has been occasionally deleted.
// The possibility to rise object again should be still implemented.
/* ************************************************************************* */
void SampleFactory::onDeadReference() {
    throw DeadReferenceException("Dead reference detected.");
}


/* ************************************************************************* */
// This function is used to automatically register new classes and their
// creaion methods
/* ************************************************************************* */
bool SampleFactory::RegisterSample(int sampleId, CreateSampleCallback CreateFn)
{
    return m_callbacks.insert( SampleCallbackMap_t::value_type(sampleId, CreateFn)).second;
}


/* ************************************************************************* */
// creation of standard sample of given sampleId type
/* ************************************************************************* */
ISample *SampleFactory::createStandard(int sampleId)
{
    SampleCallbackMap_t::const_iterator it = m_callbacks.find(sampleId);
    if( it == m_callbacks.end() ) {
        // sample of such kond have not been registered in the database
        throw UnknownClassException("Unknown sampleId");
    }
    // invoke the creation function
    return (it->second)();
}



