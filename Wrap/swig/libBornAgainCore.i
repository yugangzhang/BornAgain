// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Wrap/swig/libBornAgainCore.i
//! @brief     SWIG interface file for libBornAgainCore
//!
//!            Configuration is done in Core/CMakeLists.txt
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

%module(directors="1", moduleimport="import $module") "libBornAgainCore"

%include "commons.i"

%include "../../auto/Wrap/doxygenCore.i"

%include "ignoreBase.i"
%include "ignoreSample.i"

%rename(setSampleBuilderCpp) Simulation::setSampleBuilder;
%rename(setSampleBuilderCpp) SpecularSimulation::setSampleBuilder;
%rename(addSimulationAndData_cpp) FitObjective::addSimulationAndData;
%rename(evaluate_residuals_cpp) FitObjective::evaluate_residuals;
%rename(evaluate_cpp) FitObjective::evaluate;
%rename(finalize_cpp) FitObjective::finalize;
%rename(initPlot_cpp) FitObjective::initPlot;
%rename(uncertainties_cpp) FitObjective::uncertainties;
%rename(uncertaintyData_cpp) FitObjective::uncertaintyData;
%rename(containsUncertainties_cpp) FitObjective::containsUncertainties;
%rename(allPairsHaveUncertainties_cpp) FitObjective::allPairsHaveUncertainties;
%rename(MaterialProfile_cpp) MaterialProfile;

// force swig to use move ctor instead of copy ctor
%typemap(out) SlicedParticle %{
    $result = SWIG_NewPointerObj(new $1_ltype(std::move($1)), $&1_descriptor, SWIG_POINTER_OWN);
  %}

%shared_ptr(ISampleBuilder)

%feature("director") PyBuilderCallback;  // used in extendCore.i
%feature("director") PyObserverCallback; // used in extendCore.i

%feature("director") ISampleBuilder;     // used in mesocrystal1.py
%feature("director") ISample;            // needed by IFormFactor
%feature("director") IFormFactor;        // needed by IFormFactorBorn
%feature("director") IFormFactorBorn;    // used in CustomFormFactor.py
%feature("director") FitObjective;       // used in custom_objective_function.py

// Propagate python exceptions (from https://stackoverflow.com/questions/4811492)
%feature("director:except") {
    if( $error != NULL ) {
        PyObject *ptype, *pvalue, *ptraceback;
        PyErr_Fetch( &ptype, &pvalue, &ptraceback );
        PyErr_Restore( ptype, pvalue, ptraceback );
        PyErr_Print();
        Py_Exit(1);
    }
}

 // deprecations:
%rename(getArrayObsolete) IHistogram::getArray;
%extend IHistogram {
    %pythoncode %{
         @deprecated("Deprecated. Use array() instead.")
         def getArray(self):
             return self.getArrayObsolete()
    %}
 };

