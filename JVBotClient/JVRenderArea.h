#ifndef JVRENDERAREA_H
#define JVRENDERAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
//Include some useful constants for image encoding. Refer to: http://www.ros.org/doc/api/sensor_msgs/html/namespacesensor__msgs_1_1image__encodings.html for more info.
#include <sensor_msgs/image_encodings.h>

class JVRenderArea : public QWidget
{
    Q_OBJECT

public:
    JVRenderArea(QWidget *parent, qint32 nWidth, qint32 nHeight);
    ~JVRenderArea();

    void render(QImage image);
    void render(cv::Mat matImage);
    void paintEvent(QPaintEvent *event);
    void clear();
    void save();
    QImage getImage();
    QImage Mat2QImage(cv::Mat const& src);
    cv::Mat QImage2Mat(QImage const& src);
     void imageCallback(const sensor_msgs::ImageConstPtr& img);
     void mousePressEvent(QMouseEvent *ev);
private:
    QImage m_image;

};

#endif
