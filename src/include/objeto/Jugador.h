#ifndef  JUGADOR_H
#define JUGADOR_H

#include "Objeto.h" 
#include <string>


class Jugador : public Objeto {
    private:
        int vida;
        int nivel;
        string nombre;
        int tiempoTotal;

    public:
        Jugador(int ataque, int x, int y, int z, int vida, int nivel, string nombre, int tiempoTotal);

        void atacar() override;
        void recibirAtaque(int ataque, string nombre);

        ~Jugador() override = default;
};


#endif