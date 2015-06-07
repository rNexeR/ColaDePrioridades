#include "cola.h"

Cola::Cola(){
    inicio = NULL;
    ultimo = NULL;
}

Cola::~Cola(){

}

/**
 * @brief Cola::insert - Inserta en la cola las tareas que sean después de la fecha actual y en el orden de fechas
 * @param fecha - QDateTime de la fecha determinada
 * @param desc - Descripción de la tarea
 * @return - True si la tarea se pudo ingresar (si la fecha no es antes de la fecha actual)
 */
bool Cola::insert(QDateTime fecha, string desc){
    QDateTime actual = QDateTime::currentDateTime();
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

/**
 * @brief Cola::getInicio - Obtiene el inicio actual
 * @return - Dato* del inicio
 */
Dato* Cola::getInicio(){
    return inicio;
}

/**
 * @brief Cola::quitarDeCola - Elimina el primer objeto de la cola de tareas
 * @return true si se logró eliminar
 */
bool Cola::quitar(){
    Dato* temp;
    if(inicio){
        temp = inicio;
        inicio = inicio->anterior;
        delete temp;
        return true;
    }

    return false;
}

/**
 * @brief Cola::posponerInicio - Extrae el inicio y lo inserta de nuevo con una nueva fecha
 * @param fecha - La fecha nueva del inicio actual
 * @return true si se logró posponer
 */
bool Cola::posponerInicio(QDateTime fecha){
    Dato* actual = inicio;

    QDateTime tiempo = QDateTime::fromMSecsSinceEpoch(actual->tiempo);
    if(fecha < tiempo)
        return false;

    string tarea = actual->tarea;
    quitar();

    return insert(fecha, tarea);
}
