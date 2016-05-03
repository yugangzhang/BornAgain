// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/JobWidgets/JobRealTimeWidget.cpp
//! @brief     Implements class JobRealTimeWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "JobRealTimeWidget.h"
#include "JobModel.h"
#include "JobItem.h"
#include "JobQueueData.h"
#include "ModelTuningWidget.h"
#include "JobRealTimeToolBar.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QAction>
#include <QLabel>
#include <QDebug>
#include "GUIHelpers.h"

JobRealTimeWidget::JobRealTimeWidget(JobModel *jobModel, QWidget *parent)
    : JobPresenter(jobModel, parent)
    , m_stack(new QStackedWidget(this))
    , m_toolBar(new JobRealTimeToolBar)
{
    setWindowTitle(QLatin1String("Job Real Time"));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

//    setMinimumSize(100, 400);

//    m_stack->setMinimumSize(100, 400);
//    m_stack->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    mainLayout->addWidget(m_toolBar);
    mainLayout->addWidget(m_stack);

    setLayout(mainLayout);

    connect(m_toolBar, SIGNAL(resetParameters()), this, SLOT(onResetParameters()));
}

ModelTuningWidget *JobRealTimeWidget::getTuningWidgetForItem(JobItem *jobItem)
{
    return m_jobItemToTuningWidget[jobItem];
}

void JobRealTimeWidget::setItem(JobItem * item)
{
    //qDebug() << "JobOutputDataWidget::setItem()";
    if(!item) return;

    m_currentItem = item;

    if(!isVisible()) return;

    ModelTuningWidget *widget = m_jobItemToTuningWidget[item];
    if( !widget && isValidJobItem(item)) {
        widget = new ModelTuningWidget(m_jobModel);
        widget->setItem(item);
        m_stack->addWidget(widget);
        m_jobItemToTuningWidget[item] = widget;

    } else {
        if( m_stack->currentWidget()) {
            m_stack->currentWidget()->hide();
        }
    }

    if(widget) {
        if(widget->isHidden()) {
            widget->show();
        }

        m_stack->setCurrentWidget(widget);
    }
}

void JobRealTimeWidget::onJobItemFinished(const QString &identifier)
{
    //qDebug() << "JobOutputDataWidget::onJobItemFinished()";
    JobItem *jobItem = m_jobModel->getJobItemForIdentifier(identifier);

    if(jobItem == m_currentItem) {
        if((jobItem->isCompleted() || jobItem->isCanceled()) && jobItem->getIntensityDataItem()) {
            qDebug() << "JobOutputDataWidget::dataChanged() JobItem::Completed";
            setItem(jobItem);
        }
    }
}

void JobRealTimeWidget::onResetParameters()
{
    ModelTuningWidget *widget = getCurrentModelTuningWidget();
    if(widget)
        widget->restoreModelsOfCurrentJobItem();
}

void JobRealTimeWidget::updateCurrentItem()
{
    if(!m_currentItem) return;
    setItem(m_currentItem);
}

void JobRealTimeWidget::onModelLoaded()
{
    JobItem *item = dynamic_cast<JobItem*>(m_jobModel->rootItem()->getItem());
    if (item) {
        setItem(item);
    } else {
        onJobItemDelete(m_currentItem);
    }
}

ModelTuningWidget *JobRealTimeWidget::getCurrentModelTuningWidget()
{
    ModelTuningWidget *result = dynamic_cast<ModelTuningWidget *>(m_stack->currentWidget());
    if(result && result->isHidden()) result = 0;
    return result;
}

//! Returns true if JobItem is valid for real time simulation, i.e.
//! it is not already running and it has valid models
bool JobRealTimeWidget::isValidJobItem(JobItem *item)
{
    return (item->isCompleted() || item->isCanceled()) && item->getMultiLayerItem() && item->getInstrumentItem();
}

void JobRealTimeWidget::onJobItemDelete(JobItem *item)
{
    //qDebug() << "JobOutputDataWidget::onJobItemDelete()";
    if(item == m_currentItem) m_currentItem=0;

    ModelTuningWidget *widget = m_jobItemToTuningWidget[item];
    if( !widget ) {
        // this is the case when user removes failed job which doesn't have propper widget
        return;
    }

    QMap<JobItem *, ModelTuningWidget *>::iterator it = m_jobItemToTuningWidget.begin();
    while(it!=m_jobItemToTuningWidget.end()) {
        if(it.value() == widget) {
            it = m_jobItemToTuningWidget.erase(it);
        } else {
            ++it;
        }
    }

    m_stack->removeWidget(widget);
    delete widget;
}

