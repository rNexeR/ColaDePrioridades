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

void MainWindow::updateProxima(){
    if(!tareas.getInicio()){
        ui->fecha->clear();
        ui->nombre->clear();
        return;
    }
    ui->fecha->setDateTime(QDateTime::fromMSecsSinceEpoch(tareas.getInicio()->tiempo));
    ui->nombre->setText(QString::fromStdString(tareas.getInicio()->tarea));
}

void MainWindow::on_pushButton_clicked()//crear
{
    QDateTime fecha = ui->txtfecha->dateTime();
    string nombre = ui->txtnombre->text().toStdString();
    if(nombre != "" && fecha > QDateTime::currentDateTime()){
        tareas.insert(fecha, nombre);
        updateProxima();
    }
}

void MainWindow::on_pushButton_2_clicked()//posponer
{
    if(!tareas.getInicio())
        return;
    QDateTime fecha = ui->fechanueva->dateTime();
    if(fecha > QDateTime::currentDateTime()){
        tareas.posponerInicio(fecha);
        updateProxima();
    }
}

void MainWindow::on_pushButton_3_clicked()//cumplida
{
    if(!tareas.getInicio())
        return;
    tareas.quitar();
    updateProxima();
}