%{
#include "BAVersion.h"
#include "Sample/Correlations/FTDecay1D.h"
#include "Sample/Correlations/FTDecay2D.h"
#include "Sample/Correlations/FTDistributions1D.h"
#include "Sample/Correlations/FTDistributions2D.h"
#include "Sample/Correlations/ILayout.h"
#include "Sample/Correlations/IPeakShape.h"
#include "Sample/Aggregate/IInterferenceFunction.h"
#include "Sample/Aggregate/InterferenceFunction1DLattice.h"
#include "Sample/Aggregate/InterferenceFunction2DLattice.h"
#include "Sample/Aggregate/InterferenceFunction2DParaCrystal.h"
#include "Sample/Aggregate/InterferenceFunction2DSuperLattice.h"
#include "Sample/Aggregate/InterferenceFunction3DLattice.h"
#include "Sample/Aggregate/InterferenceFunctionFinite2DLattice.h"
#include "Sample/Aggregate/InterferenceFunctionFinite3DLattice.h"
#include "Sample/Aggregate/InterferenceFunctionHardDisk.h"
#include "Sample/Aggregate/InterferenceFunctionNone.h"
#include "Sample/Aggregate/InterferenceFunctionRadialParaCrystal.h"
#include "Sample/Aggregate/InterferenceFunctionTwin.h"
#include "Sample/Aggregate/ParticleLayout.h"
#include "Device/Beam/Beam.h"
#include "Device/Beam/FootprintGauss.h"
#include "Device/Beam/FootprintSquare.h"
#include "Core/Computation/ConstantBackground.h"
#include "Core/Computation/IBackground.h"
#include "Core/Computation/MultiLayerFuncs.h"
#include "Core/Computation/PoissonNoiseBackground.h"
#include "Device/Detector/DetectorMask.h"
#include "Device/Detector/IDetector2D.h"
#include "Device/Resolution/IDetectorResolution.h"
#include "Device/Resolution/IResolutionFunction2D.h"
#include "Device/Detector/IsGISAXSDetector.h"
#include "Device/Detector/RectangularDetector.h"
#include "Device/Resolution/ResolutionFunction2DGaussian.h"
#include "Device/Resolution/ScanResolution.h"
#include "Device/Detector/SphericalDetector.h"
#include "Core/Fitting/FitObjective.h"
#include "Core/Fitting/IObserver.h"
#include "Core/Fitting/IterationInfo.h"
#include "Core/Fitting/PyFittingCallbacks.h"
#include "Sample/HardParticle/FormFactorAnisoPyramid.h"
#include "Sample/HardParticle/FormFactorBar.h"
#include "Sample/HardParticle/FormFactorBox.h"
#include "Sample/HardParticle/FormFactorCantellatedCube.h"
#include "Sample/HardParticle/FormFactorCone.h"
#include "Sample/HardParticle/FormFactorCone6.h"
#include "Sample/HardParticle/FormFactorCosineRipple.h"
#include "Sample/HardParticle/FormFactorCuboctahedron.h"
#include "Sample/HardParticle/FormFactorCylinder.h"
#include "Sample/HardParticle/FormFactorDodecahedron.h"
#include "Sample/HardParticle/FormFactorDot.h"
#include "Sample/HardParticle/FormFactorEllipsoidalCylinder.h"
#include "Sample/HardParticle/FormFactorFullSphere.h"
#include "Sample/HardParticle/FormFactorFullSpheroid.h"
#include "Sample/HardParticle/FormFactorHemiEllipsoid.h"
#include "Sample/HardParticle/FormFactorHollowSphere.h"
#include "Sample/HardParticle/FormFactorIcosahedron.h"
#include "Sample/HardParticle/FormFactorLongBoxGauss.h"
#include "Sample/HardParticle/FormFactorLongBoxLorentz.h"
#include "Sample/HardParticle/IFormFactorPolyhedron.h"
#include "Sample/HardParticle/IFormFactorPrism.h"
#include "Sample/HardParticle/FormFactorPrism3.h"
#include "Sample/HardParticle/FormFactorPrism6.h"
#include "Sample/HardParticle/FormFactorPyramid.h"
#include "Sample/HardParticle/FormFactorSawtoothRipple.h"
#include "Sample/HardParticle/FormFactorTetrahedron.h"
#include "Sample/HardParticle/FormFactorTruncatedCube.h"
#include "Sample/HardParticle/FormFactorTruncatedSphere.h"
#include "Sample/HardParticle/FormFactorTruncatedSpheroid.h"
#include "Device/Histo/IntensityDataIOFactory.h"
#include "Device/Scan/AngularSpecScan.h"
#include "Device/Instrument/ChiSquaredModule.h"
#include "Device/Instrument/IChiSquaredModule.h"
#include "Device/Instrument/Instrument.h"
#include "Device/Instrument/PyArrayImportUtils.h"
#include "Device/Scan/QSpecScan.h"
#include "Device/Histo/SimulationResult.h"
#include "Device/Instrument/SpectrumUtils.h"
#include "Device/Instrument/VarianceFunctions.h"
#include "Device/Histo/Histogram1D.h"
#include "Device/Histo/Histogram2D.h"
#include "Device/Histo/IHistogram.h"
#include "Device/Intensity/IIntensityFunction.h"
#include "Device/Intensity/IIntensityFunction.h"
#include "Device/Instrument/IntensityDataFunctions.h"
#include "Device/Data/OutputData.h"
#include "Sample/Lattice/ILatticeOrientation.h"
#include "Sample/Lattice/ISelectionRule.h"
#include "Sample/Lattice/Lattice.h"
#include "Sample/Lattice/Lattice2D.h"
#include "Sample/Lattice/LatticeUtils.h"
#include "Device/Mask/Ellipse.h"
#include "Device/Mask/IShape2D.h"
#include "Device/Mask/Line.h"
#include "Device/Mask/Polygon.h"
#include "Device/Mask/Rectangle.h"
#include "Sample/Material/MaterialFactoryFuncs.h"
#include "Sample/Material/WavevectorInfo.h"
#include "Core/SampleBuilderEngine/ISampleBuilder.h"
#include "Sample/Multilayer/Layer.h"
#include "Sample/Multilayer/LayerInterface.h"
#include "Sample/Multilayer/LayerRoughness.h"
#include "Sample/Multilayer/MultiLayer.h"
#include "Sample/RT/SimulationOptions.h"
#include "Sample/Particle/Crystal.h"
#include "Sample/Particle/FormFactorCrystal.h"
#include "Sample/Particle/FormFactorWeighted.h"
#include "Sample/Particle/IAbstractParticle.h"
#include "Sample/Particle/IClusteredParticles.h"
#include "Sample/Particle/IParticle.h"
#include "Sample/Particle/MesoCrystal.h"
#include "Sample/Particle/Particle.h"
#include "Sample/Particle/ParticleComposition.h"
#include "Sample/Particle/ParticleCoreShell.h"
#include "Sample/Particle/ParticleDistribution.h"
#include "Sample/Particle/SlicedParticle.h"
#include "Sample/Scattering/IFormFactorDecorator.h"
#include "Sample/Scattering/ISample.h"
#include "Sample/Scattering/Rotations.h"
#include "Core/Simulation/DepthProbeSimulation.h"
#include "Core/Simulation/GISASSimulation.h"
#include "Core/Simulation/OffSpecSimulation.h"
#include "Core/Simulation/Simulation.h"
#include "Core/Simulation/Simulation2D.h"
#include "Core/Simulation/SpecularSimulation.h"
#include "Sample/SoftParticle/FormFactorGauss.h"
#include "Sample/SoftParticle/FormFactorSphereGaussianRadius.h"
#include "Sample/SoftParticle/FormFactorSphereLogNormalRadius.h"
#include "Core/StandardSamples/SampleBuilderFactory.h"
#include "Core/Simulation/SimulationFactory.h"
#include "Fit/Kernel/FitOptions.h"
%}

