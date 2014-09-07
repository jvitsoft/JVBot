#include "JVTrainerCombination.h"

JVTrainerCombination::JVTrainerCombination()
{
    
}

JVTrainerCombination::~JVTrainerCombination()
{
    
}

void JVTrainerCombination::addImage(QString strPath)
{
    m_lImages.append(strPath);
    m_strId += strPath;
}

bool JVTrainerCombination::containImage(QString strPath)
{
    return m_lImages.contains(strPath);
}

QList<QString>& JVTrainerCombination::getImages()
{
    return m_lImages;
}

QString& JVTrainerCombination::getId()
{
    return m_strId;
}