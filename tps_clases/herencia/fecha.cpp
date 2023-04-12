#include "fecha.h"

#include <iostream>

#include "utils.h"

Fecha::Fecha(int valDay, int valMonth, int valYear) {
    this->setDay(valDay);
    this->setMonth(valMonth);
    this->setYear(valYear);
}

int Fecha::getDay() { return day; }

int Fecha::getMonth() { return month; }

int Fecha::getYear() { return year; }

void Fecha::setDay(int valor) {
    if (valor > 0 && valor < 31) {
        day = valor;
    } else {
        day = 10;
    }
}

void Fecha::setMonth(int valor) {
    if (valor > 0 && valor <= 12) {
        month = valor;
    } else {
        month = 3;
    }
}

void Fecha::setYear(int valor) {
    if (valor > 1900) {
        year = valor;
    } else {
        year = 2023;
    }
}

void Fecha::cargar() {
    int dia{}, mes{}, anio{};

    std::cout << "Ingresar día: ";
    std::cin >> dia;
    ignoreLine();

    std::cout << "Ingresar mes: ";
    std::cin >> mes;
    ignoreLine();

    std::cout << "Ingresar año: ";
    std::cin >> anio;
    ignoreLine();

    this->setDay(dia);
    this->setYear(anio);
    this->setMonth(mes);
}

void Fecha::mostrar() {
    std::cout << day << "/" << month << "/" << year;
}
