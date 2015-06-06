#include "cola.h"

Cola::Cola(){
    inicio = NULL;
    ultimo = NULL;
}

Cola::~Cola(){

}

bool Cola::insert(QDateTime fecha, string desc){
    QDateTime actual = new QDateTime(QDateTime::currentDateTime());
    actual.addMSecs(-2000);
    if(fecha <= actual)
        return false;
    else{
        Dato* nuovo = new Dato(fecha.toMSecsSinceEpoch(), desc);
        if(!inicio){
            inicio = nuovo;
            return true;
        }

        if(nuovo->tiempo < inicio->tiempo){//si la fecha es mayor (después) al inicio actual
            nuovo->anterior = inicio;
            inicio = nuovo;
            return true;
        }

        Dato* temp = inicio;
        while(temp->anterior && temp->anterior->tiempo <= nuovo->tiempo)//si el tiempo actual sucede antes que el nuevo
            temp = temp->anterior;

        nuovo->anterior = temp->anterior;
        temp->anterior = nuovo;

        return true;
    }
}

Dato* Cola::getInicio(){
    return inicio;
}

bool Cola::posponerInicio(QDateTime fecha){
    return false;
}
