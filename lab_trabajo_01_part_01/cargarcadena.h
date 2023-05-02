#ifndef CARGARCADENA_H_INCLUDED
#define CARGARCADENA_H_INCLUDED

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

#endif