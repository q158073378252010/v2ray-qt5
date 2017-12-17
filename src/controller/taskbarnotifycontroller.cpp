#include "taskbarnotifycontroller.h"
#include "src/view/mainwindow.h"
#include <QApplication>

TaskBarNotifyController::TaskBarNotifyController(MainWindow* w,QObject *parent) : QObject(parent),
  mainWindow(w)
{
    trayIcon = new QSystemTrayIcon(mainWindow);
    trayIcon->setIcon(QIcon(":/icons/icons/v2ray.png"));
    trayIcon->setToolTip("V2Ray-Qt5");

    connect(trayIcon, &QSystemTrayIcon::activated, [this](QSystemTrayIcon::ActivationReason r) {
        if (r != QSystemTrayIcon::Context) {
            this->activate();
        }
    });
    trayMenu = new QMenu();
    restoreAction = new QAction(tr("Restore"), this);
    exitAction = new QAction(tr("Exit"),this);
    trayMenu->addAction(restoreAction);
    trayMenu->addAction(QIcon(":/icons/icons/exit-icon.png"),tr("Exit"),qApp, SLOT(quit()));
    trayIcon->setContextMenu(trayMenu);
    connect(restoreAction,&QAction::triggered,this,&TaskBarNotifyController::activate);



    //connect(restoreAction, &QAction::triggered, this, &TaskBarNotifyController::activate);

    trayIcon->show();
}

void TaskBarNotifyController::activate(){
    if (!mainWindow->isVisible() || mainWindow->isMinimized()) {

        mainWindow->showNormal();
        mainWindow->activateWindow();
        mainWindow->raise();
        //emit sigActivate(0);
    } else {
        //emit sigActivate(1);
        mainWindow->hide();
    }
}
