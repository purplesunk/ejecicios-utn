#include "clasePais.h"

#include <cstring>
#include <iostream>
#include <iomanip>

#include "cargarCadena.h"

void Pais::Cargar(int autoId) {
  std::cout << "Nombre de Pais: ";
  cargarCadena(nombre, 30);

  std::cout << "Continente al que pertenece: \n";
  cargarCadena(continente, 30);

  id = autoId;
  estado = true;
}

void Pais::Mostrar() {
  std::cout << std::right << std::setw(26) << "ID: " << id << '\n';
  std::cout << std::right << std::setw(26) << "NOMBRE: " << nombre << '\n';
  std::cout << std::right << std::setw(26) << "CONTINENTE: " << continente << '\n';
}

void Pais::MostrarSeleccion() {
  std::cout << ' ' << std::right << std::setfill(' ') << std::setw(4) << id << " - " << nombre;
}

// gets
int Pais::getId() { return id; }
bool Pais::getEstado() { return estado; }
const char *Pais::getContinente() { return continente; }
const char *Pais::getNombre() { return nombre; }

// sets
void Pais::setId(int nuevoId) { id = nuevoId; }
void Pais::setEstado(bool nuevoEstado) { estado = nuevoEstado; }
void Pais::setNombre(const char *n) { strncpy(nombre, n, 30); }

void Pais::setContinente(const char *c) { strncpy(continente, c, 30); }
