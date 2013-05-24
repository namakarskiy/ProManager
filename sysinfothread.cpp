#include "sysinfothread.h"

sysInfoThread::sysInfoThread(QObject *parent) :
    QThread(parent)
{
    mutex.lock();
    sysInfoTimer = new QTimer();
    connect(sysInfoTimer,SIGNAL(timeout()),
            this,SLOT(getSystemInfo()),Qt::DirectConnection);
    inf = new SystemInfo;
    mutex.unlock();

}

void sysInfoThread::run()
{
    inf->getOtherInfo();
    sysInfoTimer->start(1000);
    exec();
}

sysInfoThread::~sysInfoThread()
{
   mutex.lock();
   this->exit(0);
   delete sysInfoTimer;
   this->deleteLater();
   mutex.unlock();
}

void sysInfoThread::getSystemInfo()
{
    mutex.lock();
    inf->getSystemInfo();
    mutex.unlock();
}


