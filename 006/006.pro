#-------------------------------------------------
#
# Project created by QtCreator 2019-08-17T14:46:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 006
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwidget.cpp \
    topwidget.cpp \
    bottomwidget.cpp \
    leftwidget.cpp \
    centerwidget.cpp \
    rightwidget.cpp \
    videowidget.cpp \
    vehinfowidget.cpp \
    functionwidget.cpp \
    logwidget.cpp \
    historywidget.cpp

HEADERS += \
        mainwidget.h \
    topwidget.h \
    bottomwidget.h \
    leftwidget.h \
    centerwidget.h \
    rightwidget.h \
    videowidget.h \
    vehinfowidget.h \
    functionwidget.h \
    logwidget.h \
    historywidget.h

FORMS += \
        mainwidget.ui \
    topwidget.ui \
    bottomwidget.ui \
    leftwidget.ui \
    centerwidget.ui \
    rightwidget.ui \
    videowidget.ui \
    vehinfowidget.ui \
    functionwidget.ui \
    logwidget.ui \
    historywidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
