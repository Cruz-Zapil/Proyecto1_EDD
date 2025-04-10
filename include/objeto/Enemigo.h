#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Objeto.h"
#include <string>
#include "Util.h"

class Enemigo : public Objeto {
    private:
        int vida;
        int nivelAtaque;


    public:
        Util util;
        Enemigo()
          : Objeto("Enemigo"),
          vida(util.aleatorio_en_rango(6,15)),
          nivelAtaque(util.aleatorio_en_rango(6,10)){};


        int ataqueEnemigo(){
        return nivelAtaque;
        };

        void recibirAtaque(int ataque){

            vida -= ataque;
            cout<<endl;
            util.colorVerde("_____________________________________");
            util.colorVerdeJ("¡El jugador ha lanzado un ataque de " + to_string(ataque) );
            cout << endl;
            util.colorVerde("puntos! ➤ Vida reducida.");
            util.colorRojo ("💚 vida:  "+ to_string(vida));
            util.colorRojo ("_____________________________________");
        };

        int getVida(){return vida;};
    void enemyInactivo() {

            util.colorRojo("_____________________________________");
            util.colorRojo(" Perdio la batalla contra el Jugador ");
            util.colorRojo("_____________________________________");

    }

    int getClaveUbicacion() {
        // Normal para enemigos: XYZ → 153
        return posicionX * 100 + posicionY * 10 + posicionZ;
    }



        bool getActivo() const { return vida > 0; }
        
        ~Enemigo() override = default;
};


#endif