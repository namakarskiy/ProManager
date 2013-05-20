#ifndef PROCESSESINFO_H
#define PROCESSESINFO_H
#include <QList>
#include <QString>

struct Process
{
    int pid;
    QString name;
    char state;
    int ppid;
    int nice;
    int size;
};

class ProcessesInfo
{
private:
    QList<Process>* list;
public:
    ProcessesInfo();
    QList<Process>* getProcessList();
    ~ProcessesInfo();
};

#endif // PROCESSESINFO_H
