#ifndef JUGAR_H
#define JUGAR_H

#include <CargarRegistro.h>

#include "ArbolEnemy.h"
#include "Tablero.h"
#include "Objeto.h"
#include "Tesoro.h"
#include "Util.h"
#include "ArbolTrampa.h"
#include <chrono>

#include "ArbolPista.h"
using namespace std::chrono;


using namespace std;

class Jugar {

    // cronometro:
    time_point<high_resolution_clock> inicioPartida;

    Tablero<Objeto> *tablero3D = nullptr; //  Puntero que puedes inicializar después
    NodoCasilla<Objeto>* destino = nullptr;
    ArbolTrampa arbolTrampa = ArbolTrampa();
    ArbolEnemy arbolEnemy = ArbolEnemy();
    ArbolPista arbolPista = ArbolPista();
    Util util;
    string nombreJugador;
    bool tesoroEncontrado = false;
    int tamanioFijo = 2;
    int numeroNodos;
    int cantObjetos;
    int fila, columna, altura;
    int tesoroX, tesoroY, tesoroZ;
    int cantMovimiento=0;
    Jugador* jugador;
    Tesoro tesoro;

    /// registro :
    CargarRegistro registros;

public:
    void iniciarJuego();

    void crearTablero(int x, int y, int z);

    void crearPersonaje();

    void crearTesoro();

    void crearPista();

    void crearObjetos();

    bool colocarObjetoEnTablero(Objeto *obj);

    void jugar();

    void moverJugador(string direccion);

    void guardarRegistro();

    void iniciarBatalla(Objeto *obj);

    void manejarTrampa(Objeto *obj);

    void manejarPocima(Objeto *obj);

    void manejarPista(Objeto *obj);

    void actualizarPosicion();

    void iniciarCronometro() {
        inicioPartida = high_resolution_clock::now();
    }

    void finalizarCronometro() {
        auto finPartida = high_resolution_clock::now();
        auto duracion = duration_cast<seconds>(finPartida - inicioPartida);
        cout << "⏱️ Tiempo total de partida: " << duracion.count() << " segundos" << endl;
    }
};



#endif
