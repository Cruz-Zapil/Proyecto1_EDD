#include <iostream>
#include <fstream>
#include <limits>



#include "CargarRegistro.h"

using namespace std;
int main()
{

    int opcion = 0;
    bool jugando = true;
    CargarRegistro cargarRegistro ;

    do
    {
        cout << endl
             << endl
             << endl
             << endl;
        cout << "_________________________" << endl;
        cout << "_________________________" << endl;
        cout << "_______   Menu   ________" << endl;
        cout << "_________________________" << endl;
        cout << "_________________________" << endl
             << endl;

        cout << "Seleccione una opcion:" << endl;

        cout << "1. Jugar" << endl;
        cout << "2. Cargar Registro" << endl;
        cout << "3. Mostrar Reporte " << endl;
        cout << "4. Salir" << endl;

        cout << "_________________________" << endl;
       
        cout << "Ingrese su opción: ";
        cin >> opcion;


        // Manejo de error por entrada no numérica
        if (cin.fail())
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no válida. Por favor, ingrese un número entre 1 y 4." << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
            cout << "Jugar" << endl;

            break;

        case 2:
            cout << "Cargar Registro" << endl;
            cargarRegistro.cargarUnRegistro();
            
            break;

        case 3:
            cout << "Mostrar Reporte" << endl;
            break;

        case 4:

        cout << "_________________________" << endl;
        cout << "_______   Adios  ________" << endl;
        cout << "_________________________" << endl
             << endl;
            jugando = false;
            break;

        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }

    } while (jugando);

    return 0;
}
