
#ifndef TESORO_H
#define TESORO_H

#include "Objeto.h"

class Tesoro  : public Objeto {

private:

    int oro;


public:


    Tesoro()
        : Objeto ("Tesoro"),
    oro(100){};

    int oroTesoro() {
        return oro;
    };
    void descripcion();

    ~Tesoro() override = default;

};



#endif
