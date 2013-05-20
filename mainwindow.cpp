#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "realtimeplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QStringList header;
    QLayout* tmp;
    header<<"pid"<<"name"<<"state"<<"ppid"<<"nice"<<"size";
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(6);
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

    ui->treeWidget->setColumnWidth(0,50);
    ui->treeWidget->setColumnWidth(1,200);
    ui->treeWidget->setSortingEnabled(true);
    QTreeWidgetItem *item=0;
    for(int i=0;i<10;i++)
    {
        item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0,QString::number(i));
        item->setText(1,"qwed"+QString::number(i));
        ui->treeWidget->setItemExpanded(item,true);
    }
}

MainWindow::~MainWindow()
{
    delete ram;
    delete swap;
    delete ui;
}

void MainWindow::acceptSystemInfo(SystemInformation t)
{
    ui->swap_free->setText(QString::number(t.freeswap));
    ui->swap_used->setText(QString::number(t.usedswap));
    ui->swap_total->setText(QString::number(t.totalswap));
    ui->ram_free->setText(QString::number(t.freeram));
    ui->ram_used->setText(QString::number(t.usedram));
    ui->ram_total->setText(QString::number(t.totalswap));
    emit sendUsedRam(t.usedram);
    emit sendUsedSwap(t.usedswap);
}




