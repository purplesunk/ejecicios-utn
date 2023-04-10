#include <iostream>
#include <string.h>

#include "class_articulo.h"
#include "utils.h"

using namespace std;

void cargarArticulos(Articulo registros[], const int CANTIDAD);
void mostrarArticulos(Articulo registros[], const int CANTIDAD);
void mostrarPrecioMayor(Articulo registros[], const int CANTIDAD);
int posicionArticulo(Articulo registros[], const int CANTIDAD, const char* codArt);
int cantidadStockMenor(Articulo registros[], const int CANTIDAD);
Articulo devolverArticulo(Articulo registros[], const int CANTIDAD, const char* codArt);
void ajustePrecio(Articulo registros[], const int CANTIDAD, int porcentaje);

int main()
{
    const int CANTIDAD{3};
    Articulo registros[CANTIDAD];

    while (true) {
        cout << "------------------------------\n";
        cout << "1. Cargar vector de articulos\n";
        cout << "2. Mostrar vector de articulos\n";
        cout << "3. Mostrar articulos con precio mayor a...\n";
        cout << "4. Posición de articulo con codigo\n";
        cout << "5. Articulo con codigo\n";
        cout << "6. Cantidad de articulos con stock menor a...\n";
        cout << "7. Ajustar precio de los articulos\n";
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
            case 3:
                mostrarPrecioMayor(registros, CANTIDAD);
                break;
            case 4: {
                    cout << "Ingrese codigo a buscar: ";
                    char codArt[5];
                    cargarCadena(codArt, 5);

                    cout << "Posición: " << posicionArticulo(registros, CANTIDAD, codArt) << '\n';
                }
                break;
            case 5: {
                    cout << "Ingrese codigo a buscar: ";
                    char codArt[5];
                    cargarCadena(codArt, 5);

                    Articulo obj = devolverArticulo(registros, CANTIDAD, codArt);
                    cout << "Articulo: ";
                    obj.Mostrar();
                }
                break;
            case 6: 
                    cout << "Cantidad de articulos con ese stock: " << cantidadStockMenor(registros, CANTIDAD) << '\n';
                break;
            case 7: {
                    cout << "Ingrese porcentaje a incrementar el precio: ";
                    int porcentaje{};
                    cin >> porcentaje;
                    ignoreLine();

                    ajustePrecio(registros, CANTIDAD, porcentaje);
                }
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

void mostrarPrecioMayor(Articulo registros[], const int CANTIDAD) {
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

int posicionArticulo(Articulo registros[], const int CANTIDAD, const char* codArt) {
    for (int i = 0; i < CANTIDAD; ++i) {
        if (strncmp(registros[i].getCodigo(), codArt, 4) == 0) {
            return i;
        }
    }
    return -1;
}

Articulo devolverArticulo(Articulo registros[], const int CANTIDAD, const char* codArt) {
    for (int i = 0; i < CANTIDAD; ++i) {
        if (strncmp(registros[i].getCodigo(), codArt, 4) == 0) {
            return registros[i];
        }
    }
    Articulo obj("", "", 0, -1, false);   
    return obj;
}

int cantidadStockMenor(Articulo registros[], const int CANTIDAD) {
    int stock{};

    cout << "Ingrese el valor: ";
    cin >> stock;
    ignoreLine();

    int cantidad{0};

    for (int i = 0; i < CANTIDAD; ++i) {
        if (registros[i].getStock() < stock) {
            ++cantidad;
        }
    }

    return cantidad;
}

void ajustePrecio(Articulo registros[], const int CANTIDAD, int porcentaje) {
    float precio{};
    for (int i = 0; i < CANTIDAD; ++i) {
        precio = registros[i].getPrecio();
        precio += precio * porcentaje / 100;
        registros[i].setPrecio(precio);
    }
}