#include <QApplication>
#include "mainwindow.h"
#include "sysinfothread.h"
#include "processlistThread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    sysInfoThread *sysThread = new sysInfoThread();
    sysThread->start(QThread::NormalPriority);

    processListThread *procThread = new processListThread();
    procThread->start(QThread::NormalPriority);

    return a.exec();
}
