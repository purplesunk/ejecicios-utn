#include "fecha.h"

#include <ctime>
#include <iostream>

Fecha::Fecha() {
  time_t tiempo = time(NULL);
  struct tm *fechaActual = localtime(&tiempo);

  dia = fechaActual->tm_mday;
  mes = fechaActual->tm_mon;
  anio = fechaActual->tm_year;
}

Fecha::Fecha(int d, int m, int a) {
  dia = d;
  mes = m;
  anio = a;
}

void Fecha::cagar() {
  int x;

  std::cout << "Ingresar día: ";
  std::cin >> x;
  this->setDia(x);

  std::cout << "Ingresar mes: ";
  std::cin >> x;
  this->setMes(x);

  std::cout << "Ingresar año: ";
  std::cin >> x;
  this->setAnio(x);
}

void Fecha::mostrar() { std::cout << dia << "/" << mes << "/" << anio; }

void Fecha::setDia(int d) {
  if (d > 0 && d <= 31) {
    dia = d;
  }
}

void Fecha::setMes(int m) {
  if (m > 0 && m <= 12) {
    mes = m;
  }
}

void Fecha::setAnio(int a) {
  if (a > 0) {
    anio = a;
  }
}

int Fecha::getDia() { return dia; }

int Fecha::getMes() { return mes; }

int Fecha::getAnio() { return anio; }
