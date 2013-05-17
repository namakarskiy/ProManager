#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QStringList header;
    header<<"pid"<<"name"<<"state"<<"ppid"<<"nice"<<"size";//<<"ram"<<"swap"<<"ololo";
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(6);
    ui->treeWidget->setHeaderLabels(header);


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
    //ui->treeWidget->s;
}

MainWindow::~MainWindow()
{
    delete ui;
}
