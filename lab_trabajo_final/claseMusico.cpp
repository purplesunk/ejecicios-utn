#include "claseMusico.h"

#include <cstring>
#include <iostream>

#include "archivoInstrumento.h"
#include "archivoGenero.h"
#include "cargarCadena.h"
#include "claseFecha.h"

#include "interfaz.h"

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
    int posx = 1;

    posicion(posx, 2);
    std::cout << "MUSICO: ";
    posicion(posx, 3);
    std::cout << "---------------\n";

    dni = cargarInt("DNI: ", posx, 5);
    cargarCadena("NOMBRE: ", nombre, 30, posx, 6);
    cargarCadena("APELLIDO: ", apellido, 30, posx, 7);
    cargarCadena("EMAIL: ", email, 30, posx, 8);
    cargarCadena("TELEFONO: ", telefono, 30, posx, 9);
    claustro = cargarInt("CLAUSTRO: ", posx, 10);
    while (claustro < 1 || claustro > 4) {
        mostrarError("CLAUSTRO INVALIDO.");
        claustro = cargarInt("CLAUSTRO: ", posx, 10);
    }
    
    posicion(posx, 11);
    mostrarAviso("INSTRUMENTO: ");
    ArchivoInstrumento instrumentos("instrumentos.dat");
    instrumento = instrumentos.seleccionarRegistro();

    posicion(posx, 11);
    mostrarDato("INSTRUMENTO: ", instrumento);

    tipoMusica = cargarInt("TIPO DE MUSICA: ", posx, 12);
    while (tipoMusica < 1 || tipoMusica > 10) {
        mostrarError("TIPO DE MUSICA INVALIDO.");
        tipoMusica = cargarInt("TIPO DE MUSICA: ", posx, 12);
    }

    posicion(posx, 13);
    mostrarAviso("FECHA DE INSCRIPCION:\n");
    fechaInscripcion.CargaValida();

    matricula = cargarFloat("MATRICULA: ", posx, 17);
    while (matricula < 0) {
        mostrarError("MATRICULA INVALIDA.");
        matricula = cargarFloat("MATRICULA: ", posx, 17);
    }

    estado = true;
}

void Musico::Mostrar() {
    mostrarDato("DNI: ", dni);
    mostrarDato("NOMBRE: ", nombre);
    mostrarDato("APELLIDO: ", apellido);
    mostrarDato("EMAIL: ", email);
    mostrarDato("TELEFONO: ", telefono);
    mostrarDato("CLAUSTRO: ", claustro);
    mostrarDato("INTRUMENTRO PRINCIPAL: ", instrumento);
    mostrarDato("TIPO DE MÚSICA: ", tipoMusica);
    mostrarAviso("FECHA DE INSCRIPCION: ");
    fechaInscripcion.Mostrar();
    std::cout << '\n';
    mostrarDato("MATRÍCULA: ", matricula);
}
