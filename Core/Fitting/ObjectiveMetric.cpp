//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Fitting/ObjectiveMetric.cpp
//! @brief     Implements ObjectiveMetric classes.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "Core/Fitting/ObjectiveMetric.h"
#include "Core/Fitting/ObjectiveMetricUtils.h"
#include "Core/Fitting/SimDataPair.h"
#include "Device/Data/OutputData.h"
#include <cmath>
#include <limits>

namespace {
const double double_max = std::numeric_limits<double>::max();
const double double_min = std::numeric_limits<double>::min();
const double ln10 = std::log(10.0);

template <class T> T* copyMetric(const T& metric) {
    auto* result = new T;
    result->setNorm(metric.norm());
    return result;
}

void checkIntegrity(const std::vector<double>& sim_data, const std::vector<double>& exp_data,
                    const std::vector<double>& weight_factors) {
    const size_t sim_size = sim_data.size();
    if (sim_size != exp_data.size() || sim_size != weight_factors.size())
        throw std::runtime_error("Error in ObjectiveMetric: input arrays have different sizes");

    for (size_t i = 0; i < sim_size; ++i)
        if (sim_data[i] < 0.0)
            throw std::runtime_error(
                "Error in ObjectiveMetric: simulation data array contains negative values");
}

void checkIntegrity(const std::vector<double>& sim_data, const std::vector<double>& exp_data,
                    const std::vector<double>& uncertainties,
                    const std::vector<double>& weight_factors) {
    if (sim_data.size() != uncertainties.size())
        throw std::runtime_error("Error in ObjectiveMetric: input arrays have different sizes");

    checkIntegrity(sim_data, exp_data, weight_factors);
}
} // namespace

ObjectiveMetric::ObjectiveMetric(std::function<double(double)> norm) : m_norm(std::move(norm)) {}

double ObjectiveMetric::compute(const SimDataPair& data_pair, bool use_weights) const {
    if (use_weights && !data_pair.containsUncertainties())
        throw std::runtime_error("Error in ObjectiveMetric::compute: the metric is weighted, but "
                                 "the simulation-data pair does not contain uncertainties");

    if (use_weights)
        return computeFromArrays(data_pair.simulation_array(), data_pair.experimental_array(),
                                 data_pair.uncertainties_array(), data_pair.user_weights_array());
    else
        return computeFromArrays(data_pair.simulation_array(), data_pair.experimental_array(),
                                 data_pair.user_weights_array());
}

void ObjectiveMetric::setNorm(std::function<double(double)> norm) {
    m_norm = std::move(norm);
}

// ----------------------- Chi2 metric ---------------------------

Chi2Metric::Chi2Metric() : ObjectiveMetric(ObjectiveMetricUtils::l2Norm()) {}

Chi2Metric* Chi2Metric::clone() const {
    return copyMetric(*this);
}

double Chi2Metric::computeFromArrays(std::vector<double> sim_data, std::vector<double> exp_data,
                                     std::vector<double> uncertainties,
                                     std::vector<double> weight_factors) const {
    checkIntegrity(sim_data, exp_data, uncertainties, weight_factors);

    double result = 0.0;
    auto norm_fun = norm();
    for (size_t i = 0, sim_size = sim_data.size(); i < sim_size; ++i)
        if (exp_data[i] >= 0.0 && weight_factors[i] > 0.0 && uncertainties[i] > 0.0)
            result += norm_fun((exp_data[i] - sim_data[i]) / uncertainties[i]) * weight_factors[i];

    return std::isfinite(result) ? result : double_max;
}

double Chi2Metric::computeFromArrays(std::vector<double> sim_data, std::vector<double> exp_data,
                                     std::vector<double> weight_factors) const {
    checkIntegrity(sim_data, exp_data, weight_factors);

    auto norm_fun = norm();
    double result = 0.0;
    for (size_t i = 0, sim_size = sim_data.size(); i < sim_size; ++i)
        if (exp_data[i] >= 0.0 && weight_factors[i] > 0.0)
            result += norm_fun(exp_data[i] - sim_data[i]) * weight_factors[i];

    return std::isfinite(result) ? result : double_max;
}

// ----------------------- Poisson-like metric ---------------------------

PoissonLikeMetric::PoissonLikeMetric() : Chi2Metric() {}

PoissonLikeMetric* PoissonLikeMetric::clone() const {
    return copyMetric(*this);
}

