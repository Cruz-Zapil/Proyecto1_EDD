#ifndef CARGARREGISTRO_H
#define CARGARREGISTRO_H

#include <fstream>
#include <iostream>
#include <Jugador.h>
#include <sstream>

#include "OrdenJugadores.h"
#include "tinyfiledialogs.h"

using namespace std;

class CargarRegistro
{

private:
    OrdenJugadores listaJugadores;

public:
    void cargarUnRegistro()
    {
        listaJugadores.limpiarLista();
        /// lectura de archivo
        const char *filtro[] = {"*.csv"};
        const char *archivo = tinyfd_openFileDialog("Seleccionar archivo CSV", "", 1, filtro, "Archivos CSV", 0);

        if (archivo)
        {
            cout << "Archivo seleccionado: " << archivo << endl;
            ifstream file(archivo);

            if (!file)
            {
                cout << " Error al abrir el archivo :c";
                return;
            }

            string linea;
            bool encabezado = true;

            while (getline(file, linea)){ // Lee línea por línea

                if (encabezado) {
                    encabezado = false; // saltar primera línea
                    continue;
                }

                stringstream ss(linea);
                string nombre, puntos, tiempo, movimiento;


                getline(ss, nombre, ',');
                getline(ss, puntos, ',');
                getline(ss, tiempo , ',');
                getline(ss, movimiento, ',');

                int pts = stoi(puntos);
                int tmp = stoi(tiempo);
                int movimien = stoi(movimiento);

                Jugador* jugador = new Jugador(nombre,pts, tmp, movimien);

                listaJugadores.ingresar(jugador);

            }

            file.close(); // Cierra el archivo
            cout << "✅ Archivo cargado exitosamente.\n";
        }
        else
        {
            cout << "No se seleccionó ningún archivo." << endl;
        }
    }

    void mostrarRegistroOrdenado() {
        listaJugadores.ordenarLista();
        cout << "\n🏅 RANKING DE JUGADORES 🏅\n";
        listaJugadores.mostrarJugadores();
    }


    void guardarRegistroCSV(Jugador* jugador) {
        const char *filtro[] = { "*.csv" };
        const char *ruta = tinyfd_saveFileDialog("Guardar Registro", "registro_jugadores.csv", 1, filtro, "Archivo CSV");

        if (ruta) {
            ofstream archivo(ruta, ios::app);  // modo append
            if (archivo.is_open()) {
                archivo << jugador->getNombre() << ","
                        << jugador->getPuntos() << ","
                        << jugador->getTime() << ","
                        << jugador->getCantMovimiento() << "\n";

                archivo.close();
                cout << "✅ Registro guardado exitosamente en: " << ruta << endl;
            } else {
                cout << "❌ No se pudo abrir el archivo para escribir." << endl;
            }
        } else {
            cout << "⚠️ No se seleccionó ningún archivo para guardar." << endl;
        }
    }
};

#endif 