#include "procinfo.h"

ProcInfo::ProcInfo(QObject *parent) :
    QObject(parent)
{
}




void ProcInfo::getProcessList()
{
    QList<Process> list;
    dirent *dirInfo;
    DIR *processDir;

    list.begin();
    processDir = opendir("/proc/");
    while((dirInfo = readdir(processDir)) != NULL)
       {
            if(dirIsDigit(dirInfo->d_name))
            {
                char* path;
                Process tmp;
                path = AbsolutePath(dirInfo->d_name);
                chdir(path);
                delete [] path;
                std::ifstream statFile;
                statFile.open("stat");
                if(!statFile)
                {
                    qDebug()<<"not1";
                }
                statFile>>tmp.pid>>tmp.name>>tmp.state>>tmp.ppid>>tmp.pgrp;

                statFile.close();

                std::ifstream statmFile("statm");
                if (!statmFile)
                {

                }
                int garbage;
                statmFile>>tmp.size>>tmp.resident>>tmp.share>>garbage
                         >>garbage>>tmp.lrs;//все поля которые содержат информацию о памяти, измеряются в страницач(4096 байт)

                statmFile.close();
                list.append(tmp);
           }
        }
    emit sendProcessList(&list);
}

ProcInfo::~ProcInfo()
{
}


char* AbsolutePath(char *path)
{
    char* absPath;
    absPath = new char [(strlen(path)+strlen("/proc/")+2)]; //+2 because we add / in the end of  the string ad \0
    strcpy(absPath,"/proc/");
    strcat(absPath,path);
    absPath[(strlen(path)+strlen("/proc/"))]='/';
    absPath[(strlen(path)+strlen("/proc/")+1)]='\0';
    return absPath;
}

bool dirIsDigit(char * name)
{
    unsigned int i=0;
    for(i=0;i<strlen(name);i++)
    {
        if(isdigit(name[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

