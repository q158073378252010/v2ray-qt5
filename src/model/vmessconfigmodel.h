#ifndef VMESSCONFIGMODEL_H
#define VMESSCONFIGMODEL_H

#include "serverconfigmodel.h"


class VmessConfigModel : public ServerConfigModel
{
public:
    VmessConfigModel(int Index);
    VmessConfigModel(int Index,QString Address,int Port,QString UserId,int UserAlterId,QString UserSecurity,QString Remarks,QString HeaderType,QString RequestHost,QString StreamSecurity);
    int Index;
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

};

#endif // VMESSCONFIGMODEL_H
