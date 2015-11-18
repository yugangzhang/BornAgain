// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/MaskWidgets/MaskEditorToolBar.cpp
//! @brief     Implements class MaskEditorToolBar
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "MaskEditorToolBar.h"
#include <QStyle>
#include <QVariant>
#include <QToolButton>
#include <QLabel>
#include <QButtonGroup>
#include <QDebug>

namespace {
const int toolbar_icon_size = 32;
}

MaskEditorToolBar::MaskEditorToolBar(QWidget *parent)
    : QToolBar(parent)
    , m_activityButtonGroup(new QButtonGroup(this))
    , m_maskValueGroup(new QButtonGroup(this))
{
    // const int size = style()->pixelMetric(QStyle::PM_SmallIconSize);
    // setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    setIconSize(QSize(toolbar_icon_size, toolbar_icon_size));

    setProperty("_q_custom_style_disabled", QVariant(true));

    setup_selection_group();
    add_separator();
    setup_masktype_group();
    add_separator();
    setup_shapes_group();
    add_separator();
    setup_maskmodify_group();
    add_separator();
    setup_extratools_group();

    connect(m_activityButtonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(onButtonGroupChange(int)));
    connect(m_maskValueGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(onButtonGroupChange(int)));

    m_previousActivity = getCurrentActivity();

}

//! Handles ZOOM requests from MaskGraphicsView while user press and holds
//! space bar. As soon as space bar is released, activity is returned to previous state.
void MaskEditorToolBar::onChangeActivityRequest(MaskEditorActivity::Flags value)
{
    if(value.testFlag(MaskEditorActivity::PAN_ZOOM_MODE)) {
        m_previousActivity = getCurrentActivity();
        m_activityButtonGroup->button(MaskEditorActivity::PAN_ZOOM_MODE)->setChecked(true);
    } else {
        setCurrentActivity(m_previousActivity);
    }
    emit activityModeChanged(getCurrentActivity());
}

void MaskEditorToolBar::onButtonGroupChange(int value)
{
    Q_UNUSED(value);
    emit activityModeChanged(getCurrentActivity());
}


void MaskEditorToolBar::setup_selection_group()
{
    QToolButton *selectionButton = new QToolButton(this);
    selectionButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_arrow.svg"));
    selectionButton->setToolTip("Select/modify mode");
    selectionButton->setCheckable(true);
    selectionButton->setChecked(true);
    addWidget(selectionButton);

    QToolButton *panButton = new QToolButton(this);
    panButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_hand.svg"));
    panButton->setToolTip("Pan/zoom mode");
    panButton->setCheckable(true);
    addWidget(panButton);

    QToolButton *refreshButton = new QToolButton(this);
    refreshButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_refresh.svg"));
    refreshButton->setToolTip("Reset pan/zoom to initial state");
    addWidget(refreshButton);

    m_activityButtonGroup->addButton(selectionButton, MaskEditorActivity::SELECTION_MODE);
    m_activityButtonGroup->addButton(panButton, MaskEditorActivity::PAN_ZOOM_MODE);
}

void MaskEditorToolBar::setup_masktype_group()
{
    QToolButton *maskTrueButton = new QToolButton(this);
    maskTrueButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_masktrue.svg"));
    maskTrueButton->setToolTip("Set mask to True (area is excluded from the simulation)");
    maskTrueButton->setCheckable(true);
    maskTrueButton->setChecked(true);
    addWidget(maskTrueButton);

    QToolButton *maskFalseButton = new QToolButton(this);
    maskFalseButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_maskfalse.svg"));
    maskFalseButton->setToolTip("Set mask to False (area stays in the simulation)");
    maskFalseButton->setCheckable(true);
    addWidget(maskFalseButton);

    m_maskValueGroup->addButton(maskTrueButton, MaskEditorActivity::MASK_GREEN_ID);
    m_maskValueGroup->addButton(maskFalseButton, MaskEditorActivity::MASK_RED_ID);
}

