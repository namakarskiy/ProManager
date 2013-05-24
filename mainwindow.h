#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include "sysinfothread.h"
#include "processlistThread.h"
#include "systeminfo.h"
#include "procinfo.h"
#include <linux/sysinfo.h>
#include <sys/sysinfo.h>
#include <QTreeWidgetItem>
#include <QMutex>
#include <QDialog>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <cstring>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QMutex mutex;
    QDialog error;
    
public:
    Ui::MainWindow *ui;

private:



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void acceptSystemInfo(SystemInformation);
    void acceptProcessList(QList<Process>*);
    void actionWithProcess(QTreeWidgetItem*,int);
    void btnBackClicked();
    void btnKillClicked();
    void btnTerminateClicked();
signals:
    void sendUsedRam(int);
    void sendUsedSwap(int);

};

#endif // MAINWINDOW_H
