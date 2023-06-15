#include "claseFecha.h"

#include <ctime>
#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "interfaz.h"

Fecha::Fecha(const char *texto) {
    if (strcmp(texto, "actual") == 0) {
        time_t tiempo = time(NULL);
        struct tm *fechaActual = localtime(&tiempo);

        anio = fechaActual->tm_year + 1900;
        mes = fechaActual->tm_mon + 1;
        dia = fechaActual->tm_mday;
    }
}

Fecha::Fecha() {}

void Fecha::Cargar() {
    int x = cargarInt("INGRESAR ANIO: ");
    this->setAnio(x);

    x = cargarInt("INGRESAR MES: ");
    this->setMes(x);

    x = cargarInt("INGRESAR DIA: ");
    this->setDia(x);
}

void Fecha::CargaValida(int posx, int posy) {
    Fecha fechaActual("actual");
    int anioActual = fechaActual.getAnio();
    int mesActual = fechaActual.getMes();
    int x = cargarInt("INGRESAR ANIO: ", posx, posy);
    while (x < 0 || x > anioActual) {
        mostrarError("ANIO NO VALIDO.");
        x = cargarInt("INGRESAR ANIO: ", posx, posy);
    }
    anio = x;

    int mesMax = 12;
    if (anio == anioActual) {
        mesMax = mesActual;
    }

    x = cargarInt("INGRESAR MES: ", posx, posy + 1);
    while (x > mesMax || x <= 0) {
        mostrarError("MES NO VALIDO.");
        x = cargarInt("INGRESAR MES: ", posx, posy + 1);
    }
    mes = x;

    int diaMax = getDiaValido(fechaActual);

    x = cargarInt("INGRESAR DIA: ", posx, posy + 2);
    while (x > diaMax || x <= 0) {
        mostrarError("DIA NO VALIDO.");
        x = cargarInt("INGRESAR DIA: ", posx, posy + 2);
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

int Fecha::getDiaValido(Fecha &fechaActual) {
    int diaMax = 31;
    if (anio == fechaActual.getAnio() && mes == fechaActual.getMes()) {
        diaMax = fechaActual.getDia();
    } else if (mes == 2) {
        if (this->anioBisiesto()) {
            diaMax = 29;
        } else {
            diaMax = 28;
        }
    } else if (mes % 2 != 0) {
        diaMax = 30;
    }
    return diaMax;
}
