#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T23:13:08
#
#-------------------------------------------------

QT       += core gui
INCLUDEPATH += /usr/include/qwt
LIBS += -L/usr/lib -lqwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProManager2
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    sysinfothread.cpp \
    processlistThread.cpp \
    systeminfo.cpp \
    procinfo.cpp

HEADERS  += mainwindow.h \
    sysinfothread.h \
    ThreadsConfig.h \
    processlistThread.h \
    systeminfo.h \
    procinfo.h

FORMS    += mainwindow.ui
