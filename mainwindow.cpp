#include "mainwindow.h"
#include "ui_mainwindow.h"


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

    connect(ui->treeWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
            this,SLOT(actionWithProcess(QTreeWidgetItem*,int)));

    connect(ui->btnBack,SIGNAL(clicked()),
            this,SLOT(btnBackClicked()));

    ui->treeWidget->setColumnWidth(0,75);
    ui->treeWidget->setColumnWidth(1,175);
  mutex.unlock();

}

MainWindow::~MainWindow()
{
    mutex.lock();

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
    ui->ram_total->setText(QString::number(t.totalram));
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

void MainWindow::actionWithProcess(QTreeWidgetItem *item, int)
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->pid_value->setText(item->text(0));
    ui->name_value->setText(item->text(1));
    ui->state_value->setText(item->text(2));
    ui->ppid_value->setText(item->text(3));
    ui->pgrp_value->setText(item->text(4));
    ui->size_value->setText(item->text(5));
    ui->resident_value->setText(item->text(6));
    ui->share_value->setText(item->text(7));
    ui->lrs_value->setText(item->text(8));
    qDebug()<<"I`m clicked";
    qDebug()<<item->text(0);
}

void MainWindow::btnBackClicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




