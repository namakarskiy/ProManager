#include "processlist.h"

processList::processList(QObject *parent) :
    QThread(parent)
{
    mutex.lock();
    procListTimer = new QTimer();
    connect(procListTimer,SIGNAL(timeout()),
            this,SLOT(getProcessList()),Qt::DirectConnection);
    qDebug()<<"proclist thread started";
    mutex.unlock();

}

void processList::run()
{
    procListTimer->start(1235);
    exec();
}

processList::~processList()
{
   mutex.lock();
    this->exit(0);
   delete procListTimer;
    this->deleteLater();
   mutex.unlock();
}

void processList::getProcessList()
{
    mutex.lock();
    qDebug()<<"tutututu";

    mutex.unlock();
}
