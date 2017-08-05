#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mainWindowController = new MainWindowController(this);
    ui->setupUi(this);
    this->move(QApplication::desktop()->screen()->rect().center() -
               this->rect().center());


    connect(ui->action_About_Qt,&QAction::triggered,qApp,&QApplication::aboutQt);
    connect(ui->action_Exit,&QAction::triggered,qApp,&QApplication::quit);
    connect(ui->actionManually,&QAction::triggered,mainWindowController,&MainWindowController::onAddManually);
    connect(ui->action_About,&QAction::triggered,mainWindowController,&MainWindowController::onAbout);
    connect(ui->actionBug_Report,&QAction::triggered,mainWindowController,&MainWindowController::onBugReport);
    connect(ui->action_Share,&QAction::triggered,mainWindowController,&MainWindowController::onShareServer);
    connect(ui->actionScan_QR_Code,&QAction::triggered,mainWindowController,&MainWindowController::onAddScreenQRCapturer);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainWindowController;
}

