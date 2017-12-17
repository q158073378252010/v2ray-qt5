SOURCES +=  src/main.cpp\
            src/view/mainwindow.cpp \
    src/controller/configcontroller.cpp \
    src/model/inboundmodel.cpp \
    src/model/serverconfigmodel.cpp \
    src/model/configmodel.cpp \
    src/model/vmessconfigmodel.cpp \
    src/view/editdialog.cpp \
    src/view/sharedialog.cpp \
    src/utils/qrwidget.cpp \
    src/utils/qrcodecapturer.cpp \
    src/controller/mainwindowcontroller.cpp \
    src/utils/urihelper.cpp \
    $$PWD/model/serverstablemodel.cpp \
    $$PWD/model/serveritemmodel.cpp \
    $$PWD/controller/taskbarnotifycontroller.cpp

HEADERS  += src/view/mainwindow.h \
    src/controller/configcontroller.h \
    src/model/inboundmodel.h \
    src/model/serverconfigmodel.h \
    src/model/configmodel.h \
    src/model/vmessconfigmodel.h \
    src/view/editdialog.h \
    src/view/sharedialog.h \
    src/utils/qrwidget.h \
    src/utils/qrcodecapturer.h \
    src/controller/mainwindowcontroller.h \
    src/utils/urihelper.h \
    $$PWD/model/serverstablemodel.h \
    $$PWD/model/serveritemmodel.h \
    $$PWD/controller/taskbarnotifycontroller.h

FORMS    += src/view/mainwindow.ui \
    src/view/editdialog.ui \
    src/view/sharedialog.ui

RESOURCES += \
    src/resources/icons.qrc \
    src/resources/translations.qrc

TRANSLATIONS += src/resources/i18n/v2ray-qt5_zh_CN.ts \
                src/resources/i18n/v2ray-qt5_zh_TW.ts

