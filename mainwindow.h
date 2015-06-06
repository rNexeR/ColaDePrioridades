#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <time.h>
#include <QDateTime>
#include <iostream>
using namespace std;

class Dato{
public:
    long tiempo;
    string tarea;

    Dato(long f, string t){
        tiempo = f;
        tarea = t;
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Dato *inicio;
    QDateTime actual;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
