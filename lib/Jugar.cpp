#include <iostream>
#include <fstream>
#include <limits>
#include <chrono>

#include "Jugar.h"
#include "Trampa.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Pista.h"
#include "Pocima.h"

using namespace std;
using namespace std::chrono;


/// complejidad:
/// complejidad iniciar Juego:
/// peor de lo casos: O(n²)
/// mejor de los casos: O(n)
///
void Jugar::iniciarJuego() {
    // iniciar tiempo
    iniciarCronometro();
    util.colorVerde(" Ingrese su nombre: ");
    cin >> nombreJugador;
    jugador = new Jugador(nombreJugador);

    util.colorMagenta("Ingrese el tamaño del Mundo");
    cin >> fila >> columna >> altura;
    // Manejo de error por entrada no numérica
    if (cin.fail() || fila < 2 || columna < 2 || altura < 2) {
        cin.clear(); // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        numeroNodos = tamanioFijo * tamanioFijo * tamanioFijo;
        crearTablero(tamanioFijo, tamanioFijo, tamanioFijo);
    } else {
        numeroNodos = fila * columna * altura;
        crearTablero(fila, columna, altura);
    }

    /// mas metodos:
    crearPersonaje();
    crearTesoro();
    crearPista();
    crearObjetos();
    tablero3D->imprimirTablero2D(jugador->getPosZ());
    jugar();
}

void Jugar::crearTablero(int fila, int columna, int altura) {
    if (tablero3D != nullptr) {
        delete tablero3D;
    }
    /// crear tablero
    tablero3D = new Tablero<Objeto>(fila, columna, altura);
}

void Jugar::crearPersonaje() {
    if (!colocarObjetoEnTablero(jugador)) {
        delete jugador; // liberar memoria
    }
}

void Jugar::crearTesoro() {
    Objeto *tesoro = new Tesoro();
    if (!colocarObjetoEnTablero(tesoro)) {
        delete tesoro; // liberar puntero
    }
}

void Jugar::crearPista() {
    int cantidad = numeroNodos / 8;
    for (int i = 0; i < cantidad; i++) {
        Objeto *pista = new Pista();
        if (!colocarObjetoEnTablero(pista)) {
            delete pista; // Liberar puntero
        }
    }
}

void Jugar::crearObjetos() {
    int cantidad = numeroNodos / 8;

    for (int i = 0; i < cantidad; i++) {
        // Enemigo
        Objeto *enemigo = new Enemigo();
        if (!colocarObjetoEnTablero(enemigo)) {
            delete enemigo;
        }

        // Trampa
        Objeto *trampa = new Trampa();
        if (!colocarObjetoEnTablero(trampa)) {
            delete trampa;
        }
        // Pócima
        Objeto *pocima = new Pocima();
        if (!colocarObjetoEnTablero(pocima)) {
            delete pocima;
        }
    }
}

/// complejidad:
/// complejidad insertar:
/// peor de lo casos: O(n)
/// mejor de los casos: O(n)
///
bool Jugar::colocarObjetoEnTablero(Objeto *obj) {
    int intentos = 0;
    int intentosFijos = numeroNodos / 8;
    bool colocado = false;
    while (!colocado && intentos < intentosFijos) {
        int x = util.aleatorio_en_rango(0, fila - 1);
        int y = util.aleatorio_en_rango(0, columna - 1);
        int z = util.aleatorio_en_rango(0, altura - 1);
        colocado = tablero3D->setObjeto(x, y, z, obj);

        if (colocado) {
            // chequeamos que tipo de objeto es:
            // si es tesoro guradamos su posicion
            Tesoro *t = dynamic_cast<Tesoro *>(obj);
            if (t != nullptr) {
                tesoroX = x;
                tesoroY = y;
                tesoroZ = z;
            }

            // si es personaje
            Jugador *jugador = dynamic_cast<Jugador *>(obj);

            if (jugador != nullptr) {
                cout << "Jugador creado en (" << x << ", " << y << ", " << z << ")\n";
            }

            // si es pista
            // le colocamos la pista depende de la distancia
            Pista *pista = dynamic_cast<Pista *>(obj);
            if (pista != nullptr) {
                int distancia = abs(x - tesoroX) + abs(y - tesoroY) + abs(z - tesoroZ);
                if (distancia == 1) {
                    pista->setPista("Caliente");
                } else if (distancia <= 2) {
                    pista->setPista("Tibio");
                } else {
                    pista->setPista("Frío");
                }
            }
            obj->setPosicion(x, y, z);
        } else {
            ++intentos;
        }
    }
    return colocado;
}


