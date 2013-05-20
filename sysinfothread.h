#ifndef SYINFOTHREAD_H
#define SYINFOTHREAD_H

#include "ThreadsConfig.h"
#include "systeminfo.h"

class sysInfoThread : public QThread
{
    Q_OBJECT
private:
    QTimer* sysInfoTimer;
    QMutex mutex;
 public:
    SystemInfo *inf;

public:
    explicit sysInfoThread(QObject *parent = 0);
    void run();
    ~sysInfoThread();
public slots:
    void getSystemInfo();
};

#endif // SYINFOTHREAD_H
