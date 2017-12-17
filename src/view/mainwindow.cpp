#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/controller/taskbarnotifycontroller.h"

#include <QDesktopWidget>
#include <QCloseEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mainWindowController = new MainWindowController(this);
    ui->setupUi(this);
    this->move(QApplication::desktop()->screen()->rect().center() -
               this->rect().center());
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(ConfigController::getInstance().ServerTable);
    proxyModel->setSortRole(Qt::EditRole);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterKeyColumn(-1);//read from all columns
    ui->ServersTableView->setModel(proxyModel);
    connect(ui->action_About_Qt,&QAction::triggered,qApp,&QApplication::aboutQt);
    connect(ui->action_Exit,&QAction::triggered,mainWindowController,&MainWindowController::onQuit);
    connect(ui->actionManually,&QAction::triggered,mainWindowController,&MainWindowController::onAddManually);
    connect(ui->action_About,&QAction::triggered,mainWindowController,&MainWindowController::onAbout);
    connect(ui->actionBug_Report,&QAction::triggered,mainWindowController,&MainWindowController::onBugReport);
    connect(ui->action_Share,&QAction::triggered,mainWindowController,&MainWindowController::onShareServer);
    connect(ui->actionScan_QR_Code,&QAction::triggered,mainWindowController,&MainWindowController::onAddScreenQRCapturer);
    //ui->ServersTableView->setHorizontalHeader();

    icon = new TaskBarNotifyController(this);
    //connect(icon,SIGNAL(TaskBarNotifyController::sigActivate(int)) ,this,SLOT(activate(int)));

}

void MainWindow::activate(int){
    return;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainWindowController;
    delete icon;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if (e->spontaneous()) {
        e->ignore();
        hide();
    } else {
        QMainWindow::closeEvent(e);
    }
}

