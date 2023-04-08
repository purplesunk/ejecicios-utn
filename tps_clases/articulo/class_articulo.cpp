#include <string.h>
#include <iostream>
#include <limits>

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void cargarCadena(char *cadena, int tam) {
    std::cin.getline(cadena, tam);
    if (!std::cin) {
        std::cin.clear();
        ignoreLine();
    }
}

#include "class_articulo.h"

void Articulo::setCodigo(char *valor) {
    strncpy(codigo, valor, 4);
}

void Articulo::setDescripcion(char *valor) {
    strncpy(descripcion, valor, 29);
}

void Articulo::setPrecio(float valor) {
    if (valor > 0) 
        precio = valor;
}

void Articulo::setStock(int valor) {
    if (valor > -1)
        stock = valor;
}

void Articulo::setEstado(bool valor) {
    estado = valor;
}

const char* Articulo::getCodigo() const {
    return codigo;
}

const char* Articulo::getDescripcion() const {
    return descripcion;
}

float Articulo::getPrecio() const {
    return precio;
}

int Articulo::getStock() const {
    return stock;
}

bool Articulo::getEstado() const {
    return estado;
}

void Articulo::Cargar() {
    std::cout << "Carga de articulo:\n -------------------------\n"
        "Ingrese codigo de articulo: ";
    cargarCadena(codigo, 5);

    std::cout << "Ingrese descripción: ";
    cargarCadena(descripcion, 30);

    std::cout << "Ingrese precio: ";
    std::cin >> precio;

    std::cout << "Ingrese stock: ";
    std::cin >> stock;
}

void Articulo::Mostrar() const {
    std::cout << "Articulo:\n --------------------------\n";
    std::cout << "Código: " << codigo << '\n';
    std::cout << "Descripción: " << descripcion << '\n';
    std::cout << "Precio: " << precio << '\n';
    std::cout << "Stock: " << stock << '\n';
    std::cout << "Estado: " << estado << '\n';
}

Articulo::Articulo(const char* string) {
    strncpy(descripcion, string, 29);
}

Articulo::Articulo(const char* codArt = "AAAA", const char* desc = "No hay descripción", float valorPrecio = 0, int valorStock = 0, bool valorEstado = false) {
    strncpy(codigo, codArt, 4);
    strncpy(descripcion, desc, 29);
    precio = valorPrecio;
    stock = valorStock;
    estado = valorEstado;
}