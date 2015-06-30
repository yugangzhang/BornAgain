// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      StandardSamples/ParaCrystalBuilder.cpp
//! @brief     Implements class ParaCrystalBuilder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ParaCrystalBuilder.h"
#include "MultiLayer.h"
#include "ParticleLayout.h"
#include "Materials.h"
#include "InterferenceFunctionRadialParaCrystal.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "FormFactorCylinder.h"
#include "Units.h"
#include "FTDistributions.h"

RadialParaCrystalBuilder::RadialParaCrystalBuilder()
    : m_corr_peak_distance(20.0*Units::nanometer)
    , m_corr_width(7*Units::nanometer)
    , m_corr_length(1e3*Units::nanometer)
    , m_cylinder_height(5*Units::nanometer)
    , m_cylinder_radius(5*Units::nanometer)
{
    init_parameters();
}

void RadialParaCrystalBuilder::init_parameters()
{
    clearParameterPool();
    registerParameter("corr_peak_distance", &m_corr_peak_distance);
    registerParameter("corr_width", &m_corr_width);
    registerParameter("corr_length", &m_corr_length);
    registerParameter("cylinder_height", &m_cylinder_height);
    registerParameter("cylinder_radius", &m_cylinder_radius);
}

ISample *RadialParaCrystalBuilder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial substrate_material("Substrate", 6e-6, 2e-8);
    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);

    InterferenceFunctionRadialParaCrystal *p_interference_function =
            new InterferenceFunctionRadialParaCrystal(
                    m_corr_peak_distance, m_corr_length);
    FTDistribution1DGauss pdf(m_corr_width);
    p_interference_function->setProbabilityDistribution(pdf);
    FormFactorCylinder ff_cylinder(m_cylinder_radius, m_cylinder_height);

    Particle particle(particle_material, ff_cylinder);
    ParticleLayout particle_layout(particle);
    particle_layout.addInterferenceFunction(p_interference_function);

    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}

// -----------------------------------------------------------------------------
// HexParaCrystalBuilder
// -----------------------------------------------------------------------------

HexParaCrystalBuilder::HexParaCrystalBuilder()
    : m_peak_distance(20.0*Units::nanometer)
    , m_corr_length(0.0)
    , m_domain_size_1(20.0*Units::micrometer)
    , m_domain_size_2(20.0*Units::micrometer)
    , m_cylinder_height(5*Units::nanometer)
    , m_cylinder_radius(5*Units::nanometer)
{
    init_parameters();
}

void HexParaCrystalBuilder::init_parameters()
{
    clearParameterPool();
    registerParameter("m_peak_distance", &m_peak_distance);
    registerParameter("m_corr_length", &m_corr_length);
    registerParameter("m_domain_size_1", &m_domain_size_1);
    registerParameter("m_domain_size_2", &m_domain_size_2);
    registerParameter("cylinder_height", &m_cylinder_height);
    registerParameter("cylinder_radius", &m_cylinder_radius);
}


ISample *HexParaCrystalBuilder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);
    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial substrate_material("Substrate", 6e-6, 2e-8);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);

    InterferenceFunction2DParaCrystal *p_interference_function =
            InterferenceFunction2DParaCrystal::createHexagonal(
                    m_peak_distance, m_corr_length,
                    m_domain_size_1, m_domain_size_2);
    FTDistribution2DCauchy pdf(1.0*Units::nanometer, 1.0*Units::nanometer);
    p_interference_function->setProbabilityDistributions(pdf, pdf);

    FormFactorCylinder ff_cylinder(m_cylinder_radius, m_cylinder_height);
    Particle cylinder(particle_material,ff_cylinder);

    ParticleLayout particle_layout(cylinder);
    particle_layout.addInterferenceFunction(p_interference_function);

    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}

// -----------------------------------------------------------------------------
// RectParaCrystalBuilder
// -----------------------------------------------------------------------------

RectParaCrystalBuilder::RectParaCrystalBuilder()
{
}

ISample *RectParaCrystalBuilder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial substrate_material("Substrate", 6e-6, 2e-8);
    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);

    InterferenceFunction2DParaCrystal *p_interference_function =
            InterferenceFunction2DParaCrystal::createSquare(10*Units::nanometer, 0*Units::nanometer);

    p_interference_function->setDomainSizes(20.0*Units::micrometer,
            20.0*Units::micrometer);
    FTDistribution2DCauchy pdf1(0.5*Units::nanometer, 2.0*Units::nanometer);
    FTDistribution2DCauchy pdf2(0.5*Units::nanometer, 2.0*Units::nanometer);
    p_interference_function->setProbabilityDistributions(pdf1, pdf2);

    FormFactorCylinder ff_cylinder(5.0*Units::nanometer, 5.0*Units::nanometer);

    Particle particle(particle_material, ff_cylinder);
    ParticleLayout particle_layout(particle);
    particle_layout.addInterferenceFunction(p_interference_function);

    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}



// -----------------------------------------------------------------------------
// RectParaCrystalBuilder
// -----------------------------------------------------------------------------

IsGISAXS08BBuilder::IsGISAXS08BBuilder()
{
}

// IsGISAXS8 functional test: 2D paracrystal lattice with isotropic pdfs
ISample *IsGISAXS08BBuilder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial substrate_material("Substrate", 6e-6, 2e-8);
    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);

    InterferenceFunction2DParaCrystal *p_interference_function =
            new InterferenceFunction2DParaCrystal(10.0*Units::nanometer,
                    10.0*Units::nanometer, Units::PI/2.0, 0.0, 0.0);
    p_interference_function->setDomainSizes(20.0*Units::micrometer,
            20.0*Units::micrometer);
    FTDistribution2DCauchy pdf1(0.5*Units::nanometer, 0.5*Units::nanometer);
    FTDistribution2DCauchy pdf2(0.5*Units::nanometer, 0.5*Units::nanometer);
    p_interference_function->setProbabilityDistributions(pdf1, pdf2);

    FormFactorCylinder ff_cylinder(5*Units::nanometer, 5*Units::nanometer);

    Particle particle(particle_material, ff_cylinder);
    ParticleLayout particle_layout(particle);
    particle_layout.addInterferenceFunction(p_interference_function);

    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}
