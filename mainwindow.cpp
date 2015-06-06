#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cout<<QDateTime::currentDateTime().toString().toStdString()<<endl;
    //Cola.primero = new Dato(100, "Nada");
}

MainWindow::~MainWindow()
{
    delete ui;
}
