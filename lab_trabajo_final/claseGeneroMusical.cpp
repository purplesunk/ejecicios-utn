#include "claseGeneroMusical.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "claseFecha.h"
#include "archivoPais.h"
#include "interfaz.h"

void GeneroMusical::Cargar(int autoId) {
    int posx = 1;
    int posy = 2;
    posicion(posx, posy);
    mostrarAviso("CARGA GENERO MUSICAL");

    posy += 2;
    cargarCadena("NOMBRE DE GENERO MUSICAL: ", nombre, 30, posx, posy);

    ++posy;
    // paisOrigen = cargarInt("PAIS DE ORIGEN: ", posx, posy);
    // while (paisOrigen < 1 || paisOrigen > 100) {
    //     mostrarError("PAIS DE ORIGEN INVALIDO. ");
    //     paisOrigen = cargarInt("PAIS DE ORIGEN: ", posx, posy);
    // }
    posicion(posx, posy);
    mostrarAviso("PAIS DE ORIGEN: ");
    ArchivoPais paises("paises.dat");
    paisOrigen = paises.seleccionarRegistro();
    posicion(posx, posy);
    mostrarDato("PAIS DE ORIGEN: ", paisOrigen);


    ++posy;
    Fecha fechaActual("actual");
    anioOrigen = cargarInt("ANIO DE ORIGEN: ", posx, posy);
    while (anioOrigen < 1500 || anioOrigen > fechaActual.getAnio()) {
        mostrarError("ANIO DE ORIGEN INVALIDO. ");
        anioOrigen = cargarInt("ANIO DE ORIGEN: ", posx, posy);
    }

    id = autoId;
    estado = true;
}

void GeneroMusical::Mostrar() {
    mostrarDato("ID: ", id);
    mostrarDato("NOMBRE: ", nombre);
    mostrarDato("PAIS DE ORIGEN: ", paisOrigen);
    mostrarDato("ANIO DE ORIGEN: ", anioOrigen);
}

// gets
int GeneroMusical::getId() { return id; }
bool GeneroMusical::getEstado() { return estado; }
int GeneroMusical::getPaisOrigen() { return paisOrigen; }
int GeneroMusical::getAnioOrigen() { return anioOrigen; }
const char *GeneroMusical::getNombre() { return nombre; }

// sets
void GeneroMusical::setId(int nuevoId) { id = nuevoId; }
void GeneroMusical::setEstado(bool nuevoEstado) { estado = nuevoEstado; }
void GeneroMusical::setNombre(const char *n) { strncpy(nombre, n, 29); }

void GeneroMusical::setPaisOrigen(int nuevoPais) {
    // verificar acá también
    if (nuevoPais > 0 && nuevoPais < 101) {
        paisOrigen = nuevoPais;
    }
}

void GeneroMusical::setAnioOrigen(int nuevoAnio) {
    Fecha fechaActual("actual");
    if (nuevoAnio > 1500 && nuevoAnio <= fechaActual.getAnio()) {
        anioOrigen = nuevoAnio;
    }
}
