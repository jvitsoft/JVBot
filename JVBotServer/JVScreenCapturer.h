#ifndef JVSCREENCAPTURER_H
#define JVSCREENCAPTURER_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

//#include "JVRenderArea.h"
#include <QDebug>

#include <QElapsedTimer>

#include <QImage>
//#include "JVAreaSelector.h"
#include <QRect>
#include <QDebug>

using namespace cv;

#include <X11/Xlib.h>

class JVScreenCapturer
{
public:
    JVScreenCapturer();
    ~JVScreenCapturer();
    void setArea(QRect area);
    Mat getImage();
    
private:
    Display* m_pDisplay;
    Window m_root;
    qint32 m_nWidth;
    qint32 m_nHeight;
    qint32 m_nX;
    qint32 m_nY;
};
/*
class JVScreenCapturer
{
public:
    JVScreenCapturer(JVRenderArea* pJVRenderArea);
    ~JVScreenCapturer();

    QImage Mat2QImage(cv::Mat const& src);
    cv::Mat QImage2Mat(QImage const& src);

    void start();
    void stop();
    void tick();
    void startAreaSelector();

private:
    JVRenderArea* m_pJVRenderArea;
      bool m_bEnabled;
      bool m_bAreaSelectorEnabled;
      Display* m_pDisplay;
      Window m_root;
      qint32 m_nWidth;
      qint32 m_nHeight;
      qint32 m_nX;
      qint32 m_nY;
      JVAreaSelector* m_pJVAreaSelector;
};
 * 
 */

#endif
