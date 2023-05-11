#include "cargarcadena.h"

#include <iostream>

void ignoreLine() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void cargarCadena(char *cadena, int tam) {
    std::cin.getline(cadena, tam);
    if (!std::cin) {
        std::cin.clear();
        ignoreLine();
    }
}

int cargarInt(const char *pregunta) {
    int numero;
    std::cout << pregunta;
    std::cin >> numero;

    while (!std::cin) {
        std::cin.clear();
        ignoreLine();
        std::cout << pregunta;
        std::cin >> numero;
    }

    ignoreLine();
    return numero;
}

float cargarFloat(const char *pregunta) {
    float numero;
    std::cout << pregunta;
    std::cin >> numero;

    while (!std::cin) {
        std::cin.clear();
        ignoreLine();
        std::cout << pregunta;
        std::cin >> numero;
    }

    ignoreLine();
    return numero;
}