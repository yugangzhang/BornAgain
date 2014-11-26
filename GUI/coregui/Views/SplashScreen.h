#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include "WinDllMacros.h"

class BA_CORE_API_ SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(QWidget *parent = 0);


public slots:
    void setProgress(int value)
    {
      m_progress = value;
      if (m_progress > 100)
        m_progress = 100;
      if (m_progress < 0)
        m_progress = 0;
      update();
    }

protected:
    void drawContents(QPainter *painter);
private:
    int m_width, m_height;
    int m_progress;

};

#endif