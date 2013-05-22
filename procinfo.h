#ifndef PROCINFO_H
#define PROCINFO_H
#include <QList>
#include <QString>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <QDebug>
#include <fstream>
#include <QList>
#include "string.h"
#include <iostream>

#include <unistd.h>
#include <QObject>

char* AbsolutePath(char *path);
bool dirIsDigit(char * name);

struct Process
{
    int pid;
    char name[20];
    char state;
    int ppid;
    int pgrp;
    int size;
    int resident;
    int share;
    int lrs;
};


class ProcInfo : public QObject
{
    Q_OBJECT
public:
    explicit ProcInfo(QObject *parent = 0);
    void getProcessList();
    ~ProcInfo();
    
signals:
    void sendProcessList(QList<Process>*);
    
public slots:
    
};

#endif // PROCINFO_H
