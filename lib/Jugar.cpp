#include <iostream>
#include <fstream>
#include <limits>

#include "Jugar.h"
#include "Trampa.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Pista.h"
#include "Pocima.h"


using namespace std;



void Jugar::iniciarJuego(){

    string nombreJugador;

    util.colorVerde(" Ingrese su nombre: ");
    cin >>nombreJugador;
    jugador = new Jugador(nombreJugador);

    util.colorMagenta("Ingrese el tamaño del Mundo");
    cin >> fila >> columna >> altura;
    // Manejo de error por entrada no numérica
    if (cin.fail() || fila < 2 || columna < 2 || altura < 2 )
    {
        cin.clear(); // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        numeroNodos= tamanioFijo*tamanioFijo*tamanioFijo;
        crearTablero(tamanioFijo, tamanioFijo, tamanioFijo);

    }else {
        numeroNodos= fila*columna*altura;
        crearTablero(fila, columna, altura);
    }

    /// mas metodos:
    crearPersonaje();
    crearObjetos();
}

void Jugar::crearTablero(int fila, int columna, int altura){

    if (tablero3D != nullptr) {
        delete tablero3D;
    }
    /// crear tablero
    tablero3D = new Tablero<Objeto*>(fila, columna, altura);

   // tablero3D->imprimirTablero2D(2);

}

void Jugar::crearPersonaje(){

    bool tmpPersonaje;
    do {
        int tmpx = util.aleatorio_en_rango(0,fila);
        int tmpy= util.aleatorio_en_rango(0,columna);
        int tmpz= util.aleatorio_en_rango(0,altura);
        util.colorRojo("primera pruba de colobar el objeto **borrable**");
        tmpPersonaje= (tablero3D->setObjeto(tmpx,tmpy,tmpz, &jugador));

    }while (!tmpPersonaje);

}

void Jugar::crearTesoro() {
    bool tmpTeso;
    Objeto* tmpTesoro = new Enemigo();
    do {
        int tmpx = util.aleatorio_en_rango(0,fila);
        int tmpy= util.aleatorio_en_rango(0,columna);
        int tmpz= util.aleatorio_en_rango(0,altura);
        util.colorRojo("primera pruba de colobar el objeto **borrable**");
        tmpTeso= (tablero3D->setObjeto(tmpx,tmpy,tmpz, &tmpTesoro));

    }while (!tmpTeso);
    delete tmpTesoro;
}

void Jugar::crearObjetos() {
    /// hay que crear objeto el 50% del mundo esta lleno de objetos
    util.colorRojo("numero de nodo **borrable");
    cout<<numeroNodos<<endl;
    int tmpObjetos = numeroNodos/8;

    for (int i = 0; i < tmpObjetos; i++) {
        Objeto* tmpEnemigo = new Enemigo();
        Objeto* tmpTrampa = new Trampa();
        Objeto* tmpPista = new Pista();
        Objeto* tmpPocima = new Pocima();

        bool tmpEnemy;
        do {
            int tmpx = util.aleatorio_en_rango(0,fila);
            int tmpy= util.aleatorio_en_rango(0,columna);
            int tmpz= util.aleatorio_en_rango(0,altura);
            util.colorRojo("primera pruba de colobar el objeto **borrable**");
            tmpEnemy= (tablero3D->setObjeto(tmpx,tmpy,tmpz, &tmpEnemigo));

        }while (!tmpEnemy);

        bool tmpTram;
        do {
            int tmpx = util.aleatorio_en_rango(0,fila);
            int tmpy= util.aleatorio_en_rango(0,columna);
            int tmpz= util.aleatorio_en_rango(0,altura);
            util.colorRojo("primera pruba de colobar el objeto **borrable**");
            tmpEnemy= (tablero3D->setObjeto(tmpx,tmpy,tmpz, &tmpTrampa));

        }while (!tmpTram);

        bool tmpPist;
        do {
            int tmpx = util.aleatorio_en_rango(0,fila);
            int tmpy= util.aleatorio_en_rango(0,columna);
            int tmpz= util.aleatorio_en_rango(0,altura);
            util.colorRojo("primera pruba de colobar el objeto **borrable**");
            tmpEnemy= (tablero3D->setObjeto(tmpx,tmpy,tmpz, &tmpPista));

        }while (!tmpPist);

        bool tmpPoci;
        do {
            int tmpx = util.aleatorio_en_rango(0,fila);
            int tmpy= util.aleatorio_en_rango(0,columna);
            int tmpz= util.aleatorio_en_rango(0,altura);
            util.colorRojo("primera pruba de colobar el objeto **borrable**");
            tmpEnemy= (tablero3D->setObjeto(tmpx,tmpy,tmpz, &tmpPocima));

        }while (!tmpPoci);

        delete tmpEnemigo;
        delete tmpPista;
        delete tmpPista;
        delete tmpPocima;

    }

    }






