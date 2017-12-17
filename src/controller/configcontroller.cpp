#include "configcontroller.h"

ConfigController::ConfigController(QObject *parent) : QObject(parent)
{
    config = new ConfigModel();
    ServerTable = new ServersTableModel();
}

ConfigController::ConfigController(const QString &configuration, QObject *parent) : QObject(parent){
    this->configFile = configuration;
    loadConfig(configuration);
}

ConfigController::~ConfigController(){

}

void ConfigController::loadConfig(const QString &configuration){
    config = new ConfigModel(configuration);
}

void ConfigController::addServerConfig(VmessConfigModel *server){
    this->config->Servers->append(server);
}

void ConfigController::saveConfig(){

    this->config->save();
}

ConfigController& ConfigController::getInstance(){
    static ConfigController instance(file);
    return instance;
}

ConfigController& ConfigController::getInstance(const QString &configuration){
    static ConfigController instance(configuration);
    return instance;
}

QString ConfigController::file = "";

