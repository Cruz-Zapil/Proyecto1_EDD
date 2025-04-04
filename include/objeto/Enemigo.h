#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Objeto.h"
#include <string>

class Enemigo : public Objeto {
    private:
        int vida;
        int nivelAtaque;

    public:
        Enemigo()
          : Objeto("Enemigo"),
          vida(3),
          nivelAtaque(7){};


        int ataqueEnemigo(){
        return nivelAtaque;
        };

        void recibirAtaque(int ataque, string nombre){

            vida -= ataque;
            cout << "El enemigo  ha recibido un ataque de" << ataque << endl;
        };

        int getVida(){return vida;};
        
        ~Enemigo() override = default;
};


#endif