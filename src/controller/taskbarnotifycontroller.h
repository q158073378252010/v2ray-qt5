#ifndef TASKBARNOTIFYCONTROLLER_H
#define TASKBARNOTIFYCONTROLLER_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QStringList>
#include <QAction>

#define signals public
class MainWindow;

class TaskBarNotifyController : public QObject
{
    Q_OBJECT
public:
    explicit TaskBarNotifyController(MainWindow* mainWindow, QObject *parent = 0);

signals:
    void sigActivate(int value);
private:
    QSystemTrayIcon* trayIcon;
    QMenu* trayMenu;
    MainWindow* mainWindow;
    QAction* restoreAction;
    QAction* exitAction;
    void activate();

public slots:
};

#endif // TASKBARNOTIFYCONTROLLER_H
