// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/FitWidgets/FitComparisonWidget.h
//! @brief     Declares class FitComparisonWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef FITCOMPARISONWIDGET_H
#define FITCOMPARISONWIDGET_H

#include "SessionItemWidget.h"

//! The FitComparisonWidget class plots realdata, simulated data and relative difference map
//! during the course of the fit.

class BA_CORE_API_ FitComparisonWidget : public SessionItemWidget
{
    Q_OBJECT

public:
    explicit FitComparisonWidget(QWidget *parent = 0);

    void setItem(class SessionItem *item);

protected:
    void setJobItem(class JobItem *jobItem);

private:
    class IntensityDataItem *createRelativeDifferenceItem();
    void calculateRelativeDifference();

    class ColorMapPlot *m_realDataPlot;
    class ColorMapPlot *m_simulatedDataPlot;
    class ColorMapPlot *m_relativeDiffPlot;

    class IntensityDataItem *m_realDataItem;
    class IntensityDataItem *m_simulatedDataItem;
    class IntensityDataItem *m_relativeDiffItem;

    class SessionModel *m_tempIntensityDataModel;
};

#endif