// ownership

%newobject ScanResolution::scanRelativeResolution;
%newobject ScanResolution::scanAbsoluteResolution;

%newobject SimulationResult::histogram2d(Axes::Units units_type = Axes::Units::DEFAULT) const;

%newobject IntensityDataIOFactory::readOutputData(const std::string& file_name);
%newobject IntensityDataIOFactory::readIntensityData(const std::string& file_name);

%newobject DetectorMask::createHistogram() const;

%newobject PyArrayImport::importArrayToOutputData;
%newobject IHistogram::createFrom(const std::string& filename);
%newobject IHistogram::createFrom(const std::vector<std::vector<double>>& data);

%newobject InterferenceFunction2DLattice::createSquare(double lattice_length, double xi);
%newobject InterferenceFunction2DLattice::createHexagonal(double lattice_length, double xi);
%newobject InterferenceFunction2DParaCrystal::createSquare(
        double lattice_length, double damping_length, double domain_size_1, double domain_size_2);
%newobject InterferenceFunction2DParaCrystal::createHexagonal(
        double lattice_length, double damping_length, double domain_size_1, double domain_size_2);
%newobject InterferenceFunction2DSuperLattice::createSquare(
        double lattice_length, double xi, unsigned size_1, unsigned size_2);
%newobject InterferenceFunction2DSuperLattice::createHexagonal(
        double lattice_length, double xi, unsigned size_1, unsigned size_2);
%newobject InterferenceFunctionFinite2DLattice::createSquare(
        double lattice_length, double xi, unsigned size_1, unsigned size_2);
%newobject InterferenceFunctionFinite2DLattice::createHexagonal(
        double lattice_length, double xi, unsigned size_1, unsigned size_2);

// The following goes verbatim from libBornAgainCore.i to libBornAgainCore_wrap.cxx.
// Note that the order matters, as base classes must be included before derived classes.

%import(module="libBornAgainFit") "Fit/Tools/AttLimits.h"
%import(module="libBornAgainFit") "Fit/Tools/Attributes.h"
%import(module="libBornAgainFit") "Fit/Tools/RealLimits.h"
%import(module="libBornAgainFit") "Fit/Kernel/Parameters.h"
%import(module="libBornAgainFit") "Fit/Kernel/Parameter.h"

