// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Fit/Minimizer/FunctionTestPlanCases.h
//! @brief     Defines collection of FunctionTestPlan classes
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "FunctionTestPlanCases.h"
#include "ObjectiveTestFunctions.h"
#include "Parameter.h"

using namespace Fit;

//! Plan to minimize a Rosenbrock function.
//! start point: F(-1.2,1.0) = 24.20
//! minimum    : F(1.0,1.0)  = 0.

RosenbrockPlan::RosenbrockPlan()
    : FunctionTestPlan("RosenbrockPlan", TestFunctions::RosenBrock, 0.0)
{
    addParameter(Parameter("par0", -1.2, AttLimits::limited(-5.0, 5.0), 0.01), 1.0);
    addParameter(Parameter("par1", 1.0, AttLimits::limited(-5.0, 5.0), 0.01), 1.0);
}

//! Plan for WoodFour function
//!   start point: F(-3,-1,-3,-1) = 19192
//!   minimum    : F(1,1,1,1)  =   0.

WoodFourPlan::WoodFourPlan() : FunctionTestPlan("WoodFourPlan", TestFunctions::WoodFour, 0.0)
{
    addParameter(Parameter("par0", -3.0, AttLimits::limited(-5.0, 5.0)), 1.0);
    addParameter(Parameter("par1", -1.0, AttLimits::limited(-5.0, 5.0)), 1.0);
    addParameter(Parameter("par2", -3.0, AttLimits::limited(-5.0, 5.0)), 1.0);
    addParameter(Parameter("par3", -1.0, AttLimits::limited(-5.0, 5.0)), 1.0);
}