double PoissonLikeMetric::computeFromArrays(std::vector<double> sim_data,
                                            std::vector<double> exp_data,
                                            std::vector<double> weight_factors) const {
    checkIntegrity(sim_data, exp_data, weight_factors);

    double result = 0.0;
    auto norm_fun = norm();
    for (size_t i = 0, sim_size = sim_data.size(); i < sim_size; ++i) {
        if (weight_factors[i] <= 0.0 || exp_data[i] < 0.0)
            continue;
        const double variance = std::max(1.0, sim_data[i]);
        const double value = (sim_data[i] - exp_data[i]) / std::sqrt(variance);
        result += norm_fun(value) * weight_factors[i];
    }

    return std::isfinite(result) ? result : double_max;
}

// ----------------------- Log metric ---------------------------

LogMetric::LogMetric() : ObjectiveMetric(ObjectiveMetricUtils::l2Norm()) {}

LogMetric* LogMetric::clone() const {
    return copyMetric(*this);
}

double LogMetric::computeFromArrays(std::vector<double> sim_data, std::vector<double> exp_data,
                                    std::vector<double> uncertainties,
                                    std::vector<double> weight_factors) const {
    checkIntegrity(sim_data, exp_data, uncertainties, weight_factors);

    double result = 0.0;
    auto norm_fun = norm();
    for (size_t i = 0, sim_size = sim_data.size(); i < sim_size; ++i) {
        if (weight_factors[i] <= 0.0 || exp_data[i] < 0.0 || uncertainties[i] <= 0.0)
            continue;
        const double sim_val = std::max(double_min, sim_data[i]);
        const double exp_val = std::max(double_min, exp_data[i]);
        double value = std::log10(sim_val) - std::log10(exp_val);
        value *= exp_val * ln10 / uncertainties[i];
        result += norm_fun(value) * weight_factors[i];
    }

    return std::isfinite(result) ? result : double_max;
}

double LogMetric::computeFromArrays(std::vector<double> sim_data, std::vector<double> exp_data,
                                    std::vector<double> weight_factors) const {
    checkIntegrity(sim_data, exp_data, weight_factors);

    double result = 0.0;
    auto norm_fun = norm();
    for (size_t i = 0, sim_size = sim_data.size(); i < sim_size; ++i) {
        if (weight_factors[i] <= 0.0 || exp_data[i] < 0.0)
            continue;
        const double sim_val = std::max(double_min, sim_data[i]);
        const double exp_val = std::max(double_min, exp_data[i]);
        result += norm_fun(std::log10(sim_val) - std::log10(exp_val)) * weight_factors[i];
    }

    return std::isfinite(result) ? result : double_max;
}

// ----------------------- Relative difference ---------------------------

RelativeDifferenceMetric::RelativeDifferenceMetric() : Chi2Metric() {}

RelativeDifferenceMetric* RelativeDifferenceMetric::clone() const {
    return copyMetric(*this);
}

double RelativeDifferenceMetric::computeFromArrays(std::vector<double> sim_data,
                                                   std::vector<double> exp_data,
                                                   std::vector<double> weight_factors) const {
    checkIntegrity(sim_data, exp_data, weight_factors);

    double result = 0.0;
    auto norm_fun = norm();
    for (size_t i = 0, sim_size = sim_data.size(); i < sim_size; ++i) {
        if (weight_factors[i] <= 0.0 || exp_data[i] < 0.0)
            continue;
        const double sim_val = std::max(double_min, sim_data[i]);
        const double exp_val = std::max(double_min, exp_data[i]);
        result += norm_fun((exp_val - sim_val) / (exp_val + sim_val)) * weight_factors[i];
    }

    return std::isfinite(result) ? result : double_max;
}

// ----------------------- RQ4 metric ---------------------------

RQ4Metric::RQ4Metric() : Chi2Metric() {}

RQ4Metric* RQ4Metric::clone() const {
    return copyMetric(*this);
}

double RQ4Metric::compute(const SimDataPair& data_pair, bool use_weights) const {
    if (use_weights)
        return Chi2Metric::compute(data_pair, use_weights);

    // fetching data in RQ4 form
    auto sim_data = data_pair.simulationResult().data(Axes::Units::RQ4);
    auto exp_data = data_pair.experimentalData().data(Axes::Units::RQ4);

    return computeFromArrays(sim_data->getRawDataVector(), exp_data->getRawDataVector(),
                             data_pair.user_weights_array());
}
