#include <cstring>
#include <iostream>

#include "cliente.h"
#include "fecha.h"
#include "puntos.h"
#include "utils.h"

int main() {
    bool cargados = false;
    const int CANTIDAD = 2;
    Cliente clientes[CANTIDAD];

    while (true) {
        std::cout << "1. Cargar\n";
        if (cargados) {
            std::cout << "2. Mostrar\n";
            std::cout << "3. Mostrar DNI Mayor a...\n";
            std::cout << "4. Posición de DNI\n";
            std::cout << "5. Objeto de DNI\n";
            std::cout << "6. Cantidad nacidos antes de...\n";
        }
        std::cout << "0. Salir\n";

        int opcion{};
        std::cin >> opcion;
        ignoreLine();

        if (cargados) {
            switch (opcion) {
                case 1:
                    cargados = cargarClientes(clientes, CANTIDAD);
                    break;
                case 2:
                    mostrarClientes(clientes, CANTIDAD);
                    break;
                case 3:
                    mostrarClientesDniMayor(clientes, CANTIDAD);
                    break;
                case 4:
                    punto4(clientes, CANTIDAD);
                    break;
                case 5:
                    punto5(clientes, CANTIDAD);
                    break;
                case 6:
                    punto6(clientes, CANTIDAD);
                    break;
                case 0:
                    return 0;
                    break;
                default:
                    std::cout << "Opción no existe.\n";
                    break;
            }
        } else {
            switch (opcion) {
                case 1:
                    cargados = cargarClientes(clientes, CANTIDAD);
                    break;
                case 0:
                    return 0;
                    break;
                default:
                    std::cout << "Opción no existe.\n";
                    break;
            }
        }
    }
}
