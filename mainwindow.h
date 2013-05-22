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




#define PID_COLUMN 0
#define NAME_COLUMN 1
#define STATE_COLUMN 2
#define PPID_COLUMN 3
#define NICE_COLUMN 4
#define SIZE_COLUMN 5


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QMutex mutex;
    
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
signals:
    void sendUsedRam(int);
    void sendUsedSwap(int);

};

#endif // MAINWINDOW_H
