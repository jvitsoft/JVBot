/* 
 * File:   JVViewer.h
 * Author: javi
 *
 * Created on 13 de agosto de 2014, 21:13
 */

#ifndef _JVVIEWER_H
#define	_JVVIEWER_H

#include "ui_JVViewer.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
//Include some useful constants for image encoding. Refer to: http://www.ros.org/doc/api/sensor_msgs/html/namespacesensor__msgs_1_1image__encodings.html for more info.
#include <sensor_msgs/image_encodings.h>

class JVViewer : public QWidget {
    Q_OBJECT
public:
    JVViewer(QWidget *parent = 0);
    virtual ~JVViewer();
   // void imageCallback(const sensor_msgs::ImageConstPtr& img);
    
public slots:
    void onTypeChanged(QString strType);
    
private:
    Ui::JVViewer widget;
    image_transport::Subscriber m_subImage;
};

#endif	/* _JVVIEWER_H */
