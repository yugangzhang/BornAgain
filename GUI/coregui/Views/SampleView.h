#ifndef SAMPLEMANAGER_H
#define SAMPLEMANAGER_H

#include "fancymainwindow.h"
#include "sampleeditorstack.h"
#include <QWidget>
#include <QMainWindow>
#include <QDockWidget>


//#include <QDesignerFormEditorInterface>
#include <QtDesigner/QDesignerFormEditorInterface>

class SampleView : public Manhattan::FancyMainWindow
{
public:

    enum SubWindows
    {
        WidgetBoxSubWindow,
        SampleInspectorSubWindow,
        PropertyEditorSubWindow,
        SampleWorkspaceSubWindow,
        NumberOfSubWindows
    };


    SampleView(QWidget *parent = 0);


public slots:
    void resetToDefaultLayout();


private:
    void initSubWindows();

    QDesignerFormEditorInterface *m_sampleEditor;

    SampleEditorStack *m_sampleEditorStack;

    QWidget *m_subWindows[NumberOfSubWindows];
    QDockWidget *m_dockWidgets[NumberOfSubWindows];

};


#endif // SAMPLEMANAGER_H
