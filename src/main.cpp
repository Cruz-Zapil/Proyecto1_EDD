#include <iostream>
#include <fstream>
#include <limits>

#include "CargarRegistro.h"
#include "Util.h"
#include "Jugar.h"

using namespace std;
int main()
{

    int opcion = 0;
    bool jugando = true;
    CargarRegistro cargarRegistro ;
    Util  util ;
    Jugar jugar;


    util.colorAzul ("__________________________");
    util.colorRojo ("__________________________");
    util.colorVerde("_____   Bienvenido  ______");
    util.colorRojo ("__________________________");
    util.colorAzul ("__________________________");
    cout << endl<<endl;


    do
    {
        cout << endl
             << endl
             << endl
             << endl;

        util.colorVerde   ("___________________________");
        util.colorAmarillo("___________________________");
        util.colorRojo    ("________   MENÚ   _________");
        util.colorAmarillo("___________________________");
        util.colorVerde   ("___________________________");
          

        cout << endl;
        util.colorMagenta("__________________________");
        cout <<   "Seleccione una opcion:" << endl;

        cout << "1.";  util.colorVerde   ("Jugar");
        cout << "2.";  util.colorAmarillo("Cargar Registro");
        cout << "3.";  util.colorAzul    ("Mostrar Reporte ");
        cout << "4.";  util.colorRojo    ("Salir");

        util.colorMagenta("__________________________");
       
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

            jugar.iniciarJuego();
            break;

        case 2:
            cout << "Cargar Registro" << endl;
            cargarRegistro.cargarUnRegistro();
            
            break;

        case 3:
            cout << "Mostrar Reporte" << endl;
            break;

        case 4:

        util.colorRojo( "_________________________" );
        util.colorRojo( "_______   Adios  ________" );
        util.colorRojo( "_________________________" );
            jugando = false;
            break;

        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }

    } while (jugando);

    return 0;
}
