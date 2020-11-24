#ifndef MYCRYPT_H
#define MYCRYPT_H
#include <QObject>
#include <QMap>
class Crypt:public QObject
{
public:

    QString cryptString(QString &data)
    {

        QString resultString = "";
        for(int i = 0; i < data.length(); i++)
        {
            resultString.append(QString(QChar(data[i] = data[i+1])));
        }
        return resultString;
    }

    QString decryptString(QString &descryptData)
    {

        QString result = "";
        for(int j = 0; j < descryptData.length(); j++)
        {
            result.append(QString(QChar(descryptData[j] = descryptData[j])));
        }
        return descryptData;
    }
};

#endif // MYCRYPT_H
