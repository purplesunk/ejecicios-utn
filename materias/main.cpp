#include <iostream>
#include <cstring>

#include "funciones.h"

int main()
{
    int const CANTIDAD_MATERIAS = 10;
    char nombreMateria[CANTIDAD_MATERIAS][40];
    int horasMateria[CANTIDAD_MATERIAS] = {};
    int accesoMarzo[CANTIDAD_MATERIAS][31] = {};

    while (true)
    {
        std::cout << "1. Cargar Materias\n";
        std::cout << "2. Cargar Ingresos\n";
        std::cout << "3. Punto A\n";
        std::cout << "4. Punto B\n";
        std::cout << "5. Punto C\n";
        std::cout << "0. Salir del programa\n";

        int opcion;
        std::cin >> opcion;
        clearConsole();

        switch(opcion)
        {
            case 1:
                cargarMaterias(nombreMateria, CANTIDAD_MATERIAS);
                break;
            case 2:
                ingresosAlumnos(horasMateria, accesoMarzo);
                break;
            case 3:
                MateriasNoAcceso(horasMateria, nombreMateria, CANTIDAD_MATERIAS);
                break;
            case 4:
                MayorAcceso(horasMateria, nombreMateria, CANTIDAD_MATERIAS);
                break;
            case 5:
                CantidadAccesosMarzo(accesoMarzo, nombreMateria, CANTIDAD_MATERIAS);
                break;
            case 0:
                return 0;
                break;
        }
    }
}

