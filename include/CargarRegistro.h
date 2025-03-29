#ifndef CARGARREGISTRO_H
#define CARGARREGISTRO_H

#include <fstream>
#include <iostream>
#include <sstream>
#include "tinyfiledialogs.h"

using namespace std;

class CargarRegistro
{


public:
    void cargarUnRegistro()
    {
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
            }

            string linea;

            while (getline(file, linea))
            { // Lee línea por línea

                stringstream ss(linea);
                string palabra;

                while (getline(ss, palabra, ','))
                {
                    /// guardar las palabras
                    cout << palabra << endl;
                }
            }

            file.close(); // Cierra el archivo
        }
        else
        {
            cout << "No se seleccionó ningún archivo." << endl;
        }
    }

    void
    mostrarRegistro()
    {

        cout << "Mostrar Registro" << endl;
    }
};

#endif 