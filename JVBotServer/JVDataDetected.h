/* 
 * File:   JVDataDetected.h
 * Author: vrs
 *
 * Created on August 24, 2014, 2:41 PM
 */

#ifndef JVDATADETECTED_H
#define	JVDATADETECTED_H

#include <QString>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

class JVDataDetected
{
public:
    JVDataDetected();
    ~JVDataDetected();
    
    void setData(QString strData);
    void setBoundingBox(Rect rBoundingBox);
    QString getData();
    Rect getBoundingBox();
    
    void setMatSource(Mat matSource);
    Mat getMatSource();
    
private:
    QString m_strData;
    Rect m_rBoundingBox;
    Mat m_matSource;
};

#endif	/* JVDATADETECTED_H */

