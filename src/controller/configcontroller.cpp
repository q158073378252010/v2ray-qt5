#include "configcontroller.h"

ConfigController::ConfigController(QObject *parent) : QObject(parent)
{
    config = new ConfigModel();
}

ConfigController::ConfigController(const QString &configuration, QObject *parent) : QObject(parent){
    loadConfig();
}

ConfigController::~ConfigController(){

}

void ConfigController::loadConfig(const QString &configuration){
    config = new ConfigModel(configuration);
}

void ConfigController::addServerConfig(ServerConfigModel *server){

}

void ConfigController::saveConfig(){

}

ConfigController& ConfigController::getInstance(){
    static ConfigController instance;
    return instance;
}

ConfigController& ConfigController::getInstance(const QString &configuration){
    static ConfigController instance(configuration);
    return instance;
}
