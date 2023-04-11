#include "cliente.h"

#include <cstring>
#include <iostream>

Cliente::Cliente(const char *valorNombre) { this->setNombre(valorNombre); }

Cliente::Cliente(int valorDni, int dia, int mes, int anio, const char *valorNom,
                 const char *valorApellido, const char *valorTel,
                 const char *valorEmail) {
    this->setApellido(valorApellido);
    this->setDni(valorDni);
    this->setEmail(valorEmail);
    this->setNombre(valorNom);
    this->setTelefono(valorTel);
    this->setNacimiento(dia, mes, anio);
}

void Cliente::Cargar() {
    char buffer[255];
    std::cout << "Ingrese DNI: ";
    int valorDni{};
    std::cin >> valorDni;
    this->setDni(valorDni);

    std::cout << "Ingrese Fecha de nacimiento: \n";
    nacimiento.cargar();

    std::cout << "Ingrese Nombre: ";
    cargarCadena(buffer, 50);
    this->setNombre(buffer);

    std::cout << "Ingrese Apellido: ";
    cargarCadena(buffer, 50);
    this->setApellido(buffer);

    std::cout << "Ingrese Email: ";
    cargarCadena(buffer, 80);
    this->setEmail(buffer);

    std::cout << "Ingrese Teléfono: ";
    cargarCadena(buffer, 20);
    this->setTelefono(buffer);
}

void Cliente::Mostrar() {
    std::cout << "--------------------------------------------\n";
    std::cout << "Cliente: " << nombre << " " << apellido << '\n';
    std::cout << "DNI: " << dni << '\n';
    std::cout << "Email: " << email << '\n';
    std::cout << "Teléfono: " << telefono << '\n';
    std::cout << "Fecha de nacimiento: ";
    nacimiento.mostrar();
    std::cout << '\n';
    std::cout << "--------------------------------------------\n";
}

Fecha Cliente::getNacimiento() { return nacimiento; }

int Cliente::getDni() { return dni; }

const char *Cliente::getNombre() { return nombre; }

const char *Cliente::getApellido() { return apellido; }

const char *Cliente::getEmail() { return email; }

const char *Cliente::getTelefono() { return telefono; }

void Cliente::setDni(int valor) { dni = valor; }

void Cliente::setNacimiento(int dia, int mes, int anio) {
    nacimiento.setDay(dia);
    nacimiento.setMonth(mes);
    nacimiento.setYear(anio);
}

void Cliente::setNombre(const char *valor) { strncpy(nombre, valor, 49); }

void Cliente::setApellido(const char *valor) { strncpy(apellido, valor, 49); }

void Cliente::setEmail(const char *valor) { strncpy(email, valor, 79); }

void Cliente::setTelefono(const char *valor) { strncpy(telefono, valor, 19); }