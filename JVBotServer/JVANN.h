#ifndef JVANN_H
#define JVANN_H

#include <QString>
#include <QJsonObject>
#include <QSet>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/ml/ml.hpp"   
#include "JVInputGenerator.h"
#include <QScopedPointer>
#include "JVImage.h"
class JVANN
{
public:
    JVANN();
    ~JVANN();

    void setConfiguration(QJsonObject joConfigANN);
    void clearConfiguration();

    void addInput(qint32 numImage,JVImage* pJVImage);
    void addOutput(qint32 numImage,qint32 nClassId, qint32 nValue);

    QString getSetName();
    qint32 getNumImagesTraining();
    qint32 getNumImagesTest();
    QList<QString> getClasses();

    QString predict(const cv::Mat& matImage);
    void train();

    cv::Mat generateInputs(JVImage* pJVImage);

private:
//    bool lessThan( QPair<QString,qreal> pair1, QPair<QString,qreal> pair2 );

    struct QPairSecondComparer
    {
        template<typename T1, typename T2>
        bool operator()(const QPair<T1,T2> & a, const QPair<T1,T2> & b) const
        {
            return a.second > b.second;
        }
    };

    QString m_strSetName;
    QList<QString> m_setClasses;
    qint32 m_numImagesTraining;
    qint32 m_numImagesTest;

    bool m_bInputsInitialized;
    cv::Mat m_matInputs;
    cv::Mat m_matOutputs;
    CvANN_MLP* m_nnetwork;
    QScopedPointer<JVInputGenerator> m_pJVInputGenerator;
};

#endif
