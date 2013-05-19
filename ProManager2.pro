#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T23:13:08
#
#-------------------------------------------------

QT       += core gui
INCLUDEPATH += /usr/include/qwt-qt4
LIBS += -L/usr/lib -lqwt-qt4

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProManager2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sysinfothread.cpp \
    processlist.cpp

HEADERS  += mainwindow.h \
    sysinfothread.h \
    processlist.h \
    ThreadsConfig.h

FORMS    += mainwindow.ui
