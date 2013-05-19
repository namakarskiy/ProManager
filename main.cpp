#include <QApplication>
#include "mainwindow.h"
#include "sysinfothread.h"
#include "processlist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    sysInfoThread *sysThread = new sysInfoThread();
    sysThread->start(QThread::NormalPriority);

    processList *procThread = new processList();
    procThread->start(QThread::NormalPriority);


    return a.exec();
}
