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
  posicion(posx, posy);
  mostrarAviso("CONTINENTE: ");
  const int tamNombres = 30;
  const int cantContinentes = 7;
  char continentes[cantContinentes][tamNombres];
  strncpy(continentes[0], "America del Sur", 29);
  strncpy(continentes[1], "America del Norte", 29);
  strncpy(continentes[2], "America Central", 29);
  strncpy(continentes[3], "Europa", 29);
  strncpy(continentes[4], "Asia", 29);
  strncpy(continentes[5], "Oceania", 29);
  strncpy(continentes[6], "Africa", 29);
  char **nombreRegistros = new char*[cantContinentes];
  for (int i = 0; i < cantContinentes; ++i) {
    nombreRegistros[i] = continentes[i];
  }
  int seleccion = seleccionarObjeto(-1, 4, 40, -1, nombreRegistros, cantContinentes, "SELECCIONAR CONTINENTE:");
  delete[] nombreRegistros;
  strncpy(continente, continentes[seleccion], 29);
  posicion(posx, posy);
  mostrarDato("CONTINENTE: ", continente);
  
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
void Pais::setContinente(const char *c) { 
  const int tamNombres = 30;
  const int cantContinentes = 7;
  char continentes[cantContinentes][tamNombres];
  strncpy(continentes[0], "America del Sur", 29);
  strncpy(continentes[1], "America del Norte", 29);
  strncpy(continentes[2], "America Central", 29);
  strncpy(continentes[3], "Europa", 29);
  strncpy(continentes[4], "Asia", 29);
  strncpy(continentes[5], "Oceania", 29);
  strncpy(continentes[6], "Africa", 29);
  
  int coincide = -1;
  for (int i = 0; i < cantContinentes; ++i) {
    if (strcasecmp(continentes[i], c) == 0) {
      coincide = i;
    }
  }

  if (coincide != -1) {
    strncpy(continente, continentes[coincide], 29); 
  }
}
