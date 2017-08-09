#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QWidget>
#include <QMessageBox>
#include <qdesktopservices.h>
#include "src/model/serverconfigmodel.h"
#include "src/view/editdialog.h"
#include "src/view/sharedialog.h"
#include "src/utils/qrcodecapturer.h"

class MainWindowController : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindowController(QWidget *parent = 0);
    static const QUrl BugReport;
signals:

public slots:
    void onAddManually();
    void onShareServer();
    void onAddScreenQRCapturer();
    void onQRCodeCapturerResultFound(const QString &uri);
    void onAbout();
    void onBugReport();
    void onQuit();
};

#endif // MAINWINDOWCONTROLLER_H
