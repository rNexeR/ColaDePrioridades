#ifndef DATO
#define DATO
#include <iostream>
#include <QDateTime>
using namespace std;

class Dato{
public:
    qint64 tiempo;
    string tarea;
    Dato* anterior;

    Dato(qint64 f, string t){
        tiempo = f;
        tarea = t;
        anterior = NULL;
    }
};

#endif // DATO

