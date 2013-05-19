#ifndef SYINFOTHREAD_H
#define SYINFOTHREAD_H

#include <QThread>
#include <QTimer>
#include <QLibrary>
#include <QDebug>
#include <QMutex>

class sysInfoThread : public QThread
{
    Q_OBJECT
private:
    QTimer* sysInfoTimer;
    QLibrary lgetinfo;
    QMutex mutex;

public:
    explicit sysInfoThread(QObject *parent = 0);
    void run();
    ~sysInfoThread();
public slots:
    void getSystemInfo();
};

#endif // SYINFOTHREAD_H
