#include <QApplication>
#include "mainwindow.h"
#include "sysinfothread.h"
#include "processlistThread.h"
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;




    sysInfoThread *sysThread = new sysInfoThread();
    QObject::connect(sysThread->inf,SIGNAL(sendSystemInfo(SystemInformation)),
                    &w,SLOT(acceptSystemInfo(SystemInformation)));

    sysThread->start(QThread::NormalPriority);




    processListThread *procThread = new processListThread();
    procThread->start(QThread::NormalPriority);
     w.show();

    return a.exec();
}
