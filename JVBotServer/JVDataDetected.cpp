#include "JVDataDetected.h"

JVDataDetected::JVDataDetected()
{
    
}

JVDataDetected::~JVDataDetected()
{
    
}

void JVDataDetected::setBoundingBox(Rect rBoundingBox)
{
    m_rBoundingBox = rBoundingBox;
}

Rect JVDataDetected::getBoundingBox()
{
    return m_rBoundingBox;
}

void JVDataDetected::setData(QString strData)
{
    m_strData = strData;
}

QString JVDataDetected::getData()
{
    return m_strData;
}

void JVDataDetected::setMatSource(Mat matSource)
{
    m_matSource = matSource;
}

Mat JVDataDetected::getMatSource()
{
    return m_matSource;
}