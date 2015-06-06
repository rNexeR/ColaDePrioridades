#ifndef COLA
#define COLA
#include "dato.h"
#include <QDateTime>

class Cola{
public:
    Dato* inicio;
    Cola(){

    }
    ~Cola(){

    }
    bool insert(QDateTime fecha, string desc){
        return false;
    }
    Dato* getInicio(){
        return inicio;
    }
    bool posponerInicio(QDateTime fecha){
        return false;
    }
    string returnInicio(){
        return "";
    }
};



#endif // COLA

