#include "claseInstrumento.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "interfaz.h"

void Instrumento::Cargar(int autoId) {
  int posx = 1;
  int posy = 2;
  posicion(posx, posy);
  mostrarAviso("CARGA INSTRUMENTO");

  posy += 2;
  cargarCadena("NOMBRE DE INSTRUMENTO: ", nombre, 30, posx, posy);

  ++posy;
  clasificacion = cargarInt("CLASIFICACION: ", posx, posy);
  while (clasificacion < 1 || clasificacion > 10) {
    mostrarError("CLASIFICACION INVALIDA. ");
    clasificacion = cargarInt("CLASIFICACION: ", posx, posy);
  }

  id = autoId;
  estado = true;
}

void Instrumento::Mostrar() {
  mostrarDato("ID: ", id);
  mostrarDato("NOMBRE: ", nombre);
  mostrarDato("CLASIFICACION: ", clasificacion);
}

// gets
int Instrumento::getId() { return id; }
bool Instrumento::getEstado() { return estado; }
int Instrumento::getClasificacion() { return clasificacion; }
const char *Instrumento::getNombre() { return nombre; }

// sets
void Instrumento::setId(int nuevoId) { id = nuevoId; }
void Instrumento::setEstado(bool nuevoEstado) { estado = nuevoEstado; }
void Instrumento::setNombre(const char *n) { strncpy(nombre, n, 29); }

void Instrumento::setClasificacion(int c) {
  if (c > 0 && c < 10) {
    clasificacion = c;
  }
}