/// complejidad:
/// complejidad insertar:
/// peor de lo casos: O(n)
/// mejor de los casos: O(1)
///
void Jugar::jugar() {
    bool vida = false;

    do {
        string direccion;
        util.colorMagenta("___________________________________");
        util.colorMagenta("_____  Ingrese una dirección  _____");
        util.colorCyan(" a(←), s(↓), d(→), w(↑), q(↑), e(↓)");
        util.colorMagenta("___________________________________");
        cin >> direccion;

        moverJugador(direccion);
        vida = jugador->getActivo();
    } while (vida && !tesoroEncontrado);

    guardarRegistro();
}

/// complejidad:
/// complejidad insertar:
/// peor de lo casos: O(n)
/// mejor de los casos: O(1)
///

void Jugar::moverJugador(string direccion) {
    destino = tablero3D->casillaSiguiente(jugador, direccion);

    if (destino != nullptr) {
        if (destino->ocupado) {
            Objeto *objDestino = destino->contenido;

            // Verificar el tipo de objeto en la casilla destino
            if (dynamic_cast<Enemigo *>(objDestino)) {
                iniciarBatalla(dynamic_cast<Enemigo *>(objDestino));
            } else if (dynamic_cast<Trampa *>(objDestino)) {
                manejarTrampa(dynamic_cast<Trampa *>(objDestino));
            } else if (dynamic_cast<Pocima *>(objDestino)) {
                manejarPocima(dynamic_cast<Pocima *>(objDestino));
            } else if (dynamic_cast<Pista *>(objDestino)) {
                manejarPista(dynamic_cast<Pista *>(objDestino));
            } else if (dynamic_cast<Tesoro *>(objDestino)) {
                tesoroEncontrado = true;
                jugador->tesoroEncontrado();

            } else {
                util.colorRojo("Movimiento inválido: la casilla está ocupada por un objeto desconocido.");
            }
        } else {
            actualizarPosicion();
        }
    } else {
        cout << "Movimiento fallido: fuera de los límites o dirección inválida." << endl;
    }
}

/// complejidad:
/// complejidad insertar:
/// peor de lo casos: O(n)
/// mejor de los casos: O(1)
///

void Jugar::iniciarBatalla(Objeto *obj) {
    Enemigo *enemigo = dynamic_cast<Enemigo *>(obj);

    cout << endl;
    util.colorRojo("___________________________________");
    util.colorRojo("__ 🧟 Inicia batalla con un Enemigo _");
    arbolEnemy.insertar(enemigo);
    util.colorRojo("___________________________________");

    do {
        bool vidaJugador = jugador->getActivo();
        bool vidaEnemy = enemigo->getActivo();

        // el enemigo ataca
        if (vidaEnemy) {
            jugador->recibirAtaque(enemigo->ataqueEnemigo(), " Enemigo ");
        }

        // el jugador ataca
        vidaJugador = jugador->getActivo(); // Actualizamos después del ataque enemigo
        if (vidaJugador) {
            enemigo->recibirAtaque(enemigo->ataqueEnemigo());
        } else {
            jugador->jugadorInactivo();
            cout << endl << endl;
            util.colorRojo("_________________________________");
            util.colorRojo("________ JUEGO TERMINADO ________");
            util.colorRojo("___________   PERDIO  ___________");
            util.colorRojo("_________________________________");

            break; // la batalla termina si perdemos
        }

        // hay que chequear si el enemigo perdio
        vidaEnemy = enemigo->getActivo();
        if (!vidaEnemy) {
            enemigo->enemyInactivo();
            actualizarPosicion();
            break;
        }
    } while (true);
}


