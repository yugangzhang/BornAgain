"""
This example demonstrates new experimental feature of release-1.8.0:
particles can now cross interfaces.

Given example is similar to simulation/ex01_BasicParticles/CylindersAndPrisms.py,
with the difference, that z-position of particles is adjusted to move them slightly
down from vacuum layer and to make them cross substrate/air interface.

Note:
1) Simulation kernel automatically detects particles crossing interface and
adjusts calculations accordingly.

2) Particle crossing interface requires more time to simulate.

3) Crossing of interface is possible only for limited number of geometries.
For example, X or Y rotated particles can not yet cross interfaces (exception
will be thrown when trying to simulate such geometries).
"""
import bornagain as ba
from bornagain import angstrom, deg, nm, nm2, kvector_t

phi_min, phi_max = -1.0, 1.0
alpha_min, alpha_max = 0.0, 2.0


def get_sample():
    """
    Returns a sample with uncorrelated cylinders and prisms on a substrate.
    """

    # Define materials
    material_Particle = ba.HomogeneousMaterial("Particle", 0.0006, 2e-08)
    material_Substrate = ba.HomogeneousMaterial("Substrate", 6e-06, 2e-08)
    material_Vacuum = ba.HomogeneousMaterial("Vacuum", 0.0, 0.0)

    # Define form factors
    ff_1 = ba.FormFactorCylinder(5.0*nm, 5.0*nm)
    ff_2 = ba.FormFactorPrism3(10.0*nm, 5.0*nm)

    # Define particles
    particle_1 = ba.Particle(material_Particle, ff_1)
    particle_1_position = kvector_t(0.0*nm, 0.0*nm, -3.0*nm)
    particle_1.setPosition(particle_1_position)
    particle_2 = ba.Particle(material_Particle, ff_2)
    particle_2_position = kvector_t(0.0*nm, 0.0*nm, -3.0*nm)
    particle_2.setPosition(particle_2_position)

    # Define interference functions
    iff = ba.InterferenceFunctionNone()

    # Define particle layouts
    layout = ba.ParticleLayout()
    layout.addParticle(particle_1, 0.5)
    layout.addParticle(particle_2, 0.5)
    layout.setInterferenceFunction(iff)
    layout.setWeight(1)
    layout.setTotalParticleSurfaceDensity(0.01)

    # Define layers
    layer_1 = ba.Layer(material_Vacuum)
    layer_1.addLayout(layout)
    layer_2 = ba.Layer(material_Substrate)

    # Define sample
    sample = ba.MultiLayer()
    sample.addLayer(layer_1)
    sample.addLayer(layer_2)

    return sample


def get_simulation():
    """
    Returns a GISAXS simulation with beam and detector defined.
    """
    simulation = ba.GISASSimulation()
    simulation.setDetectorParameters(100, phi_min*deg, phi_max*deg, 100,
                                     alpha_min*deg, alpha_max*deg)
    simulation.setBeamParameters(1.0*angstrom, 0.2*deg, 0.0*deg)
    return simulation


def run_simulation():
    """
    Runs simulation and returns resulting intensity map.
    """
    sample = get_sample()
    simulation = get_simulation()
    simulation.setSample(sample)
    simulation.runSimulation()
    return simulation.result()


if __name__ == '__main__':
    result = run_simulation()
    ba.plot_simulation_result(result, cmap='jet', aspect='auto')
