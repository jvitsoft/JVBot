#ifndef JVAREASELECTOR_H
#define JVAREASELECTOR_H

#include <QWidget>
#include <QMouseEvent>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QDebug>
#include <QRect>
#include <X11/Xlib.h>

class JVAreaSelector
{

public:
    JVAreaSelector();
    ~JVAreaSelector();

    void processEvents();
    void start();
    void drawRectangle();
    QRect getSelectedArea();
private:

    struct RectCoords {
        qint32 m_nX, m_nY;
        qint32 m_nWidth, m_nHeight;
    };

    bool m_bEnabled;
    Display* m_pDisplay;
    Window* m_pWindowRoot;
    qint32 m_nScreen;
    RectCoords m_rc;
    GC m_gc;
};

#endif
