#include "clasePais.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "interfaz.h"

void Pais::Cargar(int autoId) {
  int posx = 1;
  int posy = 2;
  posicion(posx, posy);
  mostrarAviso("CARGA PAIS");

  posy += 2;
  cargarCadena("NOMBRE PAIS: ", nombre, 30, posx, posy);

  ++posy;
  mostrarAviso("CONTINENTE: ");
  // seleccionar continente función xd
  cargarCadena(continente, 30);

  id = autoId;
  estado = true;
}

void Pais::Mostrar() {
  mostrarDato("ID: ", id);
  mostrarDato("NOMBRE: ", nombre);
  mostrarDato("CONTINENTE: ", continente);
}

// gets
int Pais::getId() { return id; }
bool Pais::getEstado() { return estado; }
const char *Pais::getContinente() { return continente; }
const char *Pais::getNombre() { return nombre; }

// sets
void Pais::setId(int nuevoId) { id = nuevoId; }
void Pais::setEstado(bool nuevoEstado) { estado = nuevoEstado; }
void Pais::setNombre(const char *n) { strncpy(nombre, n, 29); }
void Pais::setContinente(const char *c) { strncpy(continente, c, 29); }
