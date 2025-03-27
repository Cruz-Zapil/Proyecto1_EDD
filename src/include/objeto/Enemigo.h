#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Objeto.h"
#include <string>

class Enemigo : public Objeto {
    private:
        int vida;

    public:
        Enemigo(int ataque, int x, int y, int z, int vida, int nivel);

        void atacar() override;
        void recibirAtaque(int ataque, string nombre);
        
        ~Enemigo() override = default;
};


#endif