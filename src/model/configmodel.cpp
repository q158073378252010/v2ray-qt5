#include "configmodel.h"

ConfigModel::ConfigModel(QObject *parent) : QObject(parent)
{
    Singleton = false;
    ActiveServer = -1;
    Servers = NULL;
    configFile = "config.json";
}

ConfigModel::ConfigModel(const QString &configuration, QObject *parent){
    Servers = new QList<VmessConfigModel*>();
    configFile = configuration;
    QFile ConfigFile(configuration);
    ConfigFile.open(QIODevice::ReadWrite | QIODevice::Text);
    if(!ConfigFile.isOpen()){
        qCritical() << "Error: cannot open " << configuration;
        return;
    }
    if(!ConfigFile.isReadable()){
        qCritical() << "Error: cannot read " << configuration;
        return;
    }
    QJsonParseError err;
    QJsonDocument JsonDoc = QJsonDocument::fromJson(ConfigFile.readAll(), &err);
    ConfigFile.close();
    if (err.error != QJsonParseError::NoError) {
        qCritical() << err.errorString();
    }
    if (JsonDoc.isEmpty()) {
        qCritical() << "Config file" << configuration << "is empty!";
        return;
    }
    QJsonObject ConfigObj = JsonDoc.object();
    Singleton = ConfigObj["Singleton"].toBool();
    ActiveServer = ConfigObj["ActiveServer"].toInt();
    V2RayBin = ConfigObj["V2RayBin"].toString();
    QJsonArray ServerArray = ConfigObj["Servers"].toArray();

    int n = 0;
    for(QJsonArray::iterator it = ServerArray.begin();it != ServerArray.end();++it){
        QJsonObject tempServerObj = (*it).toObject();
        Servers->append(new VmessConfigModel(
                            tempServerObj["Address"].toString(),
                            tempServerObj["Port"].toInt(),
                            tempServerObj["UserId"].toString(),
                            tempServerObj["UserAlterId"].toInt(),
                            tempServerObj["UserSecurity"].toString(),
                            tempServerObj["Remarks"].toString(),
                            tempServerObj["HeaderType"].toString(),
                            tempServerObj["RequestHost"].toString(),
                            tempServerObj["StreamSecurity"].toString(),
                            tempServerObj["LocalPort"].toInt(),
                            tempServerObj["LastUseTime"].toInt()));
    }
}

void ConfigModel::save(){

    QJsonObject configJsonObj;
    configJsonObj.insert("Singleton",this->Singleton);
    configJsonObj.insert("ActiveServer",this->ActiveServer);
    configJsonObj.insert("V2RayBin",this->V2RayBin);
    QJsonArray serversArray;
    int count = this->Servers->size();
    for(int i=0;i<count;i++){
        QJsonObject tempServerObj;
        tempServerObj.insert("Protocol",this->Servers->at(i)->Protocol);
        tempServerObj.insert("Address",this->Servers->at(i)->Address);
        tempServerObj.insert("Port",this->Servers->at(i)->Port);
        tempServerObj.insert("UserId",this->Servers->at(i)->UserId);
        tempServerObj.insert("UserAlterId",this->Servers->at(i)->UserAlterId);
        tempServerObj.insert("UserSecurity",this->Servers->at(i)->UserSecurity);
        tempServerObj.insert("Remarks",this->Servers->at(i)->Remarks);
        tempServerObj.insert("HeaderType",this->Servers->at(i)->HeaderType);
        tempServerObj.insert("RequestHost",this->Servers->at(i)->RequestHost);
        tempServerObj.insert("StreamSecurity",this->Servers->at(i)->StreamSecurity);
        tempServerObj.insert("LastUseTime",qint64(this->Servers->at(i)->LastUseTime.toTime_t()));
        tempServerObj.insert("LocalPort",this->Servers->at(i)->LocalPort);
        serversArray.append(tempServerObj);
    }
    configJsonObj.insert("Servers",serversArray);
    QJsonDocument doc(configJsonObj);
    QString json = doc.toJson();

    QFile ConfigFile(configFile);
    ConfigFile.open(QIODevice::WriteOnly);
    if(!ConfigFile.isOpen()){
        qCritical() << "Error: cannot open " << configFile;
        return;
    }
    QTextStream out(&ConfigFile);
    out<<json;
}