%import(module="libBornAgainBase") "Base/Types/Complex.h"
%import(module="libBornAgainBase") "Base/Types/ICloneable.h"
%import(module="libBornAgainBase") "Base/Vector/BasicVector3D.h"
%import(module="libBornAgainBase") "Base/Vector/Vectors3D.h"
%import(module="libBornAgainBase") "Base/Axis/IAxis.h"
%include "fromBase.i"

%import(module="libBornAgainParam") "Param/Base/ParameterPool.h"
%import(module="libBornAgainParam") "Param/Base/IParameterized.h"
%import(module="libBornAgainParam") "Param/Node/INode.h"
%import(module="libBornAgainParam") "Param/Distrib/ParameterDistribution.h"
%include "fromParam.i"

%template(swig_dummy_type_axisinfo_vector) std::vector<AxisInfo>;

%template(swig_dummy_type_inode_vector) std::vector<INode*>;
%template(swig_dummy_type_const_inode_vector) std::vector<const INode*>;

%template(vector_IFormFactorPtr_t) std::vector<IFormFactor*>;

%include "Fit/TestEngine/IFactory.h"
%template(SampleBuilderFactoryTemp) IFactory<std::string, ISampleBuilder>;
%template(SimulationFactoryTemp) IFactory<std::string, Simulation>;

%include "Device/Data/OutputData.h"
%template(IntensityData) OutputData<double>;

%include "Core/Fitting/FitObjective.h"
%template(addSimulationAndData) FitObjective::addSimulationAndData<std::vector<double>>;
%template(addSimulationAndData) FitObjective::addSimulationAndData<std::vector<std::vector<double>>>;

%include "BAVersion.h"

%include "Device/Mask/IShape2D.h"
%include "Device/Mask/Ellipse.h"
%include "Device/Mask/Line.h"
%include "Device/Mask/Polygon.h"
%include "Device/Mask/Rectangle.h"

%include "Sample/RT/SimulationOptions.h"

%include "Sample/Scattering/ISample.h"
%include "Sample/Scattering/IFormFactor.h"
%include "Sample/Scattering/IFormFactorBorn.h"
%include "Sample/Scattering/IFormFactorDecorator.h"

%include "Sample/Scattering/Rotations.h"

%include "Fit/Kernel/FitOptions.h"

%include "Core/Fitting/IObserver.h"
%include "Core/Fitting/IterationInfo.h"
%include "Core/Fitting/PyFittingCallbacks.h"

%include "Sample/Particle/FormFactorCrystal.h"
%include "Sample/Particle/FormFactorWeighted.h"
%include "Sample/Particle/IAbstractParticle.h"
%include "Sample/Particle/IClusteredParticles.h"
%include "Sample/Particle/Crystal.h"
%include "Sample/Particle/IParticle.h"
%include "Sample/Particle/MesoCrystal.h"
%include "Sample/Particle/Particle.h"
%include "Sample/Particle/ParticleComposition.h"
%include "Sample/Particle/ParticleCoreShell.h"
%include "Sample/Particle/ParticleDistribution.h"

%include "Sample/Correlations/FTDecay1D.h"
%include "Sample/Correlations/FTDecay2D.h"
%include "Sample/Correlations/FTDistributions1D.h"
%include "Sample/Correlations/FTDistributions2D.h"
%include "Sample/Correlations/FTDecay1D.h"
%include "Sample/Correlations/FTDecay2D.h"
%include "Sample/Correlations/ILayout.h"
%include "Sample/Correlations/IPeakShape.h"

%include "Sample/Aggregate/IInterferenceFunction.h"
%include "Sample/Aggregate/InterferenceFunction1DLattice.h"
%include "Sample/Aggregate/InterferenceFunction2DLattice.h"
%include "Sample/Aggregate/InterferenceFunction2DParaCrystal.h"
%include "Sample/Aggregate/InterferenceFunction2DSuperLattice.h"
%include "Sample/Aggregate/InterferenceFunction3DLattice.h"
%include "Sample/Aggregate/InterferenceFunctionFinite2DLattice.h"
%include "Sample/Aggregate/InterferenceFunctionFinite3DLattice.h"
%include "Sample/Aggregate/InterferenceFunctionHardDisk.h"
%include "Sample/Aggregate/InterferenceFunctionNone.h"
%include "Sample/Aggregate/InterferenceFunctionRadialParaCrystal.h"
%include "Sample/Aggregate/InterferenceFunctionTwin.h"
%include "Sample/Aggregate/ParticleLayout.h"

