#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <linux/sysinfo.h>
#include <sys/sysinfo.h>
#include <QDebug>

struct SystemInformation
{
    int freeram;
    int totalram;
    int usedram;
    int freeswap;
    int usedswap;
    int totalswap;
    int uptime;
    int page;
};


class SystemInfo: public QObject
{
    Q_OBJECT
private:

public:
    explicit SystemInfo(QObject* parent=0);
    void getSystemInfo();
    void getOtherInfo();
    ~SystemInfo();
signals:
    void sendSystemInfo(SystemInformation);
    void sendUsedRam(int);
};

#endif // SYSTEMINFO_H
