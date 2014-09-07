/* 
 * File:   JVTrainer.h
 * Author: vrs
 *
 * Created on August 23, 2014, 10:45 PM
 */

#ifndef JVTRAINER_H
#define	JVTRAINER_H

#include <QList>
#include <QString>
#include "JVTrainerCombination.h"
#include <QHash>
#include "JVTrainingSetData.h"
#include <QPair>

class JVTrainer
{
public:
    JVTrainer(QString strSetName, QList<QString> lSetClasses);
    ~JVTrainer();
    void generateCombinations(QList<QString>& lCombinations, qint32& nIndex);
    void displayCombinations(const QList<QString>& lCombinations);
    void readImages();
    qint32 train();
    void clear();
    void generateValidCombination();
    JVTrainingSetData* generateRandomTrainingSetData();
    
private:
    QString m_strSetName;
    QList<QString> m_lSetClasses;
    QList<QPair<QString,QString> > m_lImages;
    QHash<QString,JVTrainingSetData*> m_hashCombinations;
     int generateRandomNumber(int low, int high);
};

#endif	/* JVTRAINER_H */

