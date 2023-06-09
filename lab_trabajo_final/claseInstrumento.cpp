#include "claseInstrumento.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"

void Instrumento::Cargar(int autoId) {
  std::cout << "Nombre de Instrumento: ";
  cargarCadena(nombre, 30);

  clasificacion = cargarInt("Clasificación: ");
  while (clasificacion < 1 || clasificacion > 100) {
    std::cout << "Clasificación Inválida. ";
    clasificacion = cargarInt("Clasificación: ");
  }

  id = autoId;
  estado = true;
}

void Instrumento::Mostrar() {
  std::cout << "ID: " << id << '\n';
  std::cout << "NOMBRE: " << nombre << '\n';
  std::cout << "CLASIFICACIÓN: " << clasificacion << '\n';
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
