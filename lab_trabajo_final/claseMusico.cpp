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
int Musico::getInstrumento() { return instrumento; }
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
    ArchivoInstrumento instrumentos("instrumentos.dat");
    if (instrumentos.buscarRegistro(x) > 0) {
        instrumento = x;
    }
}

void Musico::setTipoMusica(int x) {
    ArchivoGeneroMusical generos("generos.dat");
    if (generos.buscarRegistro(x) > 0) {
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
    int posy = 2;

    posicion(posx, posy);
    mostrarAviso("CARGAR MUSICO");

    posy += 2;
    dni = cargarInt("DNI: ", posx, posy);
    ++posy;
    cargarCadena("NOMBRE: ", nombre, 30, posx, posy);
    ++posy;
    cargarCadena("APELLIDO: ", apellido, 30, posx, posy);
    ++posy;
    cargarCadena("EMAIL: ", email, 30, posx, posy);
    ++posy;
    cargarCadena("TELEFONO: ", telefono, 30, posx, posy);

    ++posy;
    claustro = cargarInt("CLAUSTRO: ", posx, posy);
    while (claustro < 1 || claustro > 4) {
        mostrarError("CLAUSTRO INVALIDO.");
        claustro = cargarInt("CLAUSTRO: ", posx, posy);
    }
    
    ++posy;
    ArchivoInstrumento instrumentos("instrumentos.dat");
    instrumento = instrumentos.cargaSeleccion("INSTRUMENTO: ", posx, posy);
    if (instrumento == -1) {
        dni = -1;
        return;
    }

    ++posy;
    ArchivoGeneroMusical generos("generos.dat");
    tipoMusica = generos.cargaSeleccion("TIPO DE MUSICA: ", posx, posy);
    if (tipoMusica == -1) {
        dni = -1;
        return;
    }

    ++posy;
    posicion(posx, posy);
    mostrarAviso("FECHA DE INSCRIPCION:\n");
    ++posy;
    fechaInscripcion.CargaValida(posx, posy);
    borrarLineas(--posy, 4);
    posicion(posx, posy);
    mostrarAviso("FECHA DE INSCRIPCION: ");
    fechaInscripcion.Mostrar();

    ++posy;
    matricula = cargarFloat("MATRICULA: ", posx, posy);
    while (matricula < 0) {
        mostrarError("MATRICULA INVALIDA.");
        matricula = cargarFloat("MATRICULA: ", posx, posy);
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
    mostrarDato("TIPO DE MUSICA: ", tipoMusica);
    mostrarAviso("FECHA DE INSCRIPCION: ");
    fechaInscripcion.Mostrar();
    std::cout << '\n';
    mostrarDato("MATRICULA: ", matricula);
}
