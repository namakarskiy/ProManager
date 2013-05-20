#include "processlistThread.h"

 processListThread::processListThread(QObject *parent) :
    QThread(parent)
{
    mutex.lock();
    procListTimer = new QTimer();
    connect(procListTimer,SIGNAL(timeout()),
            this,SLOT(getProcessList()),Qt::DirectConnection);
    qDebug()<<"processListThread started";
    mutex.unlock();

}

void processListThread::run()
{
    procListTimer->start(1235);
    exec();
}

processListThread::~processListThread()
{
   mutex.lock();
    this->exit(0);
   delete procListTimer;
    this->deleteLater();
   mutex.unlock();
}

void processListThread::getProcessList()
{
    mutex.lock();
    qDebug()<<"tutututu";

    mutex.unlock();
}