
#ifndef TESORO_H
#define TESORO_H

#include "Objeto.h"

class Tesoro  : public Objeto {

    private:

        int oro=100;


    public:

    Tesoro();
        int oroTesoro();
        void descripcion();
    ~Tesoro() override = default;

};



#endif
