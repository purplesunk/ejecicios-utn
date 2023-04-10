#include <iostream>

#include "class_articulo.h"

using namespace std;

void cargarArticulos(Articulo registros[], const int CANTIDAD);
void mostrarArticulos(Articulo registros[], const int CANTIDAD);
void mostrarPrecio(Articulo registros[], const int CANTIDAD);

int main()
{
    const int CANTIDAD{2};
    Articulo registros[CANTIDAD];

    while (true) {
        cout << "------------------------------\n";
        cout << "1. Cargar vector de articulos\n";
        cout << "2. Mostrar vector de articulos\n";
        cout << "0. Salir\n";
        cout << "------------------------------\n";

        int opcion{};
        cin >> opcion;
        ignoreLine();

        switch(opcion) {
            case 1:
                cargarArticulos(registros, CANTIDAD);
                break;
            case 2:
                mostrarArticulos(registros, CANTIDAD);               
                break;
            case 0:
                return 0;
                break;
            default:
                cout << "Opción incorrecta.\n";
                break;
        }
    }
}

void cargarArticulos(Articulo registros[], const int CANTIDAD) {
    for (int i = 0; i < CANTIDAD; ++i) {
        cout << "\n-----------------------\n" << "Carga articulo " << i + 1 << ": \n-----------------------\n";
        registros[i].Cargar();
    }
}

void mostrarArticulos(Articulo registros[], const int CANTIDAD) {
    for (int i = 0; i < CANTIDAD; ++i) {
        cout << "\n-----------------------\n" << "Articulo " << i + 1 << ": \n-----------------------\n";
        registros[i].Mostrar();
    }
}

void mostrarPrecio(Articulo registros[], const int CANTIDAD) {
    int precio{};

    cout << "Ingrese el valor: ";
    cin >> precio;
    ignoreLine();

    for (int i = 0; i < CANTIDAD; ++i) {
        if (registros[i].getPrecio() > precio) {
            cout << "\n-----------------------\n" << "Articulo " << i + 1 << ": \n-----------------------\n";
            registros[i].Mostrar();
        }
    }
}