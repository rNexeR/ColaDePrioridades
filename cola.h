#ifndef COLA
#define COLA
#include "dato.h"

class Cola{
public:
    Cola();
    ~Cola();

    bool insert(QDateTime fecha, string desc);
    Dato* getInicio();
    bool posponerInicio(QDateTime fecha);

private:
    Dato* inicio;
    Dato* ultimo;

};



#endif // COLA

