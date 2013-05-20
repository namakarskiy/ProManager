#ifndef PROCESSLIST_H
#define PROCESSLIST_H
#include "ThreadsConfig.h"
#include "processesinfo.h"


class processListThread : public QThread
{
    Q_OBJECT
private:
    QTimer* procListTimer;
    QMutex mutex;

public:
    explicit processListThread(QObject *parent = 0);
    void run();
    ~processListThread();
public slots:
    void getProcessList();
};

#endif // PROCESSLIST_H
