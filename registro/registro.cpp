#include <iostream>
#include <cstring>

const int NUM_ART = 2;

struct Articulo {
    char codigo[5];
    char descripcion[30];
    float precio;
    int stock;
};

void cargarArticulos(Articulo registros[]);
void mostrarArticulo(Articulo registro);
int checkArticulo(Articulo registros[], const char *codArt);
Articulo devolverArticulo(Articulo registros[], const char *codArt);

void clearInput() {
    std::cin.clear();
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void pause() {
    std::cout << "\nPresione Enter para continuar...\n";

    clearInput();
    std::cin.get();
    if(!std::cin) {
        std::cin.clear();
        clearInput();
    }
}

int main() {
    Articulo registros[NUM_ART];

    while (true) {
        std::cout << "1. Cargar artículos\n";
        std::cout << "2. Mostrar artículos\n";
        std::cout << "0. Salir\n";

        std::cout << "Opción: ";
        int opcion{};
        std::cin >> opcion;

        while (!std::cin) {
            std::cin.clear();
            clearInput();
            std::cout << "Use un número.\nOpción: ";
            std::cin >> opcion;
        }

        switch(opcion) {
            case 1:
                cargarArticulos(registros);
            break;
            case 2:
                for (int i = 0; i < NUM_ART; ++i) {
                    std::cout << "Artículo " << i + 1 << '\n';
                    mostrarArticulo(registros[i]);
                }
                pause();           
            break;
            case 0:
                return 0;
            break;
            default:
                std::cout << "Opción no válida.\n";
            break;
        }
    }
}

void cargarArticulos(Articulo registros[]) {
    char codArt[5];
    for (int i = 0; i < NUM_ART; ++i) {
        std::cout << "Carga de artículo " << i + 1 << '\n';

        std::cout << "Ingrese código de artículo: ";
        clearInput();
        std::cin.getline(codArt, 5);
        if (!std::cin) {
            clearInput();
        }
        while (checkArticulo(registros, codArt) != -1) {
            std::cout << "Código de artículo ya ingresado.\n";
            std::cout << "Ingrese código de artículo: ";
            std::cin.getline(codArt, 5);
            if (!std::cin) {
                clearInput();
            }
        }

        strcpy(registros[i].codigo, codArt);

        std::cout << "Ingrese descripción: ";
        std::cin.getline(registros[i].descripcion, 30);
        if (!std::cin) {
            clearInput();
        }

        std::cout << "Ingrese precio unitario: ";
        std::cin >> registros[i].precio;
        while (!std::cin) {
            clearInput();
            std::cout << "Use un número.\nOpción: ";
            std::cin >> registros[i].precio;
        }

        std::cout << "Ingrese cantidad de stock: ";
        std::cin >> registros[i].stock;
        while (!std::cin) {
            clearInput();
            std::cout << "Use un número.\nOpción: ";
            std::cin >> registros[i].stock;
        }

    }
}

void mostrarArticulo(Articulo registro) {
    std::cout << "Código de artículo: " << registro.codigo << '\n';
    std::cout << "Descripción: " << registro.descripcion << '\n';
    std::cout << "Precio Unitario: " << registro.precio << '\n';
    std::cout << "Cantidad de unidades en stock: " << registro.stock << '\n';
}

int checkArticulo(Articulo registros[], const char *codArt) {
    for (int i = 0; i < NUM_ART; ++i) {
        if (strcmp(registros[i].codigo, codArt) == 0) {
            return i + 1;
        }       
    }
    return -1;
}

Articulo devolverArticulo(Articulo registros[], const char *codArt) {
    for (int i = 0; i < NUM_ART; ++i) {
        if (strcmp(registros[i].codigo, codArt) == 0) {
            return registros[i];
        }       
    }
    Articulo vacio;
    vacio.precio = -1;
    return vacio;
}