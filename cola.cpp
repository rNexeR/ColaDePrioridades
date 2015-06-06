#include "cola.h"

Cola::Cola(){

}

Cola::~Cola(){

}

bool Cola::insert(QDateTime fecha, string desc){
    QDateTime actual = new QDateTime(QDateTime::currentDateTime());
    actual.addMSecs(-2000);
    if(fecha < actual)
        return false;
    else{

    }
    return false;
}

Dato* Cola::getInicio(){
    return inicio;
}

bool Cola::posponerInicio(QDateTime fecha){
    return false;
}
