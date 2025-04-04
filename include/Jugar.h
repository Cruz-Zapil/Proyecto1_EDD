#ifndef JUGAR_H
#define JUGAR_H

#include "Tablero.h"
#include "Objeto.h"
#include "Tesoro.h"
#include "Util.h"


using namespace std;

class Jugar{


      Tablero<Objeto*>* tablero3D = nullptr; //  Puntero que puedes inicializar después

      Util util;
      int tamanioFijo=2;
      int numeroNodos ;
      int cantObjetos;
      int fila, columna, altura;
      Objeto* jugador;
      Tesoro tesoro;



    public:
      void iniciarJuego();
      void crearTablero(int x, int y, int z);
      void crearPersonaje();
      void crearObjetos();
      void crearTesoro();
      void moverPersonaje();
      void jugar();
      void registro();


};



#endif