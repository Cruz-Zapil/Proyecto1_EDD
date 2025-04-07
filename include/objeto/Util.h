//
// Created by CruzZapil on 3/04/25.
//

#ifndef UTIL_H
#define UTIL_H

#include <random>

using namespace std;

class Util {
    /*
    // Formato: \033[<código>m<texto>\033[0m (0m resetea el estilo)

    cout << "\033[31mTexto rojo\033[0m" << endl;  // Rojo
    cout << "\033[32mTexto verde\033[0m" << endl; // Verde
    cout << "\033[33mTexto amarillo\033[0m" << endl;
    cout << "\033[34mTexto azul\033[0m" << endl;
    cout << "\033[35mTexto magenta\033[0m" << endl;
    cout << "\033[36mTexto cyan\033[0m" << endl;

    // Fondo + texto
    cout << "\033[41;37mTexto blanco sobre rojo\033[0m" << endl;

    // Negrita
    cout << "\033[1;33mTexto amarillo brillante\033[0m" << endl;


     */

    public:

    Util() = default;

    void colorRojo(string mensaje) {
        cout << "\033[31m"<<mensaje<< "\033[0m" << endl;
    };

    void colorVerde(string mensaje) {
        cout << "\033[32m"<<mensaje<< "\033[0m" << endl;
    };

    void colorAmarillo(string mensaje) {
        cout << "\033[33m"<<mensaje<< "\033[0m" << endl;
    };

    void colorAzul(string mensaje) {
        cout << "\033[34m"<<mensaje<< "\033[0m" << endl;
    };

    void colorMagenta(string mensaje) {
        cout << "\033[35m"<<mensaje<< "\033[0m" << endl;
    };

    void colorCyan(string mensaje) {
        cout << "\033[36m"<<mensaje<< "\033[0m" << endl;
    };

    int aleatorio_en_rango(int min, int max) {

        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<> distrib(min, max-1);
        return distrib(gen);
    }

    void colorVerdeJ(string mensaje) {
        cout << "\033[32m"<<mensaje<< "\033[0m" ;
    };

    void colorAmarilloT(string mensaje) {
        cout << "\033[33m"<<mensaje<< "\033[0m" ;
    };

    void colorMagentaP(string mensaje) {
        cout << "\033[33m"<<mensaje<< "\033[0m" ;
    };

    void colorAzulP(string mensaje) {
        cout << "\033[34m"<<mensaje<< "\033[0m" ;
    };

void colorRojoA(string mensaje) {
        cout << "\033[31m"<<mensaje<< "\033[0m" ;
    };

};



#endif //UTIL_H
