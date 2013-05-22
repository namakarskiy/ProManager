#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "realtimeplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  mutex.lock();
    QStringList header;
    header<<"pid"<<"name"<<"state"<<"ppid"<<"pgrp"<<"size,KiB"<<"resident,KiB"<<"share,KiB"<<"lrs,KiB";
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(9);
    ui->treeWidget->setHeaderLabels(header);
  ////////
    RealTimePlot* ram = new RealTimePlot(); //создаем график для рисования загрузки оп. памяти
    ui->ram_layout->addWidget(ram);
    connect(this,SIGNAL(sendUsedRam(int)),
            ram,SLOT(getData(int)));
  ////////
  ////////
    RealTimePlot* swap = new RealTimePlot(); //создаем график для рисования загрузки своп раздела
    ui->swap_layout->addWidget(swap);
    connect(this,SIGNAL(sendUsedSwap(int)),
            swap,SLOT(getData(int)));
  ////////

    ui->treeWidget->setColumnWidth(0,75);
    ui->treeWidget->setColumnWidth(1,175);
   // ui->treeWidget->setSortingEnabled(true);
    mutex.unlock();

}

MainWindow::~MainWindow()
{
    mutex.lock();
    delete ram;
    delete swap;
    delete ui;
    mutex.unlock();
}

void MainWindow::acceptSystemInfo(SystemInformation t)
{
    mutex.lock();
    ui->swap_free->setText(QString::number(t.freeswap));
    ui->swap_used->setText(QString::number(t.usedswap));
    ui->swap_total->setText(QString::number(t.totalswap));
    ui->ram_free->setText(QString::number(t.freeram));
    ui->ram_used->setText(QString::number(t.usedram));
    ui->ram_total->setText(QString::number(t.totalswap));
    emit sendUsedRam(t.usedram);
    emit sendUsedSwap(t.usedswap);
    mutex.unlock();
}

void MainWindow::acceptProcessList(QList<Process> *list)
{
    if(ui->treeWidget->selectedItems().count() == 0)
    {
        int i=0;
        ui->treeWidget->clear();
        qDebug()<<ui->treeWidget->selectedItems().count();
        QTreeWidgetItem *item=0;
        while(i<list->count())
        {
            item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0,QString::number(list->at(i).pid));

            QString tmp;
            tmp = list->at(i).name;
            tmp.remove(QRegExp("[()]"));
            item->setText(1,tmp);

            tmp.clear();
            tmp+=list->at(i).state;
            item->setText(2,tmp);
            item->setText(3,QString::number(list->at(i).ppid));
            item->setText(4,QString::number(list->at(i).pgrp));
            item->setText(5,QString::number(list->at(i).size*4096/1024));
            item->setText(6,QString::number(list->at(i).resident*4096/1024));
            item->setText(7,QString::number(list->at(i).share*4096/1024));
            item->setText(8,QString::number(list->at(i).lrs*4096/1024));
            i++;
        }
    }
    else qDebug()<<"item selected";
}




