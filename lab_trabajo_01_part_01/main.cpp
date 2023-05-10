#include <iostream>

#include "archivoGenero.h"
#include "archivoMusico.h"
#include "cargarcadena.h"

int menuMusicos();
int menuGeneros();

int main() {
    while (true) {
        std::cout << "MENU PRINCIPAL\n";
        std::cout << "---------------------------------------\n";
        std::cout << "1) MENU MUSICOS\n";
        std::cout << "2) MENU GENEROS\n";
        std::cout << "3) REPORTES\n";
        std::cout << "4) CONFIGURACION\n";
        std::cout << "---------------------------------------\n";
        std::cout << "0) SALIR\n";

        int opcion = cargarInt("SELECCIONAR OPCION: ");

        system("cls");

        switch (opcion) {
            case 1:
                menuMusicos();
                break;
            case 2:
                menuGeneros();
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                return 0;
                break;
            default:
                std::cout << "LA OPCION NO EXISTE.\n";
                break;
        }
        system("pause");
        system("cls");
    }
}

int menuMusicos() {
    ArchivoMusico archivo("musicos.dat");

    while (true) {
        std::cout << "MENU MUSICOS\n";
        std::cout << "---------------------------------------\n";
        std::cout << "1) AGREGAR MUSICOS\n";
        std::cout << "2) LISTAR MUSICO POR DNI\n";
        std::cout << "3) LISTAR TODOS LOS MUSICOS\n";
        std::cout << "4) MODIFICAR FECHA DE INSCRIPCION\n";
        std::cout << "5) ELIMINAR REGISTRO DE MUSICO\n";
        std::cout << "---------------------------------------\n";
        std::cout << "0) VOLVER AL MENÚ PRINCIPAL\n";

        int opcion = cargarInt("SELECCIONAR OPCION: ");

        system("cls");

        switch (opcion) {
            case 1:
                archivo.agregarRegistro();
                break;
            case 2:
                archivo.buscarPorDNI();
                break;
            case 3:
                archivo.mostrarRegistros();
                break;
            case 4:
                // hacer ifs
                archivo.modificarFecha();
                break;
            case 5:
                // hacer ifs
                archivo.bajaLogica();
                break;
            case 0:
                return 0;
                break;
            default:
                std::cout << "LA OPCION NO EXISTE.\n";
                break;
        }
        system("pause");
        system("cls");
    }
}

int menuGeneros() {
    while (true) {
        std::cout << "MENU GÉNEROS\n";
        std::cout << "---------------------------------------\n";
        std::cout << "1) AGREGAR GÉNERO\n";
        std::cout << "2) LISTAR GÉNERO POR ID\n";
        std::cout << "3) LISTAR TODO\n";
        std::cout << "4) MODIFICAR AÑO DE ORIGEN\n";
        std::cout << "5) ELIMINAR REGISTRO\n";
        std::cout << "---------------------------------------\n";
        std::cout << "0) VOLVER AL MENÚ PRINCIPAL\n";

        int opcion = cargarInt("SELECCIONAR OPCION: ");

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
                std::cout << "LA OPCION NO EXISTE.\n";
                break;
        }
        system("pause");
        system("cls");
    }
}
