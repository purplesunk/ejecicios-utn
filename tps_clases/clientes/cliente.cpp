#include "cliente.h"

#include <iostream>
#include <cstring>

Cliente::Cliente(const char* valorDni, Fecha valorNac, const char* valorNom, const char* valorApellido, const char* valorTel, const char* valorEmail) {
    this->setApellido(valorApellido);
    this->setNombre(valorNom);
    this->setEmail(valorEmail);
    this->setTelefono(valorTel);
    this->setNacimiento(valorNac);
    this->setDni(valorDni);
}

void Cliente::Cargar() {
    char buffer[255];
    std::cout << "Ingrese DNI: ";
    cargarCadena(buffer, 9);
    this->setDni(buffer);

    std::cout << "Ingrese Fecha de nacimiento: \n";
    Fecha valorNacimiento;
    valorNacimiento.cargar();
    this->setNacimiento(valorNacimiento);

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
    std::cout << "Cliente: " << nombre << " " << apellido  << '\n';
    std::cout << "DNI: " << dni << '\n';
    std::cout << "Email: " << email << '\n';
    std::cout << "Teléfono: " << telefono << '\n';
    std::cout << "Fecha de nacimiento: ";
    nacimiento.mostrar();
    std::cout << '\n';
    std::cout << "--------------------------------------------\n";
}

Fecha Cliente::getNacimiento() {
    return nacimiento;
}

const char* Cliente::getDni() {
    return dni;
}

const char* Cliente::getNombre() {
    return nombre;
}

const char* Cliente::getApellido() {
    return apellido;
}

const char* Cliente::getEmail() {
    return email;
}

const char* Cliente::getTelefono() {
    return telefono;
}

void Cliente::setDni(const char *valor) {
    strncpy(dni, valor, 8);
}

void Cliente::setNacimiento(Fecha valor) {
    nacimiento.setDay(valor.getDay());
    nacimiento.setMonth(valor.getMonth());
    nacimiento.setYear(valor.getYear());
}

void Cliente::setNombre(const char *valor) {
    strncpy(nombre, valor, 49);
}

void Cliente::setApellido(const char *valor) {
    strncpy(apellido, valor, 49);
}

void Cliente::setEmail(const char *valor) {
    strncpy(email, valor, 79);
}

void Cliente::setTelefono(const char *valor) {
    strncpy(telefono, valor, 19);
}

