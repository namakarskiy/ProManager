#include "sysinfothread.h"

sysInfoThread::sysInfoThread(QObject *parent) :
    QThread(parent)
{
    sysInfoTimer = new QTimer(this);
    connect(sysInfoTimer,SIGNAL(timeout()),
            this,SLOT(getSystemInfo()));
}

void sysInfoThread::run()
{
    sysInfoTimer->start(1000);
    exec();
}

sysInfoThread::~sysInfoThread()
{
    this->exit(0);
    this->deleteLater();
}

void sysInfoThread::getSystemInfo()
{
    qDebug()<<"ololol";
}


