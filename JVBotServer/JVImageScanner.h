#ifndef JVIMAGESCANNER_H
#define JVIMAGESCANNER_H

#include <QString>

class JVImageScanner
{
public:
    JVImageScanner();
    ~JVImageScanner();
    QList<QString> getPathRandomImages(QString strDir, qint32 numImages, const QList<QString>& liExcludeFiles);

private:
    int generateRandomNumber(int low, int high);
};

#endif