%include "Device/Beam/Beam.h"
%include "Device/Beam/IFootprintFactor.h"
%include "Device/Beam/FootprintGauss.h"
%include "Device/Beam/FootprintSquare.h"

%include "Core/SampleBuilderEngine/ISampleBuilder.h"
%include "Sample/Multilayer/Layer.h"
%include "Sample/Multilayer/LayerRoughness.h"
%include "Sample/Multilayer/MultiLayer.h"

// SWIG workaround for using axes units the same way as they are used in cpp files
%rename(RoughnessModel) RoughnessModelWrap;
%include "Sample/Multilayer/RoughnessModels.h"

%include "Sample/HardParticle/IFormFactorPolyhedron.h"
%include "Sample/HardParticle/IFormFactorPrism.h"
%include "Sample/HardParticle/IProfileRipple.h"

%include "Sample/HardParticle/FormFactorAnisoPyramid.h"
%include "Sample/HardParticle/FormFactorBox.h"
%include "Sample/HardParticle/FormFactorCantellatedCube.h"
%include "Sample/HardParticle/FormFactorCone.h"
%include "Sample/HardParticle/FormFactorCone6.h"
%include "Sample/HardParticle/FormFactorCosineRipple.h"
%include "Sample/HardParticle/FormFactorCuboctahedron.h"
%include "Sample/HardParticle/FormFactorCylinder.h"
%include "Sample/HardParticle/FormFactorDodecahedron.h"
%include "Sample/HardParticle/FormFactorDot.h"
%include "Sample/HardParticle/FormFactorEllipsoidalCylinder.h"
%include "Sample/HardParticle/FormFactorFullSphere.h"
%include "Sample/HardParticle/FormFactorFullSpheroid.h"
%include "Sample/HardParticle/FormFactorHemiEllipsoid.h"
%include "Sample/HardParticle/FormFactorHollowSphere.h"
%include "Sample/HardParticle/FormFactorIcosahedron.h"
%include "Sample/HardParticle/FormFactorLongBoxGauss.h"
%include "Sample/HardParticle/FormFactorLongBoxLorentz.h"
%include "Sample/HardParticle/FormFactorPrism3.h"
%include "Sample/HardParticle/FormFactorPrism6.h"
%include "Sample/HardParticle/FormFactorPyramid.h"
%include "Sample/HardParticle/FormFactorSawtoothRipple.h"
%include "Sample/HardParticle/FormFactorTetrahedron.h"
%include "Sample/HardParticle/FormFactorTruncatedCube.h"
%include "Sample/HardParticle/FormFactorTruncatedSphere.h"
%include "Sample/HardParticle/FormFactorTruncatedSpheroid.h"

%include "Sample/SoftParticle/FormFactorGauss.h"
%include "Sample/SoftParticle/FormFactorSphereGaussianRadius.h"
%include "Sample/SoftParticle/FormFactorSphereLogNormalRadius.h"

%include "Core/Simulation/Simulation.h"
%include "Core/Simulation/Simulation2D.h"
%include "Core/Simulation/GISASSimulation.h"
%include "Core/Simulation/DepthProbeSimulation.h"
%include "Core/Simulation/SpecularSimulation.h"
%include "Core/Simulation/OffSpecSimulation.h"

%include "Core/Computation/IBackground.h"
%include "Core/Computation/ConstantBackground.h"
%include "Core/Computation/PoissonNoiseBackground.h"
%include "Core/Computation/MultiLayerFuncs.h"

%include "Device/Histo/IntensityDataIOFactory.h"

%include "Device/Detector/IDetector.h"
%include "Device/Detector/IDetector2D.h"
%include "Device/Detector/SphericalDetector.h"
%include "Device/Detector/DetectorMask.h"
%include "Device/Detector/IsGISAXSDetector.h"
%include "Device/Detector/RectangularDetector.h"

%include "Device/Resolution/IDetectorResolution.h"
%include "Device/Resolution/IResolutionFunction2D.h"
%include "Device/Resolution/ResolutionFunction2DGaussian.h"
%include "Device/Resolution/ScanResolution.h"

%include "Device/Histo/IHistogram.h"
%include "Device/Intensity/IIntensityFunction.h"
%include "Device/Unit/IUnitConverter.h"

