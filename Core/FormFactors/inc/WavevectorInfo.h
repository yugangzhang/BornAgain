// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/inc/WavevectorInfo.h
//! @brief     Defines WavevectorInfo.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef WAVEVECTORINFO_H
#define WAVEVECTORINFO_H

#include "Units.h"
#include "Bin.h"


//! @class WavevectorInfo
//! @ingroup formfactors_internal
//! @brief Holds all wavevector information relevant for calculating form factors.

class BA_CORE_API_ WavevectorInfo
{
public:
    WavevectorInfo() {}
    WavevectorInfo(cvector_t ki, cvector_t kf) : m_ki(ki), m_kf(kf) {}
    cvector_t getKi() const { return m_ki; }
    cvector_t getKf() const { return m_kf; }
    cvector_t getQ() const { return m_ki - m_kf; }
private:
    cvector_t m_ki;
    cvector_t m_kf;
};

#endif // WAVEVECTORINFO_H
