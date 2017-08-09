#include "mainwindowcontroller.h"
#include <QApplication>
#include "src/controller/configcontroller.h"
MainWindowController::MainWindowController(QWidget *parent) : QWidget(parent)
{

}

const QUrl MainWindowController::BugReport = QUrl("https://github.com/v2ray/v2ray-qt5/issues");

void MainWindowController::onAddManually(){
    EditDialog* editDialog = new EditDialog((QWidget*)parent());
    if(editDialog->exec()){

    }else {
        editDialog->deleteLater();
    }
}

void MainWindowController::onShareServer(){
    QString UrlStr("vmess://ew0KInBzIjogIuWkh+azqOWIq+WQjSIsDQoiYWRkIjogIjExMS4xMTEuMTExLjExMSIsDQoicG9ydCI6ICIzMjAwMCIsDQoiaWQiOiAiMTM4NmY4NWUtNjU3Yi00ZDZlLTlkNTYtNzhiYWRiNzVlMWZkIiwNCiJhaWQiOiAiMTAwIiwNCiJuZXQiOiAidGNwIiwNCiJ0eXBlIjogIm5vbmUiLA0KImhvc3QiOiAid3d3LmJiYi5jb20iLA0KInRscyI6ICJ0bHMiDQp9");
    QByteArray Url = UrlStr.toLatin1();
    ShareDialog* shareDialog = new ShareDialog(Url,(QWidget*)parent());
    shareDialog->exec();
}

void MainWindowController::onAddScreenQRCapturer(){
    QRCodeCapturer *capturer = new QRCodeCapturer((QWidget*)parent());
    connect(capturer, &QRCodeCapturer::closed,
            capturer, &QRCodeCapturer::deleteLater);
    connect(capturer, &QRCodeCapturer::qrCodeFound,
            this, &MainWindowController::onQRCodeCapturerResultFound,
            Qt::DirectConnection);
    capturer->show();
}

void MainWindowController::onQRCodeCapturerResultFound(const QString &uri)
{
    QRCodeCapturer* capturer = qobject_cast<QRCodeCapturer*>(sender());
    // Disconnect immediately to avoid duplicate signals
    disconnect(capturer, &QRCodeCapturer::qrCodeFound,
               this, &MainWindowController::onQRCodeCapturerResultFound);

}

void MainWindowController::onAbout(){
    QString text = QString("<h2>V2Ray-Qt5</h2><p><b>Version %1</b><br />"
                "Using "
                "<a href='https://github.com/v2ray/v2ray-core'>"
                "V2Ray-Core</a><br />"
                "<p>Copyright © 2017 "
                "<a href='https://github.com/SuperHentai'>"
                "Kaguya</a><br />"
                "License: <a href='http://www.gnu.org/licenses/lgpl.html'>"
                "GNU Lesser General Public License Version 3</a><br />"
                "<p>Project Page: "
                "<a href='https://github.com/v2ray/v2ray-qt5'>"
                "V2Ray-Qt5</a></p>"
                "<p>Acknowledgment:<br />"
                "This project is partly based on <a href='https://github.com/shadowsocks/shadowsocks-qt5'>"
                "Shadowsocks-Qt5</a></p>")
                .arg(QStringLiteral(APP_VERSION));
        QMessageBox::about((QWidget*)parent(), tr("About"), text);

}

void MainWindowController::onBugReport(){
    QDesktopServices::openUrl(MainWindowController::BugReport);
}

void MainWindowController::onQuit(){
    ConfigController::getInstance().saveConfig();
    QApplication::quit();

}