void MaskEditorToolBar::setup_shapes_group()
{
    QToolButton *rectangleButton = new QToolButton(this);
    rectangleButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_rectangle.svg"));
    rectangleButton->setToolTip("Create rectangle mask");
    rectangleButton->setCheckable(true);
    addWidget(rectangleButton);

    QToolButton *polygonButton = new QToolButton(this);
    polygonButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_polygon.svg"));
    polygonButton->setToolTip("Create polygon mask");
    polygonButton->setCheckable(true);
    addWidget(polygonButton);

    QToolButton *verticalLineButton = new QToolButton(this);
    verticalLineButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_verticalline.svg"));
    verticalLineButton->setToolTip("Create vertical line mask");
    verticalLineButton->setCheckable(true);
    addWidget(verticalLineButton);

    QToolButton *horizontalLineButton = new QToolButton(this);
    horizontalLineButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_horizontalline.svg"));
    horizontalLineButton->setToolTip("Create horizontal line mask");
    horizontalLineButton->setCheckable(true);
    addWidget(horizontalLineButton);

    QToolButton *ellipseButton = new QToolButton(this);
    ellipseButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_ellipse.svg"));
    ellipseButton->setToolTip("Create ellipse mask");
    ellipseButton->setCheckable(true);
    addWidget(ellipseButton);

    QToolButton *maskAllButton = new QToolButton(this);
    maskAllButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_maskall.svg"));
    maskAllButton->setToolTip("Create masked area covering whole detector plane.\nWill be placed beneath all masks.");
    maskAllButton->setCheckable(true);
    addWidget(maskAllButton);

    m_activityButtonGroup->addButton(rectangleButton, MaskEditorActivity::RECTANGLE_MODE);
    m_activityButtonGroup->addButton(polygonButton, MaskEditorActivity::POLYGON_MODE);
    m_activityButtonGroup->addButton(verticalLineButton, MaskEditorActivity::VERTICAL_LINE_MODE);
    m_activityButtonGroup->addButton(horizontalLineButton, MaskEditorActivity::HORIZONTAL_LINE_MODE);
    m_activityButtonGroup->addButton(ellipseButton, MaskEditorActivity::ELLIPSE_MODE);
    m_activityButtonGroup->addButton(maskAllButton, MaskEditorActivity::MASKALL_MODE);
}

void MaskEditorToolBar::setup_maskmodify_group()
{
    QToolButton *bringToFrontButton = new QToolButton(this);
    bringToFrontButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_bringtofront.svg"));
    bringToFrontButton->setToolTip("Rise selected mask one level up.");
    addWidget(bringToFrontButton);

    QToolButton *sendToBackButton = new QToolButton(this);
    sendToBackButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_sendtoback.svg"));
    sendToBackButton->setToolTip("Lower selected mask one level down.");
    addWidget(sendToBackButton);
}

void MaskEditorToolBar::setup_extratools_group()
{
    QToolButton *propertyPanelButton = new QToolButton(this);
    propertyPanelButton->setIcon(QIcon(":/MaskWidgets/images/maskeditor_toolpanel.svg"));
    propertyPanelButton->setToolTip("Open panel with additional settings.");
    propertyPanelButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    addWidget(propertyPanelButton);

    connect(propertyPanelButton, SIGNAL(clicked()),
            this, SIGNAL(toolPanelRequest()));
}

void MaskEditorToolBar::add_separator()
{
    addWidget(new QLabel(" "));
    addSeparator();
    addWidget(new QLabel(" "));
}

MaskEditorActivity::Flags MaskEditorToolBar::getCurrentActivity() const
{
    MaskEditorActivity::Flags result;
    result |= MaskEditorActivity::EActivityType(m_activityButtonGroup->checkedId());
    result |= MaskEditorActivity::EActivityType(m_maskValueGroup->checkedId());
    qDebug() << "MaskEditorToolBar::getCurrentActivity():" << result;
    return result;
}

void MaskEditorToolBar::setCurrentActivity(MaskEditorActivity::Flags value)
{
    if(value.testFlag(MaskEditorActivity::SELECTION_MODE))
        m_activityButtonGroup->button(MaskEditorActivity::SELECTION_MODE)->setChecked(true);
    if(value.testFlag(MaskEditorActivity::PAN_ZOOM_MODE))
        m_activityButtonGroup->button(MaskEditorActivity::PAN_ZOOM_MODE)->setChecked(true);
    if(value.testFlag(MaskEditorActivity::RECTANGLE_MODE))
        m_activityButtonGroup->button(MaskEditorActivity::RECTANGLE_MODE)->setChecked(true);
    if(value.testFlag(MaskEditorActivity::POLYGON_MODE))
        m_activityButtonGroup->button(MaskEditorActivity::POLYGON_MODE)->setChecked(true);
    if(value.testFlag(MaskEditorActivity::VERTICAL_LINE_MODE))
        m_activityButtonGroup->button(MaskEditorActivity::VERTICAL_LINE_MODE)->setChecked(true);
    if(value.testFlag(MaskEditorActivity::HORIZONTAL_LINE_MODE))
        m_activityButtonGroup->button(MaskEditorActivity::HORIZONTAL_LINE_MODE)->setChecked(true);
    if(value.testFlag(MaskEditorActivity::ELLIPSE_MODE))
        m_activityButtonGroup->button(MaskEditorActivity::ELLIPSE_MODE)->setChecked(true);
    if(value.testFlag(MaskEditorActivity::MASKALL_MODE))
        m_activityButtonGroup->button(MaskEditorActivity::MASKALL_MODE)->setChecked(true);

    if(value.testFlag(MaskEditorActivity::MASK_GREEN_ID))
        m_maskValueGroup->button(MaskEditorActivity::MASK_GREEN_ID)->setChecked(true);
    if(value.testFlag(MaskEditorActivity::MASK_RED_ID))
        m_maskValueGroup->button(MaskEditorActivity::MASK_RED_ID)->setChecked(true);
}

