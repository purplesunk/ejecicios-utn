#include "musico.h"

#include <iostream>

#include "cargarcadena.h"
#include "fecha.h"

int Musico::getDni() {
    return dni;
}

const char* Musico::getNombre() {
    return nombre;
}

const char* Musico::getApellido() {
    return apellido;
}

const char* Musico::getEmail() {
    return email;
}

const char* Musico::getTelefono() {
    return telefono;
}

bool Musico::getEstado() {
    return estado;
}

void Musico::setDNI(const int d) {
    dni = d;
}

void Musico::setNombre(const char* n) {
    strcpy(nombre, n);
}

void Musico::setApellido(const char* a) {
    strcpy(apellido, a);
}

void Musico::setEmail(const char* e) {
    strcpy(email, e);
}

void Musico::setTelefono(const char* t) {
    strcpy(telefono, t);
}

void Musico::setEstado(bool b) {
    estado = b;
}

void Musico::Cargar() {
    std::cout << "DNI: ";
    // checkear que no esté en el chiche
    std::cin >> dni;
    ignoreLine();

    std::cout << "NOMBRE: ";
    cargarCadena(nombre, 30);
    std::cout << "APELLIDO: ";
    cargarCadena(apellido, 30);
    std::cout << "EMAIL: ";
    cargarCadena(email, 30);
    std::cout << "TELEFONO: ";
    cargarCadena(telefono, 30);

    // Settear el estado cargado :)
    estado = true;
}

void Musico::Mostrar() {
    std::cout << "DNI: " << dni << '\n';
    std::cout << "NOMBRE: " << nombre << '\n';
    std::cout << "APELLIDO: " << apellido << '\n';
    std::cout << "EMAIL: " << email << '\n';
    std::cout << "TELEFONO: " << telefono << '\n';
    std::cout << "CLAUSTRO: " << claustro << '\n';
    std::cout << "INTRUMENTRO PRINCIPAL: " << instrumento << '\n';
    std::cout << "TIPO DE MÚSICA: " << tipoMusica << '\n';
    // Mostrar fecha de inscripción
    std::cout << "MATRÍCULA: " << matricula << '\n';
}