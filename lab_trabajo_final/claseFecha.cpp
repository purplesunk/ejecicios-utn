#include "claseFecha.h"

#include <ctime>
#include <iostream>

#include "cargarCadena.h"

Fecha::Fecha() {
    dia = 0;
    mes = 0;
    anio = 0;
}

Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::Cargar() {
    int x = cargarInt("Ingresar Año: ");
    this->setAnio(x);

    x = cargarInt("Ingresar Mes: ");
    this->setMes(x);

    x = cargarInt("Ingresar Día: ");
    this->setDia(x);
}

void Fecha::CargaValida() {
    time_t tiempo = time(NULL);
    struct tm *fechaActual = localtime(&tiempo);
    int anioActual = fechaActual->tm_year + 1900;
    int mesActual = fechaActual->tm_mon + 1;

    int x = cargarInt("Ingresar Año: ");
    while (x < 0 || x > anioActual) {
        std::cout << "Año no válido. ";
        x = cargarInt("Ingresar Año: ");
    }
    anio = x;

    int mesMax = 12;
    if (anio == anioActual) {
        mesMax = mesActual;
    }

    x = cargarInt("Ingresar Mes: ");
    while (x > mesMax || x <= 0) {
        std::cout << "Mes no válido. ";
        x = cargarInt("Ingresar Mes: ");
    }
    mes = x;

    int diaMax = 31;
    if (anio == anioActual && mes == mesActual) {
        diaMax = fechaActual->tm_mday;
    } else if (mes == 2) {
        if (this->anioBisiesto()) {
            diaMax = 29;
        } else {
            diaMax = 28;
        }
    } else if (mes % 2 != 0) {
        diaMax = 30;
    }

    x = cargarInt("Ingresar Día: ");
    while (x > diaMax || x <= 0) {
        std::cout << "Día no válido. ";
        x = cargarInt("Ingresar Día: ");
    }
    dia = x;
}

void Fecha::Mostrar() {
    if (dia < 10) {
        std::cout << '0' << dia;
    } else {
        std::cout << dia;
    }
    std::cout << '/';
    if (mes < 10) {
        std::cout << '0' << mes;
    } else {
        std::cout << mes;
    }
    std::cout << '/' << anio;
}

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

bool Fecha::anioBisiesto() {
    if (anio % 4 == 0) {
        if (anio % 100 == 0 && anio % 400 == 0) {
            return true;
        } else if (anio % 100 == 0) {
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}