void Jugar::manejarPista(Objeto *obj){
    Pista *pista = dynamic_cast<Pista *>(obj);
    cout << endl << endl;
    util.colorVerde("___________________________________");
    util.colorVerde("______   Encontro una pista  ______");
    util.colorVerde("___________________________________");
    pista->getPista();
    arbolPista.insertar(pista);
    util.colorVerde("___________________________________");
    actualizarPosicion();
}

void Jugar::manejarTrampa(Objeto *obj) {
    cout << endl << endl;
    Trampa *trampa = dynamic_cast<Trampa *>(obj);
    util.colorRojo("___________________________________");
    util.colorRojo("_____   Encontro una Trampa   _____");
    util.colorRojo("___________________________________");
    arbolTrampa.insertar(trampa);
    int tmp = trampa->getAtaqueTrampa();
    jugador->recibirAtaque(tmp, " Trampa ");
    util.colorRojo("___________________________________");
    actualizarPosicion();
}

void Jugar::manejarPocima(Objeto *obj) {
    cout << endl << endl;
    util.colorAzul("___________________________________");
    util.colorAzul("_____   Encontro una pocima   _____");
    util.colorAzul("___________________________________");
    int tmp = dynamic_cast<Pocima *>(obj)->getPosima();
    jugador->recibirVidaExtra(tmp);
    util.colorAzul("___________________________________");
    actualizarPosicion();
}

/// complejidad:
/// complejidad insertar:
/// peor de lo casos: O(1)
/// mejor de los casos: O(1)
///

void Jugar::actualizarPosicion() {
    //contamos el moviemiento:
    cantMovimiento += 1;
    // Si la casilla no está ocupada, solo movemos al jugador
    tablero3D->eliminarObjeto(jugador->getPosX(), jugador->getPosY(), jugador->getPosZ());
    jugador->setPosicion(destino->x, destino->y, destino->z);
    tablero3D->setObjeto(jugador->getPosX(), jugador->getPosY(), jugador->getPosZ(), jugador);
    // Imprimir el tablero después del movimiento
    tablero3D->imprimirTablero2D(jugador->getPosZ());
}

/// complejidad:
/// complejidad guardar registro:
/// peor de lo casos: O(1)
/// mejor de los casos: O(1)
///
void Jugar::guardarRegistro() {
    // duracion de partida:
    auto finPartida = high_resolution_clock::now();
    auto duracion = duration_cast<seconds>(finPartida - inicioPartida);

    jugador->setTime(duracion.count());
    jugador->setCantMovimiento(cantMovimiento);
    /// Mostrar Estadistica:

    util.colorAmarillo("___________________________________");
    util.colorAmarillo("__________ RESUMEN DE JUEGO _______");
    util.colorAmarillo("___________________________________");

    util.colorCyan("👤 Nombre del Jugador: " + jugador->getNombre());
    util.colorCyan("⏳  Tiempo empleado: " + to_string(duracion.count()) + " segundos");
    util.colorCyan("🎮 Total de movimientos: " + to_string(cantMovimiento));
    util.colorVerde("🌟 Puntos acumulados: " + to_string(jugador->getPuntos()));
    util.colorCyan(
        "📍 Ubicación del tesoro: ("
        + to_string(tesoroX)
        + ", " + to_string(tesoroY)
        + ", " + to_string(tesoroZ) +")");

    util.colorAmarillo("🔎 Pistas encontradas:");
    arbolPista.mostrar();

    util.colorRojo("💀 Enemigos encontrados:");
    arbolEnemy.mostrar();

    util.colorMagenta("💣 Trampas encontradas:");
    arbolTrampa.mostrar();


    /// guardar Registro antes
     registros.guardarRegistroCSV(jugador);

    /// limpiear variables
    tesoroEncontrado = false;
    cantMovimiento = 0;
    tesoroX = 0;
    tesoroY = 0;
    tesoroZ = 0;
    arbolEnemy.vaciar();
    arbolTrampa.vaciar();
    arbolPista.vaciar();
    delete jugador;
    delete tablero3D;


}

