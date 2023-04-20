#ifndef CARGARCADENA_H_INCLUDED
#define CARGARCADENA_H_INCLUDED

#include <iostream>
#include <limits>

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void cargarCadena(char *cadena, int tam) {
    std::cin.getline(cadena, tam);
    if (!std::cin) {
        std::cin.clear();
        ignoreLine();
    }
}

#endif
