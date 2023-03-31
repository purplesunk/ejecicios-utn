#include <iostream>

#include "funciones.h"

int main() {
    const int NUM_MATERIAS = 3;

    char materias[NUM_MATERIAS][30];
    for (int i = 0; i < NUM_MATERIAS; i++) {
        materias[i][0] = '\0';
    }
    int asistencias[NUM_MATERIAS][31] = {0};

    while (true) {
        clearConsole();

        std::cout << "----------------------------------\n";
        std::cout << "1. Cargar Materias\n";
        std::cout << "2. Cargar Asistencias\n";
        std::cout << "3. Materias sin asistencias\n";
        std::cout << "4. Materias más concurrida\n";
        std::cout << "5. Cantidad de asistencias por día\n";
        std::cout << "0. Salir\n";
        std::cout << "----------------------------------\n";

        int op = cargarNumero();
        clearConsole();

        switch (op)
        {
        case 1:
            cargarMaterias(materias, NUM_MATERIAS);
            break;
        case 2:
            cargarAsistencias(asistencias, NUM_MATERIAS);
            break;
        case 3:
            materiasSinAsistencia(asistencias, materias, NUM_MATERIAS);
            break;
        case 4:
            masConcurrida(asistencias, materias, NUM_MATERIAS);
            break;
        case 5:
            cantidadAsistencias(asistencias, materias, NUM_MATERIAS);
            break;
        case 0:
            return 0;
            break;
        default:
            std::cout << "La opción no existe.";
            pause();
            break;
        }
    }
}