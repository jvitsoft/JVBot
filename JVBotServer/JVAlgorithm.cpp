#include "JVAlgorithm.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>

JVAlgorithm::JVAlgorithm()
{

}

JVAlgorithm::~JVAlgorithm()
{

}

void JVAlgorithm::onInit(QString strId, QJsonObject joConfigAlgorithm)
{
    m_strId = strId;
}

QString JVAlgorithm::getId()
{
    return m_strId;
}

void JVAlgorithm::process(JVImage* pJVImage)
{

}
