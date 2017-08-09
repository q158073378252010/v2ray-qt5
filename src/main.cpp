#include "view/mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QTranslator>
#include <QDebug>
#include <QCommandLineParser>
#include "controller/configcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //ConfigController m = ConfigController::getInstance();
    QCommandLineParser* parser = new QCommandLineParser();
    parser->addHelpOption();
    parser->addVersionOption();
    QCommandLineOption option("c","specify configuration file.","config.json");
    parser->addOption(option);
    parser->process(a);

    QString configFile = parser->value(option);
    if (configFile.isEmpty()) {
#ifdef Q_OS_WIN
        configFile = a.applicationDirPath() + "/config.json";
#else
        QDir configDir = QDir::homePath() + "/.config/v2ray-qt5";
        configFile = configDir.absolutePath() + "/config.json";
        if (!configDir.exists()) {
            configDir.mkpath(configDir.absolutePath());
        }
    }
#endif
    ConfigController::file = configFile;
    ConfigController::getInstance();


    QTranslator *v2rayqt5t = new QTranslator(&a);
    v2rayqt5t->load(QLocale::system(), "v2ray-qt5", "_", ":/i18n");
    a.installTranslator(v2rayqt5t);
    MainWindow w;
    w.show();
    return a.exec();
}
