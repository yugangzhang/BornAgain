"""
Cylinder form factor in Born approximation
"""
import bornagain as ba
from bornagain import angstrom, deg, nm, nm2, kvector_t


def get_sample():
    """
    Returns a sample with cylinders in a homogeneous environment ("Vacuum"),
    implying a simulation in plain Born approximation.
    """

    # Define materials
    material_Particle = ba.HomogeneousMaterial("Particle", 0.0006, 2e-08)
    material_Vacuum = ba.HomogeneousMaterial("Vacuum", 0.0, 0.0)

    # Define form factors
    ff = ba.FormFactorCylinder(5.0*nm, 5.0*nm)

    # Define particles
    particle = ba.Particle(material_Particle, ff)

    # Define particle layouts
    layout = ba.ParticleLayout()
    layout.addParticle(particle, 1.0)
    layout.setWeight(1)
    layout.setTotalParticleSurfaceDensity(0.01)

    # Define layers
    layer = ba.Layer(material_Vacuum)
    layer.addLayout(layout)

    # Define sample
    sample = ba.MultiLayer()
    sample.addLayer(layer)

    return sample


def get_simulation():
    """
    Returns a GISAXS simulation with beam and detector defined
    """
    simulation = ba.GISASSimulation()
    simulation.setDetectorParameters(200, -2.0*deg, 2.0*deg, 200, 0.0*deg,
                                     2.0*deg)
    simulation.setBeamParameters(1.0*angstrom, 0.2*deg, 0.0*deg)
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
