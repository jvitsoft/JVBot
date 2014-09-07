#include "JVRenderArea.h"
#include <QPainter>
#include <QDebug>

JVRenderArea::JVRenderArea(QWidget *parent,qint32 nWidth, qint32 nHeight) :
    QWidget(parent),
    m_image(nWidth,nHeight,QImage::Format_RGB32)
{
    clear();
}

JVRenderArea::~JVRenderArea()
{

}

void JVRenderArea::render(cv::Mat matImage)
{
    cv::Mat matResized;
    cv::resize(matImage,matResized,cv::Size(width(),height()));
    m_image = Mat2QImage(matResized);
    update();
}

void JVRenderArea::render(QImage image)
{
    m_image = image;
}

QImage JVRenderArea::Mat2QImage(cv::Mat const& src)
{
     cv::Mat temp; // make the same cv::Mat
     cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
     QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     dest.bits(); // enforce deep copy, see documentation
     // of QImage::QImage ( const uchar * data, int width, int height, Format format )
     return dest;
}

cv::Mat JVRenderArea::QImage2Mat(QImage const& src)
{
     cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
     cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
     cvtColor(tmp, result,CV_BGR2RGB);
     return result;
}

void JVRenderArea::mousePressEvent(QMouseEvent *ev){
    if(ev->buttons() == Qt::LeftButton){

        //m_bDrawMode = true;
        //m_pointMousePosition = ev->pos();
    }

}

void JVRenderArea::imageCallback(const sensor_msgs::ImageConstPtr& img)
{
    qDebug() << "Image receivied!";
    
       cv_bridge::CvImagePtr cv_ptr;
    //Always copy, returning a mutable CvImage
    //OpenCV expects color images to use BGR channel order.
    cv_ptr = cv_bridge::toCvCopy(img, sensor_msgs::image_encodings::BGR8);

    render(cv_ptr->image);
}

void JVRenderArea::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);

     QRect rect(event->rect());

    painter.drawImage(rect.topLeft(),m_image,rect);

}


void JVRenderArea::save()
{
    m_image.save("save.png");
}

QImage JVRenderArea::getImage()
{
    return m_image;
}

void JVRenderArea::clear()
{
    //int opacity = 20;// Set this between 0 and 255
        m_image.fill(Qt::gray);

    update();
}
