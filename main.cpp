#include <QApplication>
#include "mainwindow.h"
#include "sysinfothread.h"
#include "processlistThread.h"
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
 //////////////////////////

    sysInfoThread *sysThread = new sysInfoThread();
    QObject::connect(sysThread->inf,SIGNAL(sendSystemInfo(SystemInformation)),
                    &w,SLOT(acceptSystemInfo(SystemInformation)));

    sysThread->start(QThread::NormalPriority);
  //  QObject::connect(&w.ui);
///////////////////////////
    processListThread *procThread = new processListThread();
   QObject::connect(procThread->info,SIGNAL(sendProcessList(QList<Process>*)),
                    &w,SLOT(acceptProcessList(QList<Process>*)));

    procThread->start(QThread::NormalPriority);
//////////////////////////


     w.show();

    return a.exec();
}
