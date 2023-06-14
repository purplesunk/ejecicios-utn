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
  std::cin.getline(cadena, tam);
  if (!std::cin) {
    std::cin.clear();
    ignoreLine();
  }
}

void cargarCadena(char *cadena, int tam) {
  std::cin.getline(cadena, tam);
  if (!std::cin) {
    std::cin.clear();
    ignoreLine();
  }
}

int cargarInt(const char *pregunta, int posx, int posy) {
  int numero;
  posicion(posx, posy);
  mostrarAviso(pregunta);
  std::cin >> numero;

  while (!std::cin) {
    std::cin.clear();
    ignoreLine();
    mostrarError("INGRESE UN NUMERO.");
    
    posicion(posx, posy);
    mostrarAviso(pregunta);
    std::cin >> numero;
  }

  ignoreLine();
  return numero;
}

int cargarInt(const char *pregunta) {
  int numero;
  mostrarAviso(pregunta);
  std::cin >> numero;

  while (!std::cin) {
    std::cin.clear();
    ignoreLine();
    mostrarError("INGRESE UN NUMERO.");
    
    mostrarAviso(pregunta);
    std::cin >> numero;
  }

  ignoreLine();
  return numero;
}

float cargarFloat(const char *pregunta, int posx, int posy) {
  float numero;
  posicion(posx, posy);
  mostrarAviso(pregunta);
  std::cin >> numero;

  while (!std::cin) {
    std::cin.clear();
    ignoreLine();
    mostrarError("INGRESE UN NUMERO.");

    posicion(posx, posy);
    mostrarAviso(pregunta);
    std::cin >> numero;
  }

  ignoreLine();
  return numero;
}

float cargarFloat(const char *pregunta) {
  float numero;
  mostrarAviso(pregunta);
  std::cin >> numero;

  while (!std::cin) {
    std::cin.clear();
    ignoreLine();
    mostrarError("INGRESE UN NUMERO.");

    mostrarAviso(pregunta);
    std::cin >> numero;
  }

  ignoreLine();
  return numero;
}
