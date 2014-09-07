/* 
 * File:   JVTrainerCombination.h
 * Author: vrs
 *
 * Created on August 24, 2014, 11:11 AM
 */

#ifndef JVTRAINERCOMBINATION_H
#define	JVTRAINERCOMBINATION_H

#include <QList>
#include <QString>

class JVTrainerCombination
{
public:
    JVTrainerCombination();
    ~JVTrainerCombination();
    
    QList<QString>& getImages();
    QString& getId();
    bool containImage(QString strPath);
    void addImage(QString strPath);
    
    QList<QString> m_lImages;
    QString m_strId;
    //qint32 m_vImages[2];
};

#endif	/* JVTRAINERCOMBINATION_H */

