#include <iostream>

#include "cargarcadena.h"

int main() {
    while (true) {
        std::cout << "MENU MUSICOS\n";
        std::cout << "---------------------------------------\n";
        std::cout << "1) AGREGAR MUSICOS\n";
        std::cout << "2) LISTAR MUSICO POR DNI\n";
        std::cout << "3) LISTAR TODOS LOS MUSICOS\n";
        std::cout << "4) MODIFICAR FECHA DE INSCRIPCION\n";
        std::cout << "5) ELIMINAR REGISTRO DE MUSICO\n";
        std::cout << "---------------------------------------\n";
        std::cout << "0) SALIR\n";

        int opcion = 0;
        std::cin >> opcion;
        ignoreLine();

        system("cls");

        switch (opcion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                return 0;
                break;
            default:
                std::cout << "LA OPCION NO EXISTE\n";
                system("pause");
                break;
        }
    }
}
