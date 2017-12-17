#ifndef VMESSCONFIGMODEL_H
#define VMESSCONFIGMODEL_H

#include <QDate>
#include <QDateTime>
#include <QTimeZone>
#include <QObject>
#include "serverconfigmodel.h"


class VmessConfigModel : public QObject
{
    Q_OBJECT
public:
    bool isRunning();
    int getLatency();
    VmessConfigModel();
    VmessConfigModel(QString Address,int Port,QString UserId,int UserAlterId,QString UserSecurity,QString Remarks,QString HeaderType,QString RequestHost,QString StreamSecurity,int LocalPort,uint LastUseTime);
    ~VmessConfigModel();
    QString Protocol;
    QString Address;
    int Port;
    QString UserId;
    int UserAlterId;
    QString UserSecurity;
    QString Remarks;
    QString HeaderType;
    QString RequestHost;
    QString StreamSecurity;
    QDateTime LastUseTime;
    int LocalPort;
};

#endif // VMESSCONFIGMODEL_H
