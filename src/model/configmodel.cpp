#include "configmodel.h"

ConfigModel::ConfigModel(QObject *parent) : QObject(parent)
{
    Singleton = false;
    ActiveServer = -1;
    Servers = NULL;
}

ConfigModel::ConfigModel(const QString &configuration, QObject *parent){
    QFile ConfigFile(configuration);
    ConfigFile.open(QIODevice::ReadOnly | QIODevice::Text);
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
    QJsonArray ServerArray = ConfigObj["Servers"].toArray();
    Servers = new QMap<int,ServerConfigModel*>();
    int n = 0;
    for(QJsonArray::iterator it = ServerArray.begin();it != ServerArray.end();++it){
        QJsonObject tempServerObj = (*it).toObject();
        Servers->insert(n,new VmessConfigModel(
                            tempServerObj["Index"].toInt(),
                            tempServerObj["Address"].toString(),
                            tempServerObj["Port"].toInt(),
                            tempServerObj["UserId"].toString(),
                            tempServerObj["UserAlterId"].toInt(),
                            tempServerObj["UserSecurity"].toString(),
                            tempServerObj["Remarks"].toString(),
                            tempServerObj["HeaderType"].toString(),
                            tempServerObj["RequestHost"].toString(),
                            tempServerObj["StreamSecurity"].toString()));

    }



}
