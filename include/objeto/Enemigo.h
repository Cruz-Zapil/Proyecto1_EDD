#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Objeto.h"
#include <string>

class Enemigo : public Objeto {
    private:
        int vida=30;
        int nivelAtaque=7;

    public:
        Enemigo();

        int ataqueEnemigo();
        void recibirAtaque(int ataque, string nombre);
        
        ~Enemigo() override = default;
};


#endif