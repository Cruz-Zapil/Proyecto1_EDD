#ifndef JUGAR_H
#define JUGAR_H

#include "Tablero.h"
#include "Objeto.h"
#include "Tesoro.h"
#include "Util.h"


using namespace std;

class Jugar{

      Tablero<Objeto>* tablero3D = nullptr; //  Puntero que puedes inicializar después

      Util util;
      int tamanioFijo=2;
      int numeroNodos ;
      int cantObjetos;
      int fila, columna, altura;
      int tesoroX, tesoroY, tesoroZ;
      Objeto* jugador;
      Tesoro tesoro;



    public:
      void iniciarJuego();
      void crearTablero(int x, int y, int z);
      void crearPersonaje();
      void crearTesoro();
      void crearPista();
      void crearObjetos();

      void moverPersonaje();
      void jugar();
      void registro();
      bool colocarObjetoEnTablero(Objeto* obj);


};



#endif