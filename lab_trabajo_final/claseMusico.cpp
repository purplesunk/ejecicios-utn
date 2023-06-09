#include "claseMusico.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "claseFecha.h"

int Musico::getDni() { return dni; }
const char* Musico::getNombre() { return nombre; }
const char* Musico::getApellido() { return apellido; }
const char* Musico::getEmail() { return email; }
const char* Musico::getTelefono() { return telefono; }
Fecha Musico::getFechaInscripcion() { return fechaInscripcion; }
int Musico::getClaustro() { return claustro; }
int Musico::getInstrumentro() { return instrumento; }
int Musico::getTipoMusica() { return tipoMusica; }
float Musico::getMatricula() { return matricula; }
bool Musico::getEstado() { return estado; }

void Musico::setDNI(const int d) { dni = d; }
void Musico::setNombre(const char* n) { strcpy(nombre, n); }
void Musico::setApellido(const char* a) { strcpy(apellido, a); }
void Musico::setEmail(const char* e) { strcpy(email, e); }
void Musico::setTelefono(const char* t) { strcpy(telefono, t); }
void Musico::setEstado(bool b) { estado = b; }
void Musico::setFechaInscripcion(Fecha nuevaFecha) { fechaInscripcion = nuevaFecha; }

void Musico::setClaustro(int x) {
    if (x > 0 || x < 5) {
        claustro = x;
    }
}
void Musico::setInstrumento(int x) {
    if (x > 0 || x < 16) {
        instrumento = x;
    }
}

void Musico::setTipoMusica(int x) {
    if (x > 0 || x < 11) {
        tipoMusica = x;
    }
}

void Musico::setMatricula(int x) {
    if (x >= 0) {
        matricula = x;
    }
}

void Musico::Cargar() {
    dni = cargarInt("DNI: ");

    std::cout << "NOMBRE: ";
    cargarCadena(nombre, 30);
    std::cout << "APELLIDO: ";
    cargarCadena(apellido, 30);
    std::cout << "EMAIL: ";
    cargarCadena(email, 30);
    std::cout << "TELEFONO: ";
    cargarCadena(telefono, 30);

    claustro = cargarInt("CLAUSTRO: ");
    while (claustro < 1 || claustro > 4) {
        std::cout << "CLAUTRO INVALIDO. ";
        claustro = cargarInt("CLAUSTRO: ");
    }

    instrumento = cargarInt("INSTRUMENTO: ");
    while (instrumento < 1 || instrumento > 15) {
        std::cout << "INSTRUMENTO INVALIDO. ";
        instrumento = cargarInt("INSTRUMENTO: ");
    }

    tipoMusica = cargarInt("TIPO DE MÚSICA: ");
    while (tipoMusica < 1 || tipoMusica > 10) {
        std::cout << "TIPO DE MÚSICA INVALIDO. ";
        tipoMusica = cargarInt("TIPO DE MUSICA: ");
    }

    std::cout << "FECHA DE INSCRIPCION: \n";
    fechaInscripcion.CargaValida();

    matricula = cargarFloat("MATRICULA: ");
    while (matricula < 0) {
        std::cout << "MATRICULA INVALIDA. ";
        matricula = cargarFloat("MATRICULA: ");
    }

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
    std::cout << "FECHA DE INSCRIPCION: ";
    fechaInscripcion.Mostrar();
    std::cout << "\nMATRÍCULA: " << matricula << '\n';
}
