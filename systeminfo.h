#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H
struct Sys
{
  int i;
};


class SystemInfo
{
private:
    Sys sysInf;

public:
    SystemInfo();
    Sys getSystemInfo();
    ~SystemInfo();

};

#endif // SYSTEMINFO_H
