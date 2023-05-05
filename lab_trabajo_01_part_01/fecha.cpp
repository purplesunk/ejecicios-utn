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

void Fecha::Cargar() {
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

void Fecha::Mostrar() { std::cout << dia << "/" << mes << "/" << anio; }

void Fecha::setDia(int x) {
    if (x > 0 && x <= 31) {
        dia = x;
    }
}

void Fecha::setMes(int x) {
    if (x > 0 && x <= 12) {
        mes = x;
    }
}

void Fecha::setAnio(int x) {
    if (x > 0) {
        anio = x;
    }
}

int Fecha::getDia() { return dia; }

int Fecha::getMes() { return mes; }

int Fecha::getAnio() { return anio; }
