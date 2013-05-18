#ifndef SYINFOTHREAD_H
#define SYINFOTHREAD_H

#include <QThread>
#include <QTimer>
#include <QLibrary>
#include <QDebug>
class sysInfoThread : public QThread
{
    Q_OBJECT
private:
    QTimer* sysInfoTimer;
    QLibrary lgetinfo;

public:
    explicit sysInfoThread(QObject *parent = 0);
    void run();
    ~sysInfoThread();

signals:
    
public slots:
    void getSystemInfo();

    
};

#endif // SYINFOTHREAD_H
