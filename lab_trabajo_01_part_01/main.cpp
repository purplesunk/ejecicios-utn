#include <cstring>
#include <iostream>

#include "archivoGenero.h"
#include "archivoMusico.h"
#include "cargarCadena.h"
#include "claseFecha.h"
#include "claseGeneroMusical.h"
#include "claseMusico.h"
#include "configuracion.h"
#include "reportes.h"
#include "zMenus.h"

int main() {
    // Cambiar encoding a UTF-8, así se ven las ñ o acentos.
    system("chcp 65001");
    system("cls");

    while (true) {
        std::cout << "  MENU PRINCIPAL\n";
        std::cout << "---------------------------------------\n";
        std::cout << "1) MENU MUSICOS\n";
        std::cout << "2) MENU GENEROS\n";
        std::cout << "3) REPORTES\n";
        std::cout << "4) CONFIGURACION\n";
        std::cout << "---------------------------------------\n";
        std::cout << "0) FIN PROGRAMA\n\n";

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
                // reportesMenu();
                break;
            case 4:
                menuConfiguracion();
                break;
            case 0:
                return 0;
                break;
            default:
                std::cout << "LA OPCION NO EXISTE.\n";
                break;
        }
        system("cls");
    }
}
