#include <iostream>

struct Articulo {
    char codigo[5];
    char descripcion[30];
    float precio;
    int stock;
};

Articulo cargarArticulo();
void mostrarArticulo(Articulo registro);

void clearInput() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {

    Articulo registro;

    while (true) {
        std::cout << "1. Cargar artículo\n";
        std::cout << "2. Mostrar artículo\n";
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
                registro = cargarArticulo();
            break;
            case 2:
                mostrarArticulo(registro);
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

Articulo cargarArticulo() {
    Articulo registro;
    std::cout << "Ingrese código de artículo: ";
    clearInput();
    std::cin.getline(registro.codigo, 5);
    if (!std::cin) {
        clearInput();
    }
    std::cout << "Ingrese descripción: ";
    std::cin.getline(registro.descripcion, 30);
    if (!std::cin) {
        clearInput();
    }
    std::cout << "Ingrese precio unitario: ";
    std::cin >> registro.precio;
    while (!std::cin) {
        std::cin.clear();
        clearInput();
        std::cout << "Use un número.\nOpción: ";
        std::cin >> registro.precio;
    }
    std::cout << "Ingrese cantidad de stock: ";
    std::cin >> registro.stock;
    while (!std::cin) {
        std::cin.clear();
        clearInput();
        std::cout << "Use un número.\nOpción: ";
        std::cin >> registro.stock;
    }
    return registro;
}

void mostrarArticulo(Articulo registro) {
    std::cout << "Código de artículo: " << registro.codigo << '\n';
    std::cout << "Descripción: " << registro.descripcion << '\n';
    std::cout << "Precio Unitario: " << registro.precio << '\n';
    std::cout << "Cantidad de unidades en stock: " << registro.stock << '\n';

    std::cout << "\nPresione Enter para continuar...\n";

    clearInput();
    std::cin.get();
    if(!std::cin) {
        std::cin.clear();
        clearInput();
    }
}