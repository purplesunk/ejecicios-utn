#include "genero.h"

#include <ctime>
#include <iostream>

#include "cargarcadena.h"

void GeneroMusical::cargar(int autoId) {
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

void GeneroMusical::mostrar() {
    std::cout << "ID: " << id << '\n';
    std::cout << "NOMBRE: " << nombre << '\n';
    std::cout << "PAIS DE ORIGEN: " << paisOrigen << '\n';
    std::cout << "AÑO DE ORIGEN: " << anioOrigen << '\n';
}

int GeneroMusical::getId() {
    return id;
}

void GeneroMusical::setId(int nuevoId) {
    id = nuevoId;
}

int GeneroMusical::getEstado() {
    return estado;
}

void GeneroMusical::setEstado(bool nuevoEstado) {
    estado = nuevoEstado;
}

void GeneroMusical::setAnioOrigen(int nuevoAnio) {
    time_t tiempo = time(NULL);
    struct tm *fechaActual = localtime(&tiempo);
    if (nuevoAnio > 1500 || nuevoAnio <= fechaActual->tm_year + 1900) {
        anioOrigen = nuevoAnio;
    }
}
