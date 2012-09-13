#ifndef GISASEXPERIMENT_H_
#define GISASEXPERIMENT_H_
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   GISASExperiment.h
//! @brief  Definition of GISASExperiment class
//! @author Scientific Computing Group at FRM II
//! @date   20.06.2012


#include "Experiment.h"
#include "ConvolutionDetectorResolution.h"

class GISASExperiment : public Experiment
{
public:
	GISASExperiment();

	virtual void runSimulation();

    virtual void normalize();

    void setDetectorParameters(size_t n_phi, double phi_f_min, double phi_f_max,
            size_t n_alpha, double alpha_f_min, double alpha_f_max, bool isgisaxs_style=false);

	void setDetectorResolutionFunction(ConvolutionDetectorResolution::cumulative_DF_2d resolution_function);

	void smearIntensityFromZAxisTilting();
private:
	void initializeAnglesIsgisaxs(NamedVector<double> *p_axis, double start, double end, size_t size);
	double getCurrentSolidAngle() const;
	double deltaAlpha(double alpha, double zeta) const;
	double deltaPhi(double alpha, double phi, double zeta);
	void createZetaAndProbVectors(std::vector<double> &zetas, std::vector<double> &probs, size_t nbr_zetas, double zeta_sigma);
	void addToIntensityMap(double alpha, double phi, double value);
	size_t findClosestIndex(const NamedVector<double> *p_axis, double value);
};

#endif /* GISASEXPERIMENT_H_ */