%include "Device/Histo/Histogram1D.h"
%include "Device/Histo/Histogram2D.h"
%include "Device/Instrument/IntensityDataFunctions.h"

%include "Device/Instrument/IChiSquaredModule.h"
%include "Device/Scan/ISpecularScan.h"

%include "Device/Scan/AngularSpecScan.h"
%include "Device/Instrument/ChiSquaredModule.h"
%include "Device/Instrument/Instrument.h"
%include "Device/Instrument/PyArrayImportUtils.h"
%include "Device/Scan/QSpecScan.h"
%include "Device/Histo/SimulationResult.h"
%include "Device/Instrument/SpectrumUtils.h"
%include "Device/Instrument/VarianceFunctions.h"

%include "Sample/Lattice/ILatticeOrientation.h"
%include "Sample/Lattice/ISelectionRule.h"
%include "Sample/Lattice/Lattice.h"
%include "Sample/Lattice/Lattice2D.h"
%include "Sample/Lattice/LatticeUtils.h"

%include "Sample/Material/Material.h"
%include "Sample/Material/MaterialFactoryFuncs.h"
%include "Sample/Material/WavevectorInfo.h"

%include "Core/StandardSamples/SampleBuilderFactory.h"
%include "Core/Simulation/SimulationFactory.h"

%extend BasicVector3D<double> {
    BasicVector3D<double> __add__(const BasicVector3D<double>& rhs) const {
        return *($self) + rhs; }
    BasicVector3D<double> __mul__(double c) const {
        return c * *($self); }
    BasicVector3D<double> __rmul__(double c) const {
        return *($self) * c; }
    BasicVector3D<double> __neg__() const {
        return - *($self); }
};

%extend OutputData<double> {
    double __getitem__(unsigned int i) { return (*($self))[i]; }
    double __setitem__(unsigned int i, double value)
    {
        (*($self))[i] = value;
        return (*($self))[i];
    }
};

%extend SimulationResult {
    double __getitem__(unsigned int i) { return (*($self))[i]; }
    double __setitem__(unsigned int i, double value)
    {
        (*($self))[i] = value;
        return (*($self))[i];
    }
};

%extend ISampleBuilder {
    virtual RealParameter* registerParameter(const std::string& name, int64_t parpointer) {
        return &(($self)->IParameterized::registerParameter(name, (double*)parpointer)); }

    virtual void setParameterValue(const std::string& name, double value) {
        ($self)->IParameterized::setParameterValue(name, value); }

    virtual std::string parametersToString() const {
        return ($self)->IParameterized::parametersToString();
        }

    virtual ParameterPool* createParameterTree() const {
        return ($self)->IParameterized::createParameterTree();
        }

    virtual ParameterPool* parameterPool() const {
        return ($self)->IParameterized::parameterPool();
    }

    virtual void onChange() {
        return ($self)->IParameterized::onChange();
    }

};

// needed to prevent ownership problems with passed ISampleBuilder
%extend Simulation {
    %pythoncode %{
         def setSampleBuilder(self, ptr):
             self.samplebuilder = ptr
             self.setSampleBuilderCpp(ptr)
    %}
 };

%extend SpecularSimulation {
    %pythoncode %{
         def setSampleBuilder(self, ptr):
             self.samplebuilder = ptr
             self.setSampleBuilderCpp(ptr)
    %}
 };

// fancy names for ScanResolution static functions
%pythoncode %{
    def ScanRelativeResolution(distribution, rel_dev):
        """
        Creates a scan resolution from the given distribution and
        relative deviation values (that is, the ratios of standard
        deviations and means).
        :param distribution: bornagain.RangedDistribution object
        :param rel_dev: either single-valued or a numpy array.
                        In the latter case should coinside in
                        size with later used mean values array.
        :return: bornagain.ScanResolution object
        """
        return ScanResolution_scanRelativeResolution(distribution, rel_dev)

    def ScanAbsoluteResolution(distribution, std_dev):
        """
        Creates a scan resolution from the given distribution and
        standard deviation values.
        :param distribution: bornagain.RangedDistribution object
        :param std_dev: either single-valued or a numpy array.
                        In the latter case should coinside in
                        size with later used mean values array.
        :return: bornagain.ScanResolution object
        """
        return ScanResolution_scanAbsoluteResolution(distribution, std_dev)
%}

