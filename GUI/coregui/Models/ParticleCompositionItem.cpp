// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/ParticleCompositionItem.cpp
//! @brief     Implements class ParticleCompositionItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ParticleCompositionItem.h"
#include "ParticleItem.h"

ParticleCompositionItem::ParticleCompositionItem(ParameterizedItem *parent)
    : ParameterizedGraphicsItem(Constants::ParticleCompositionType, parent)
{
    setItemName(Constants::ParticleCompositionType);

    registerProperty(ParticleItem::P_ABUNDANCE, 1.0,
                     PropertyAttribute(AttLimits::limited(0.0, 1.0), 3));
    registerGroupProperty(ParticleItem::P_POSITION, Constants::VectorType);

    addToValidChildren(Constants::ParticleType, PortInfo::PORT_0);
    addToValidChildren(Constants::ParticleCoreShellType, PortInfo::PORT_0);
    addToValidChildren(Constants::ParticleCompositionType, PortInfo::PORT_0);
}

void ParticleCompositionItem::insertChildItem(int row, ParameterizedItem *item)
{
    ParameterizedItem::insertChildItem(row, item);
    if (item->modelType() == Constants::ParticleType
        || item->modelType() == Constants::ParticleCoreShellType
        || item->modelType() == Constants::ParticleCompositionType) {
        item->setRegisteredProperty(ParticleItem::P_ABUNDANCE, 1.0);
        item->setPropertyAppearance(ParticleItem::P_ABUNDANCE, PropertyAttribute::DISABLED);
        int port = item->getRegisteredProperty(ParameterizedItem::P_PORT).toInt();
        if (port == PortInfo::DEFAULT) {
            item->setItemPort(PortInfo::PORT_0);
        }
    }
}

void ParticleCompositionItem::onPropertyChange(const QString &name)
{
    ParameterizedItem::onPropertyChange(name);
    if (name == P_PORT && parent()) {
        if (parent()->modelType() == Constants::ParticleCompositionType
            || parent()->modelType() == Constants::ParticleDistributionType) {
            setRegisteredProperty(ParticleItem::P_ABUNDANCE, 1.0);
            setPropertyAppearance(ParticleItem::P_ABUNDANCE, PropertyAttribute::DISABLED);
        }
    }
}
