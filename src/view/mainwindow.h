#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "src/controller/mainwindowcontroller.h"
#include "src/controller/configcontroller.h"

class TaskBarNotifyController;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MainWindowController* mainWindowController;
    QSortFilterProxyModel *proxyModel;
    TaskBarNotifyController* icon;

private:
    Ui::MainWindow *ui;


private slots:
    void closeEvent(QCloseEvent *e);

public slots:
    void activate(int);
};

#endif // MAINWINDOW_H
