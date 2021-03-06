"""
Spherical particles embedded in the middle of the layer on top of substrate.
"""
import bornagain as ba
from bornagain import angstrom, deg, nm, nm2, kvector_t


def get_sample():
    """
    Returns a sample with spherical particles in a layer
    between vacuum and substrate.
    """

    # Define materials
    material_IntermLayer = ba.HomogeneousMaterial("IntermLayer", 3.45e-06,
                                                  5.24e-09)
    material_Particle = ba.HomogeneousMaterial("Particle", 0.0, 0.0)
    material_Substrate = ba.HomogeneousMaterial("Substrate", 7.43e-06, 1.72e-07)
    material_Vacuum = ba.HomogeneousMaterial("Vacuum", 0.0, 0.0)

    # Define form factors
    ff = ba.FormFactorFullSphere(10.2*nm)

    # Define particles
    particle = ba.Particle(material_Particle, ff)
    particle_position = kvector_t(0.0*nm, 0.0*nm, -25.2*nm)
    particle.setPosition(particle_position)

    # Define particle layouts
    layout = ba.ParticleLayout()
    layout.addParticle(particle, 1.0)
    layout.setWeight(1)
    layout.setTotalParticleSurfaceDensity(0.01)

    # Define layers
    layer_1 = ba.Layer(material_Vacuum)
    layer_2 = ba.Layer(material_IntermLayer, 30.0*nm)
    layer_2.addLayout(layout)
    layer_3 = ba.Layer(material_Substrate)

    # Define sample
    sample = ba.MultiLayer()
    sample.addLayer(layer_1)
    sample.addLayer(layer_2)
    sample.addLayer(layer_3)

    return sample


def get_simulation():
    """
    Returns a GISAXS simulation.
    """
    simulation = ba.GISASSimulation()
    simulation.setSample(get_sample())
    simulation.setDetectorParameters(200, -1*deg, +1*deg, 200, 0*deg, +2*deg)
    simulation.setBeamParameters(1.5*angstrom, 0.15*deg, 0.0*deg)
    return simulation


def run_simulation():
    """
    Runs simulation and returns intensity map.
    """
    simulation = get_simulation()
    simulation.setSample(get_sample())
    simulation.runSimulation()
    return simulation.result()


if __name__ == '__main__':
    result = run_simulation()
    ba.plot_simulation_result(result, cmap='jet', aspect='auto')
