#ifndef  JUGADOR_H
#define JUGADOR_H

#include "Objeto.h" 
#include <string>
#include "Util.h"

using namespace std;

class Jugador : public Objeto {
private:

    string nombre;
    int vida;
    int tiempoTotal;
    int puntos;
    int nivelAtaque;
    Util util;

public:

    Jugador(string nombre)
      : Objeto("Jugador"),
        nombre(nombre),
        vida(30),
        tiempoTotal(0),
        puntos(0),
        nivelAtaque(5){};


    void recibirAtaque(int ataque, string atacante) {
        vida -= ataque;
        cout<<endl;
        util.colorRojo("_____________________________________");
        util.colorRojoA("¡" + atacante + " ha lanzado un ataque de " + to_string(ataque) );
        cout << endl;
        util.colorRojo("puntos! ➤ Vida reducida.");
        util.colorVerde("💚 vida:  "+ to_string(vida));
        util.colorRojo("_____________________________________");
    }

    int ataqueJugador(){
        return nivelAtaque;

    };

    void recibirVidaExtra(int extra) {
        vida += extra;
        cout<<endl;
        util.colorVerde("_____________________________________");
        util.colorVerdeJ("💚 ¡Has encontrado una pócima! +");
        cout << extra << " " << endl;
        util.colorVerde("puntos de vida. ➤ Salud restaurada.");
        util.colorVerde("_____________________________________");

    }



    // Métodos adicionales
    string getNombre() const { return nombre; }
    int getVida() const { return vida; }


    bool getActivo() const { return vida >0; }

    void jugadorInactivo() {
        util.colorRojo("_____________________________________");
        util.colorRojo(" Perdio la batalla contra el Enemigo ");
        util.colorRojo("_____________________________________");
    }
        ~Jugador() override = default;

};


#endif