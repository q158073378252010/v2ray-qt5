#include "vmessconfigmodel.h"

VmessConfigModel::VmessConfigModel()
{
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
    LocalPort = 1080;
    this->LastUseTime = QDateTime::currentDateTime();
}

VmessConfigModel::VmessConfigModel(QString Address, int Port, QString UserId, int UserAlterId, QString UserSecurity, QString Remarks, QString HeaderType, QString RequestHost, QString StreamSecurity, int LocalPort, uint LastUseTime){
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
    this->LocalPort = LocalPort;
    this->LastUseTime = QDateTime::fromTime_t(LastUseTime,QTimeZone::systemTimeZone());
}

int VmessConfigModel::getLatency(){
    return 0;
}

bool VmessConfigModel::isRunning(){
    return true;
}

VmessConfigModel::~VmessConfigModel(){}
