#include "vmessconfigmodel.h"

VmessConfigModel::VmessConfigModel(int Index)
{
    this->Index = Index;
    Protocol = "vmess";
    Address = "";
    Port = 8964;
    UserId = "";
    UserAlterId = 10;
    UserSecurity = "aes-128-gcm";
    Remarks = "";
    HeaderType = "none";
    RequestHost = "";
    StreamSecurity = "";
}

VmessConfigModel::VmessConfigModel(int Index, QString Address, int Port, QString UserId, int UserAlterId, QString UserSecurity, QString Remarks, QString HeaderType, QString RequestHost, QString StreamSecurity){
    this->Index = Index;
    this->Protocol = "vmess";
    this->Address = Address;
    this->Port = Port;
    this->UserId = UserId;
    this->UserAlterId = UserAlterId;
    this->UserSecurity = UserSecurity;
    this->Remarks = Remarks;
    this->HeaderType = HeaderType;
    this->RequestHost = RequestHost;
    this->StreamSecurity = StreamSecurity;
}
