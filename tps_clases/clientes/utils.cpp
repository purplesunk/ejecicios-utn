#include <iostream>

#include "utils.h"

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
