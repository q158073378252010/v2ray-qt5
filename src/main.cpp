#include "view/mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QTranslator>
#include <QDebug>
#include "controller/configcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //ConfigController m = ConfigController::getInstance();
    ConfigModel* x = ConfigController::getInstance().config;
    x->ActiveServer = 10;
    QTranslator *v2rayqt5t = new QTranslator(&a);
    v2rayqt5t->load(QLocale::system(), "v2ray-qt5", "_", ":/i18n");
    a.installTranslator(v2rayqt5t);
    MainWindow w;
    w.show();
    return a.exec();
}
