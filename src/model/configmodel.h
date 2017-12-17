#ifndef CONFIGMODEL_H
#define CONFIGMODEL_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QDebug>


#include "vmessconfigmodel.h"
#include "inboundmodel.h"

class ConfigModel : public QObject
{
    Q_OBJECT
public:
    explicit ConfigModel(QObject *parent = 0);
    explicit ConfigModel(const QString &configuration, QObject *parent = 0);
    QString V2RayBin;
    bool Singleton;
    int ActiveServer;
    QList<VmessConfigModel*> *Servers;
    void save();
signals:
private:
    QString configFile;

public slots:
};

#endif // CONFIGMODEL_H
