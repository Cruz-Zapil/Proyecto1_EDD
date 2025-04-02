#ifndef  JUGADOR_H
#define JUGADOR_H

#include "Objeto.h" 
#include <string>

using namespace std;

class Jugador : public Objeto {

    private:

        string nombre;
        int vida;
        int tiempoTotal;
        int puntos;
        int nivelAtaque;

    public:

        Jugador(string nombre, int posX, int posY, int posZ)
          : Objeto("Jugador", posX, posY, posZ),
            nombre(nombre),
            vida(30),
            tiempoTotal(0),
            puntos(0),
            nivelAtaque(5){};


        void recibirAtaque(int ataque, string atacante){
          vida -= ataque;
          cout << "El jugador " << this->nombre << " ha recibido un ataque de " << ataque<<" del"<< atacante
               << " puntos de vida" << endl;


        };
        int ataqueJugador(){
            return nivelAtaque;

        };
        void recibirVidaExtra(int vida){

          vida += vida;
          cout << "El jugador " << this->nombre << " ha recibido " << vida << " puntos de vida" << endl;

        };

    // Implementación de métodos virtuales de Objeto
        string posicion()  {
        return "Jugador " + nombre + " en (" +
               to_string(posX) + "," +
               to_string(posY) + "," +
               to_string(posZ) + ")";
    }

    // Métodos adicionales
    string getNombre() const { return nombre; }
    int getVida() const { return vida; }


        ~Jugador() override = default;
};


#endif