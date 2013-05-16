#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>



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
    Ui::MainWindow *ui;
    QTimer* sysInfoTimer;
    QTimer* ProcessListTimer;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    

};

#endif // MAINWINDOW_H
