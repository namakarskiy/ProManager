#include "systeminfo.h"

SystemInfo::SystemInfo(QObject *parent):
    QObject(parent)
{

}

void SystemInfo::getSystemInfo()
{
    struct sysinfo s1;
    sysinfo(&s1);
    SystemInformation send;
    send.freeram = s1.freeram*s1.mem_unit/1024;
    send.totalram = s1.totalram*s1.mem_unit/1024;
    send.usedram = (s1.totalram-s1.freeram)*s1.mem_unit/1024;
    send.freeswap = s1.freeswap*s1.mem_unit/1024;
    send.totalswap = s1.totalswap*s1.mem_unit/1024;
    send.usedswap = (s1.totalswap-s1.freeswap)*s1.mem_unit/1024;
    send.uptime =  s1.uptime/60;
    send.page = s1.mem_unit;
    emit sendSystemInfo(send);
    emit sendUsedRam(send.usedram);
}

void SystemInfo::getOtherInfo()
{

}

SystemInfo::~SystemInfo()
{
}
