#include "claseInstrumento.h"

#include <cstring>
#include <iostream>
#include <iomanip>

#include "cargarCadena.h"

void Instrumento::Cargar(int autoId) {
  std::cout << "NOMBRE DE INSTRUMENTO: ";
  cargarCadena(nombre, 30);

  clasificacion = cargarInt("CLASIFICACION: ");
  while (clasificacion < 1 || clasificacion > 100) {
    std::cout << "CLASIFICACION INVALIDA. ";
    clasificacion = cargarInt("CLASIFICACION: ");
  }

  id = autoId;
  estado = true;
}

void Instrumento::Mostrar() {
  std::cout << std::right << std::setw(26) << "ID: " << id << '\n';
  std::cout << std::right << std::setw(26) << "NOMBRE: " << nombre << '\n';
  std::cout << std::right << std::setw(26) << "CLASIFICACION: " << clasificacion << '\n';
}

void Instrumento::MostrarSeleccion() {
  std::cout << ' ' << std::right << std::setfill(' ') << std::setw(4) << id << " - " << nombre;
}

// gets
int Instrumento::getId() { return id; }
bool Instrumento::getEstado() { return estado; }
int Instrumento::getClasificacion() { return clasificacion; }
const char *Instrumento::getNombre() { return nombre; }

// sets
void Instrumento::setId(int nuevoId) { id = nuevoId; }
void Instrumento::setEstado(bool nuevoEstado) { estado = nuevoEstado; }
void Instrumento::setNombre(const char *n) { strncpy(nombre, n, 30); }

void Instrumento::setClasificacion(int c) {
  if (c > 0 && c < 101) {
    clasificacion = c;
  }
}
