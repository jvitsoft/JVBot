#include "JVScreenCapturer.h"


JVScreenCapturer::JVScreenCapturer() :
    m_pDisplay(XOpenDisplay(0)),
    m_root(DefaultRootWindow(m_pDisplay))
{
    //XWindowAttributes attributes = {0};
    //XGetWindowAttributes(m_pDisplay, m_root, &attributes);


}

void JVScreenCapturer::setArea(QRect area)
{
       m_nWidth = area.width();
    m_nHeight = area.height();
    m_nX = area.x();
    m_nY = area.y();
}

JVScreenCapturer::~JVScreenCapturer()  
{
    
}

Mat JVScreenCapturer::getImage()
{
    qDebug() << "JVScreenCapturer::getImage";
    
    XImage* pXImage = XGetImage(m_pDisplay, m_root, m_nX, m_nY , m_nWidth, m_nHeight, AllPlanes, ZPixmap);

    IplImage *iplImage = cvCreateImageHeader(
        cvSize(pXImage->width, pXImage->height),
        IPL_DEPTH_8U,
        pXImage->bits_per_pixel/8);
    iplImage->widthStep = pXImage->bytes_per_line;
    iplImage->imageData = pXImage->data;
    Mat matImg = Mat(iplImage);
    
    return matImg;
}
/*
using namespace cv;

void JVScreenCapturer::startAreaSelector()
{
   m_pJVAreaSelector->start();
   QRect rect = m_pJVAreaSelector->getSelectedArea();
   m_nX = rect.x();
   m_nY = rect.y();
   m_nWidth = rect.width();
   m_nHeight = rect.height();
}

void JVScreenCapturer::start()
{
    m_bEnabled = true;
}

void JVScreenCapturer::tick()
{
    if(m_bEnabled == true)
    {
        XImage* pXImage = XGetImage(m_pDisplay, m_root, m_nX, m_nY , m_nWidth, m_nHeight, AllPlanes, ZPixmap);

        IplImage *iplImage = cvCreateImageHeader(
            cvSize(pXImage->width, pXImage->height),
            IPL_DEPTH_8U,
            pXImage->bits_per_pixel/8);
        iplImage->widthStep = pXImage->bytes_per_line;
        iplImage->imageData = pXImage->data;
        Mat matImg = Mat(iplImage);

        m_pJVRenderArea->render(matImg);
    }
}

void JVScreenCapturer::stop()
{
    m_bEnabled = false;
}

JVScreenCapturer::JVScreenCapturer(JVRenderArea* pJVRenderArea)  :
    m_pDisplay(XOpenDisplay(0)),
    m_root(DefaultRootWindow(m_pDisplay))
{
    m_pJVRenderArea = pJVRenderArea;
    m_pJVAreaSelector = new JVAreaSelector();
    m_bEnabled = false;

    XWindowAttributes attributes = {0};
    XGetWindowAttributes(m_pDisplay, m_root, &attributes);

    m_nWidth = attributes.width;
    m_nHeight = attributes.height;
    m_nX = 0;
    m_nY = 0;
}

QImage JVScreenCapturer::Mat2QImage(cv::Mat const& src)
{
     cv::Mat temp; // make the same cv::Mat
     cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
     QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     dest.bits(); // enforce deep copy, see documentation
     // of QImage::QImage ( const uchar * data, int width, int height, Format format )
     return dest;
}

cv::Mat JVScreenCapturer::QImage2Mat(QImage const& src)
{
     cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
     cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
     cvtColor(tmp, result,CV_BGR2RGB);
     return result;
}

JVScreenCapturer::~JVScreenCapturer()
{
     XCloseDisplay(m_pDisplay);
}
*/