#ifndef PROCESSLIST_H
#define PROCESSLIST_H
#include <QThread>
#include <QTimer>
#include <QLibrary>
#include <QDebug>
#include <QMutex>
class processList : public QThread
{
    Q_OBJECT
private:
    QTimer* procListTimer;
    QLibrary lproc;
    QMutex mutex;

public:
    explicit processList(QObject *parent = 0);
    void run();
    ~processList();
public slots:
    void getProcessList();
};

#endif // PROCESSLIST_H
