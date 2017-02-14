// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Multilayer/FormFactorDWBA.h
//! @brief     Defines class FormFactorDWBA.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORDWBA_H
#define FORMFACTORDWBA_H

#include "IFormFactor.h"
#include <memory>

class ILayerRTCoefficients;

//! Evaluates the coherent sum of the four DWBA terms in a scalar IFormFactor.
//! @ingroup formfactors_internal

class FormFactorDWBA final : public IFormFactor
{
public:
    FormFactorDWBA(const IFormFactor& form_factor);
    ~FormFactorDWBA() override;

    FormFactorDWBA* clone() const override;

    void accept(INodeVisitor* visitor) const override { visitor->visit(this); }

    void setAmbientMaterial(const IMaterial& material) override {
        mP_form_factor->setAmbientMaterial(material);
    }

    //! Calculates and returns a form factor calculation in DWBA
    complex_t evaluate(const WavevectorInfo& wavevectors) const override;

    double getVolume() const override { return mP_form_factor->getVolume(); }

    double getRadialExtension() const override { return mP_form_factor->getRadialExtension(); }

    double bottomZ(const IRotation& rotation) const override;

    void setSpecularInfo (const ILayerRTCoefficients* p_in_coeffs,
                          const ILayerRTCoefficients* p_out_coeffs) override;

    friend class TestPolarizedDWBATerms;

private:
    //! The form factor for BA
    std::unique_ptr<IFormFactor> mP_form_factor;

    const ILayerRTCoefficients* mp_in_coeffs;  //!< not owned by this
    const ILayerRTCoefficients* mp_out_coeffs; //!< not owned by this
};

#endif // FORMFACTORDWBA_H
