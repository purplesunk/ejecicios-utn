#include "claseGeneroMusical.h"

#include <cstring>
#include <ctime>
#include <iostream>

#include "cargarCadena.h"

void GeneroMusical::Cargar(int autoId) {
    std::cout << "Nombre de Género: ";
    cargarCadena(nombre, 30);

    paisOrigen = cargarInt("Pais de Origen: ");
    while (paisOrigen < 1 || paisOrigen > 100) {
        std::cout << "Pais de Origen Inválido. ";
        paisOrigen = cargarInt("Pais de Origen: ");
    }

    // Conseguir fecha actual
    time_t tiempo = time(NULL);
    struct tm *fechaActual = localtime(&tiempo);

    anioOrigen = cargarInt("Año de origen: ");
    while (anioOrigen < 1500 || anioOrigen > fechaActual->tm_year + 1900) {
        std::cout << "Año de origen Inválido. ";
        anioOrigen = cargarInt("Año de origen: ");
    }

    id = autoId;
    estado = true;
}

void GeneroMusical::Mostrar() {
    std::cout << "ID: " << id << '\n';
    std::cout << "NOMBRE: " << nombre << '\n';
    std::cout << "PAIS DE ORIGEN: " << paisOrigen << '\n';
    std::cout << "AÑO DE ORIGEN: " << anioOrigen << '\n';
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
void GeneroMusical::setNombre(const char *n) { strncpy(nombre, n, 30); }

void GeneroMusical::setPaisOrigen(int nuevoPais) {
    if (nuevoPais > 0 && nuevoPais < 101) {
        paisOrigen = nuevoPais;
    }
}

void GeneroMusical::setAnioOrigen(int nuevoAnio) {
    time_t tiempo = time(NULL);
    struct tm *fechaActual = localtime(&tiempo);
    if (nuevoAnio > 1500 || nuevoAnio <= fechaActual->tm_year + 1900) {
        anioOrigen = nuevoAnio;
    }
}