%pythoncode %{
class SimulationBuilderWrapper(PyBuilderCallback):
    def __init__(self, f):
        super(SimulationBuilderWrapper, self).__init__()
        self.f_ = f

    def create_par_dict(self, pars):
        """
        Convertion of ba.Parameters to Python dictionary
        """
        pars_dict = dict()
        for index, p in enumerate(pars):
            pars_dict[p.name()] = p.value
        return pars_dict

    def build_simulation(self, obj):
        simulation = self.f_(self.create_par_dict(obj))
        simulation.__disown__()
        return simulation


%}

%pythoncode %{
class ObserverCallbackWrapper(PyObserverCallback):
    def __init__(self, callback):
        super(ObserverCallbackWrapper, self).__init__()
        self.callback_ = callback

    def update(self, fit_objective):
        return self.callback_(fit_objective)

%}

%extend FitObjective {
%pythoncode %{
    def addSimulationAndData(self, callback, data, *args, **kwargs):
        """
        Sets simulation and experimental data to the fit objective.
        Optionally accepts experimental data uncertainties and
        user-defined dataset weight.

        Arguments:

        callback -- user-defined function returning fully-defined bornagain.Simulation object.
        The function must use fit parameter dictionary as its input.

        data -- numpy array with experimental data.

        uncertainties -- numpy array with experimental data uncertainties.
        Array shape must correspond to the shape of data. Optional argument.

        weight -- user-defined weight of the dataset. If not specified, defaults to 1.0.
        """
        if not hasattr(self, 'callback_container'):
            self.callback_container = []
        wrp = SimulationBuilderWrapper(callback)
        self.callback_container.append(wrp)
        return self.addSimulationAndData_cpp(wrp, data, *args, **kwargs)

    def convert_params(self, params):
        """
        Converts parameters to what FitObjective::evaluate expects
        """

        if str(params.__module__) == "lmfit.parameter":
            bapars = libBornAgainFit.Parameters()
            for p in params:
                bapars.add(p, params[p].value)
            return bapars
        else:
            return params

    def evaluate_residuals(self, params):
        return self.evaluate_residuals_cpp(self.convert_params(params))

    def evaluate(self, params):
        return self.evaluate_cpp(self.convert_params(params))

    def convert_result(self, minim_result):
        """
        Converts result reported by arbitrary minimizer to ba.MinimizerResult
        """

        if str(minim_result.__module__) == "lmfit.minimizer":
            return libBornAgainFit.MinimizerResult()
        else:
            return minim_result

    def finalize(self, minimizer_result):
        return self.finalize_cpp(self.convert_result(minimizer_result))

    def create_default_plotter(self):
        import plot_utils
        self.m_plotter = plot_utils.PlotterGISAS()
        return self.m_plotter.plot

    def initPlot(self, every_nth, callback = None):
        if not callback:
            callback = self.create_default_plotter()

        self.wrp_plot_observer = ObserverCallbackWrapper(callback)
        return self.initPlot_cpp(every_nth, self.wrp_plot_observer)

    def uncertainties(self):
        """
        Returns one-dimensional array representing merged data uncertainties.
        If any of the associated data pairs lack uncertainties, returns None.
        """
        if self.allPairsHaveUncertainties_cpp():
            return self.uncertainties_cpp()
        return None

    def uncertaintyData(self, i=0):
        """
        Returns uncertainties for i-th simulation-data pair. If
        no uncertainties are assigned to the data pair, returns
        None.
        """
        if self.containsUncertainties_cpp(i):
            return self.uncertaintyData_cpp(i)
        return None
%}
};

// --- Computation/MaterialProfile

// Function with optional default limits and/or number of points
%pythoncode %{
    def MaterialProfile(multilayer, n_points=400, z_min=None, z_max=None):
        """
        Creates a material profile from the given multilayer. If no limits are given,
        it will provide sensible default values, considering the included particles and
        interface roughnesses.
        :param multilayer: bornagain.MultiLayer object
        :param n_points: number of points to generate
        :param z_min: starting value for z
        :param z_max: ending value for z
        :return: numpy arrays containing z positions and the complex material values in those positions
        """
        def_z_min, def_z_max = DefaultMaterialProfileLimits(multilayer)
        z_min = def_z_min if z_min is None else z_min
        z_max = def_z_max if z_max is None else z_max
        z_points = GenerateZValues(n_points, z_min, z_max)
        material_values = MaterialProfile_cpp(multilayer, n_points, z_min, z_max)
        return (z_points, material_values)
%}
