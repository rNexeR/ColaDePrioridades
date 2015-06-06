#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cout<<QDate::currentDate().toString().toStdString()<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
