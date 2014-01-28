// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/inc/FormFactorRipple1.h
//! @brief     Defines class FormFactorRipple1.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORRIPPLE1_H
#define FORMFACTORRIPPLE1_H

#include "IFormFactorBorn.h"
#include "IStochasticParameter.h"
#include "MemberComplexFunctionIntegrator.h"

//! @class FormFactorRipple1
//! @ingroup formfactors
//! @brief The formfactor for a cosine ripple.

class BA_CORE_API_ FormFactorRipple1 : public IFormFactorBorn
{
public:
    FormFactorRipple1(double length, double width, double height);

    ~FormFactorRipple1() { delete m_integrator; }

    virtual FormFactorRipple1 *clone() const;

    virtual void accept(ISampleVisitor *visitor) const { visitor->visit(this); }

    virtual int getNumberOfStochasticParameters() const { return 3; }

    virtual double getHeight() const { return m_height; }
    virtual double getWidth() const { return m_width; }
    virtual double getLength() const { return m_length; }

    virtual complex_t evaluate_for_q(const cvector_t& q) const;

private:
    complex_t Integrand(double Z, void* params) const;

    virtual void init_parameters();

    double m_width;
    double m_height;
    double m_length;
    mutable cvector_t m_q;

    MemberComplexFunctionIntegrator<FormFactorRipple1> *m_integrator;
};

#endif // FORMFACTORRIPPLE1_H

