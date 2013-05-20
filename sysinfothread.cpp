#include "sysinfothread.h"

sysInfoThread::sysInfoThread(QObject *parent) :
    QThread(parent)
{
    mutex.lock();
    sysInfoTimer = new QTimer();
    connect(sysInfoTimer,SIGNAL(timeout()),
            this,SLOT(getSystemInfo()),Qt::DirectConnection);
    qDebug()<<"sysinfoTHread started";

    mutex.unlock();
}

void sysInfoThread::run()
{
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
    qDebug()<<"ololol";
    mutex.unlock();
}


