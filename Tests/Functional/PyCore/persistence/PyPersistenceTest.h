// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/PyCore/suite/PyPersistenceTest.h
//! @brief     Declares class PyPersistenceTest
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef PYSUITETEST_H
#define PYSUITETEST_H

#include "IFunctionalTest.h" // inheriting from
#include "OutputData.h"

//! @class PyPersistenceTest
//! @ingroup standard_samples
//! @brief A functional test of PyCore (the Python wrapper of BornAgain/Core).
//!   Performs a given standard simulation, both directly and from a Python dump.
//!   Invoked from PyPersistenceStandardTest.

class PyPersistenceTest : public IFunctionalTest
{
public:
    PyPersistenceTest(const std::string& name);
    ~PyPersistenceTest() final;

    void runTest() final;

    const OutputData<double>* getOutputData() const;

    double getDifference() const { return m_difference; }

    void printResults(std::ostream& ostr) const final;

private:
    std::string getPySuiteFileNameAndPath() const;

    class GISASSimulation* m_reference_simulation;
    class GISASSimulation* m_domain_simulation;
    double m_threshold;
    double m_difference;
    std::string m_pyscript_filename;
    std::string m_output_filename;
};

#endif // PYSUITETEST_H
