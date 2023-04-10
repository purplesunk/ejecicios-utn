#include <iostream>

#include "class_articulo.h"

void Articulo::setCodigo(char *valor) {
    if (strlen(valor) == 4)
        strncpy(codigo, valor, 4);
}

void Articulo::setDescripcion(char *valor) { strncpy(descripcion, valor, 29); }

void Articulo::setPrecio(float valor) {
    if (valor > 0)
        precio = valor;
}

void Articulo::setStock(int valor) {
    if (valor > -1)
        stock = valor;
}

void Articulo::setEstado(bool valor) { estado = valor; }

const char *Articulo::getCodigo() const { return codigo; }

const char *Articulo::getDescripcion() const { return descripcion; }

float Articulo::getPrecio() const { return precio; }

int Articulo::getStock() const { return stock; }

bool Articulo::getEstado() const { return estado; }

void Articulo::Cargar() {
    std::cout << "Ingrese codigo de articulo: ";
    cargarCadena(codigo, 5);

    std::cout << "Ingrese descripción: ";
    cargarCadena(descripcion, 30);

    std::cout << "Ingrese precio: ";
    std::cin >> precio;
    ignoreLine();

    std::cout << "Ingrese stock: ";
    std::cin >> stock;
    ignoreLine();
}

void Articulo::Mostrar() const {
    std::cout << "Código: " << codigo << '\n';
    std::cout << "Descripción: " << descripcion << '\n';
    std::cout << "Precio: " << precio << '\n';
    std::cout << "Stock: " << stock << '\n';
    std::cout << "Estado: " << estado << "\n\n";
}

Articulo::Articulo(const char *string) { strncpy(descripcion, string, 29); }

Articulo::Articulo(const char* codArt, const char* desc, float valorPrecio,
                   int valorStock, bool valorEstado) {
    strncpy(codigo, codArt, 4);
    strncpy(descripcion, desc, 29);
    precio = valorPrecio;
    stock = valorStock;
    estado = valorEstado;
}
