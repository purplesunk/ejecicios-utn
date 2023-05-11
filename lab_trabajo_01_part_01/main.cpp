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

int menuMusicos();
int menuGeneros();
int menuConfiguracion();

int main() {
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

int menuMusicos() {
    ArchivoMusico archivo("musicos.dat");

    while (true) {
        std::cout << "  MENU MUSICOS\n";
        std::cout << "---------------------------------------\n";
        std::cout << "1) AGREGAR MUSICOS\n";
        std::cout << "2) LISTAR MUSICO POR DNI\n";
        std::cout << "3) LISTAR TODOS LOS MUSICOS\n";
        std::cout << "4) MODIFICAR FECHA DE INSCRIPCION\n";
        std::cout << "5) ELIMINAR REGISTRO DE MUSICO\n";
        std::cout << "---------------------------------------\n";
        std::cout << "0) VOLVER AL MENÚ PRINCIPAL\n\n";

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
                if (archivo.modificarFecha()) {
                    std::cout << "Fecha modificada correctamente.\n";
                } else {
                    std::cout << "La fecha no fue modificada.\n";
                }
                break;
            case 5:
                if (archivo.bajaLogica()) {
                    std::cout << "Registro eliminado correctamente.\n";
                } else {
                    std::cout << "El registro no pudo ser eliminado.\n";
                }
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
    ArchivoGeneroMusical archivo("generos.dat");

    while (true) {
        std::cout << "  MENU GÉNEROS\n";
        std::cout << "---------------------------------------\n";
        std::cout << "1) AGREGAR GÉNERO\n";
        std::cout << "2) LISTAR GÉNERO POR ID\n";
        std::cout << "3) LISTAR TODO\n";
        std::cout << "4) MODIFICAR AÑO DE ORIGEN\n";
        std::cout << "5) ELIMINAR REGISTRO\n";
        std::cout << "---------------------------------------\n";
        std::cout << "0) VOLVER AL MENÚ PRINCIPAL\n\n";

        int opcion = cargarInt("SELECCIONAR OPCION: ");

        system("cls");

        switch (opcion) {
            case 1:
                archivo.agregarRegistro();
                break;
            case 2:
                archivo.buscarPorID();
                break;
            case 3:
                archivo.mostrarRegistros();
                break;
            case 4:
                if (archivo.modificarAnioOrigen()) {
                    std::cout << "Año de origen modificado correctamente.\n";
                } else {
                    std::cout << "Año de origen no pudo ser modificado.\n";
                }
                break;
            case 5:
                if (archivo.bajaLogica()) {
                    std::cout << "Registro eliminado correctamente.\n";
                } else {
                    std::cout << "No se pudo eliminar el registro.\n";
                }
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

int menuConfiguracion() {
    while (true) {
        std::cout << "  MENÚ CONFIGURACIÓN\n";
        std::cout << "---------------------------------------\n";
        std::cout << "1) COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS\n";
        std::cout << "2) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS\n";
        std::cout << "3) RESTAURAR EL ARCHIVO DE MUSICOS\n";
        std::cout << "4) RESTAURAR EL ARCHIVO DE GENEROS\n";
        std::cout << "5) ESTABLECER DATOS DE INICIO\n";
        std::cout << "---------------------------------------\n";
        std::cout << "0) VOLVER AL MENÚ PRINCIPAL\n\n";

        int opcion = cargarInt("SELECCIONAR OPCION: ");

        system("cls");

        switch (opcion) {
            case 1:
                if (copiaSeguridadMusicos()) {
                    std::cout << "Copia de seguridad completada.\n";
                } else {
                    std::cout << "Copia de seguridad no se pudo completar.\n";
                }
                break;
            case 2:
                if (copiaSeguridadGeneros()) {
                    std::cout << "Copia de seguridad completada.\n";
                } else {
                    std::cout << "Copia de seguridad no se pudo completar.\n";
                }
                break;
            case 3:
                if (restaurarMusicos()) {
                    std::cout << "Copia de seguridad restaurada.\n";
                } else {
                    std::cout << "Copia de seguridad no se pudo restaurar.\n";
                }
                break;
            case 4:
                if (restaurarGeneros()) {
                    std::cout << "Copia de seguridad restaurada.\n";
                } else {
                    std::cout << "Copia de seguridad no se pudo restaurar.\n";
                }
                break;
            case 5:
                if (restablecerInicio()) {
                    std::cout << "Datos iniciales restablecidos.\n";
                } else {
                    std::cout << "Datos iniciales no pudieron ser restablecidos correctamente.\n";
                }
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
