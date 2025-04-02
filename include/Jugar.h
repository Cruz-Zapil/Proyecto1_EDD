#ifndef JUGAR_H
#define JUGAR_H

#include <iostream>
#include "Tablero.h"
#include "Objeto.h"



using namespace std;

class Jugar
{

    private:

      Tablero<Objeto*> tablero3D;
      int tamanioTablero;
      int cantObjetos;




    public:

      void crearTablero();
      void crearObjetos();
      void crearPersonajes();
      void ingresarObjetosAlMundo();
      void jugar();


};



#endif