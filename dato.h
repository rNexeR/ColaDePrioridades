#ifndef DATO
#define DATO
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

#endif // DATO

