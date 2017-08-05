#-------------------------------------------------
#
# Project created by QtCreator 2017-08-02T14:39:28
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = v2ray-qt5
TEMPLATE = app
VERSION    = 0.1.0
DEFINES   += APP_VERSION=\\\"$$VERSION\\\"
include(src/v2ray-qt5.pri)

unix: {
    CONFIG    += link_pkgconfig
    PKGCONFIG += libqrencode zbar
    !macx: {
        PKGCONFIG += gtk+-2.0 appindicator-0.1
        DEFINES   += USE_APP_INDICATOR
    }
}

