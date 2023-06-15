#include "cargarCadena.h"

#include <cstring>
#include <iostream>

#include "interfaz.h"

void ignoreLine() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

void cargarCadena(const char *pregunta, char *cadena, int tam, int posx, int posy) {
  posicion(posx, posy);
  mostrarAviso(pregunta);
  mostrarCursor();
  std::cin.getline(cadena, tam);
  if (!std::cin) {
    std::cin.clear();
    mostrarError("HUBO UN ERROR AL CARGAR EL TEXTO.");
    ignoreLine();
  }
  ocultarCursor();
}

void cargarCadena(char *cadena, int tam) {
  mostrarCursor();
  std::cin.getline(cadena, tam);
  if (!std::cin) {
    std::cin.clear();
    ignoreLine();
  }
  ocultarCursor();
}

int cargarInt(const char *pregunta, int posx, int posy) {
  int numero;
  borrarLinea(posy);
  posicion(posx, posy);
  mostrarAviso(pregunta);
  mostrarCursor();
  std::cin >> numero;

  while (!std::cin) {
    std::cin.clear();
    ignoreLine();
    ocultarCursor();
    mostrarError("INGRESE UN NUMERO.");
    
    borrarLinea(posy);
    posicion(posx, posy);
    mostrarAviso(pregunta);
    mostrarCursor();
    std::cin >> numero;
  }

  ocultarCursor();
  ignoreLine();
  return numero;
}

int cargarInt(const char *pregunta) {
  int numero;
  mostrarAviso(pregunta);
  mostrarCursor();
  std::cin >> numero;

  while (!std::cin) {
    std::cin.clear();
    ignoreLine();
    ocultarCursor();
    
    mostrarAviso(pregunta);
    mostrarCursor();
    std::cin >> numero;
  }

  ocultarCursor();
  ignoreLine();
  return numero;
}

float cargarFloat(const char *pregunta, int posx, int posy) {
  float numero;
  borrarLinea(posy);
  posicion(posx, posy);
  mostrarAviso(pregunta);
  mostrarCursor();
  std::cin >> numero;

  while (!std::cin) {
    std::cin.clear();
    ignoreLine();
    ocultarCursor();
    mostrarError("INGRESE UN NUMERO.");

    borrarLinea(posy);
    posicion(posx, posy);
    mostrarAviso(pregunta);
    mostrarCursor();
    std::cin >> numero;
  }

  ocultarCursor();
  ignoreLine();
  return numero;
}

float cargarFloat(const char *pregunta) {
  float numero;
  mostrarAviso(pregunta);
  mostrarCursor();
  std::cin >> numero;

  while (!std::cin) {
    std::cin.clear();
    ignoreLine();
    ocultarCursor();

    mostrarAviso(pregunta);
    mostrarCursor();
    std::cin >> numero;
  }

  ocultarCursor();
  ignoreLine();
  return numero;
}
