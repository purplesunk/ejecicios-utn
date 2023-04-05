#include <iostream>
#include <cstring>

const int NUM_ART = 2;

struct Articulo {
    char codigo[5];
    char descripcion[30];
    float precio;
    int stock;
};

void pause();
void clearInput();
void mostrarArticulo(Articulo registro);
void cargarArticulos(Articulo registros[]);
void mostrarArticulos(Articulo registros[]);
int cargarEntero(const char *string);
float cargarPrecio(const char *string);
void cargarCadena(char *palabra, int tam, const char *aviso);
int checkArticulo(Articulo registros[], const char *codArt);
void ventaArticulo(Articulo registros[]);
Articulo devolverArticulo(Articulo registros[], const char *codArt);

int main() {
    Articulo registros[NUM_ART];
    int opcion{};

    while (true) {
        std::cout << "1. Cargar artículos\n";
        std::cout << "2. Mostrar artículos\n";
        std::cout << "3. Venta de artículo\n";
        std::cout << "0. Salir\n";

        opcion = cargarEntero("Opción: ");

        switch(opcion) {
            case 1:
                cargarArticulos(registros);
            break;
            case 2:
                mostrarArticulos(registros);
            break;
            case 3:
                ventaArticulo(registros);
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

        cargarCadena(codArt, 5, "Ingrese código de artículo: ");
        while (checkArticulo(registros, codArt) != -1) {
            std::cout << "Código de artículo ya ingresado.\n";
            cargarCadena(codArt, 5, "Ingrese código de artículo: ");
        }
        strcpy(registros[i].codigo, codArt);

        cargarCadena(registros[i].descripcion, 30, "Ingrese descripción: ");

        registros[i].precio = cargarPrecio("Ingrese precio unitario: ");

        registros[i].stock = cargarEntero("Ingrese cantidad en stock: ");
    }
}

void ventaArticulo(Articulo registros[]) {
    std::cout << "Venta de articulo: \n";
    char codArt[5];
    cargarCadena(codArt, 5, "Ingrese código de artículo: ");
    int index{};
    while((index = checkArticulo(registros, codArt)) == -1) {
        std::cout << "Código de artículo no existente.\n";
        cargarCadena(codArt, 5, "Ingrese código de artículo: ");
    }

    int cantidad{};
    cantidad = cargarEntero("Ingrese la cantidad a comprar: ");
    while (registros[index].stock - cantidad < 0) {
        std::cout << "El stock es de " << registros[index].stock << ".\n";
        cantidad = cargarEntero("Ingrese la cantidad a comprar: ");
    }
    registros[index].stock -= cantidad;

    std::cout << "El importe de la venta es de $" << cantidad * registros[index].precio << '\n';

    pause();
}

void mostrarArticulo(Articulo registro) {
    std::cout << "Código de artículo: " << registro.codigo << '\n';
    std::cout << "Descripción: " << registro.descripcion << '\n';
    std::cout << "Precio Unitario: " << registro.precio << '\n';
    std::cout << "Cantidad de unidades en stock: " << registro.stock << '\n';
}
void mostrarArticulos(Articulo registros[]) {
    for (int i = 0; i < NUM_ART; ++i) {
         std::cout << "Artículo " << i + 1 << '\n';
         mostrarArticulo(registros[i]);
    }
    pause();
}

int checkArticulo(Articulo registros[], const char *codArt) {
    for (int i = 0; i < NUM_ART; ++i) {
        if (strcmp(registros[i].codigo, codArt) == 0) {
            return i;
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

void clearInput() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void pause() {
    std::cout << "\nPresione Enter para continuar...\n";
    std::cin.get();
    if(!std::cin) {
        std::cin.clear();
        clearInput();
    }
}

void cargarCadena(char *palabra, int tam, const char *aviso) {
    std::cout << aviso;
    std::cin.getline(palabra, tam);
    if (!std::cin) {
        std::cin.clear();
        clearInput();
    }
}

int cargarEntero(const char *string) {
    while (true) {
        std::cout << string;
        int number{};
        std::cin >> number;

        if (!std::cin) {
            std::cin.clear();
            clearInput();
            std::cout << "Input invalido.\n";
        } else {
            clearInput();
            return number;
        }
    }
}

float cargarPrecio(const char *string) {
    while (true) {
        std::cout << string;
        float number{};
        std::cin >> number;

        if (!std::cin || number <= 0) {
            std::cin.clear();
            clearInput();
            std::cout << "Input invalido.\n";
        } else {
            clearInput();
            return number;
        }
    }
}