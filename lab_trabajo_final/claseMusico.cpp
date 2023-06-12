#include "claseMusico.h"

#include <cstring>
#include <iostream>
#include <iomanip>

#include "archivoInstrumento.h"
#include "archivoGenero.h"
#include "cargarCadena.h"
#include "claseFecha.h"

#include "rlutil.h"

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
    if (x > 0 && x < 5) {
        claustro = x;
    }
}
void Musico::setInstrumento(int x) {
    if (x > 0 && x < 16) {
        instrumento = x;
    }
}

void Musico::setTipoMusica(int x) {
    if (x > 0 && x < 11) {
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

    ArchivoInstrumento instrumentos("instrumentos.dat");
    instrumento = instrumentos.seleccionarRegistro();
    std::cout << "INSTRUMENTO: ";
    std::cout << instrumento << '\n';

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
    std::cout << std::right << std::setw(26) << "DNI: " << dni << '\n';
    std::cout << std::right << std::setw(26) << "NOMBRE: " << nombre << '\n';
    std::cout << std::right << std::setw(26) << "APELLIDO: " << apellido << '\n';
    std::cout << std::right << std::setw(26) << "EMAIL: " << email << '\n';
    std::cout << std::right << std::setw(26) << "TELEFONO: " << telefono << '\n';
    std::cout << std::right << std::setw(26) << "CLAUSTRO: " << claustro << '\n';
    std::cout << std::right << std::setw(26) << "INTRUMENTRO PRINCIPAL: " << instrumento << '\n';
    std::cout << std::right << std::setw(26) << "TIPO DE MÚSICA: " << tipoMusica << '\n';
    // Mostrar fecha de inscripción
    std::cout << std::right << std::setw(26) << "FECHA DE INSCRIPCION: ";
    fechaInscripcion.Mostrar();
    std::cout << '\n';
    std::cout << std::right << std::setw(26) << "MATRÍCULA: " << matricula << '\n';
}

void Musico::MostrarSeleccion() {
  std::cout << ' ' << std::right << std::setfill(' ') << std::setw(10) << dni << " - " << nombre << ' ' << apellido;
}
