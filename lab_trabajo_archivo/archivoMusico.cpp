#include "archivoMusico.h"

#include <cstring>
#include <iostream>

#include "archivo.h"
#include "cargarCadena.h"
#include "claseFecha.h"
#include "claseMusico.h"

ArchivoMusico::ArchivoMusico(const char *nuevoArchivo) {
    strncpy(nombre, nuevoArchivo, 30);
}

void ArchivoMusico::agregarMusico() {
    Musico obj;
    std::cout << " Ingrese los datos del músico: \n";
    std::cout << "--------------------------------\n";
    obj.Cargar();

    int pos = buscarMusico(obj.getDni());

    if (pos == -2) {
        std::cout << "El archivo no se encontro. Creando archivo.\n";
    } else if (pos != -1) {
        std::cout << "Ya hay un registro con ese DNI.\n";
        return;
    }

    if (!agregarRegistro(&obj, sizeof(Musico), nombre)) {
        std::cout << "No se pudo abrir el archivo\n";
    }
}

bool ArchivoMusico::bajaLogica() {
    // Solicitar que registro se quiere dar de baja
    int DNI = cargarInt("INGRESE EL DNI A BUSCAR: ");

    // Buscar el registro en el archivo
    int pos = buscarMusico(DNI);
    if (pos == -1) {
        std::cout << "NO EXISTE MUSICO CON ESE DNI.\n";
        return false;
    }
    if (pos == -2) {
        std::cout << "NO SE PUDO ABRIR ARCHIVO\n";
        return false;
    }

    Musico obj;
    if (!leerRegistro(&obj, sizeof(Musico), pos, nombre)) {
        std::cout << "No se leer el registro.\n";
        return false;
    }

    if (!obj.getEstado()) {
        std::cout << "EL MUSICO INGRESADO YA ESTA DADO DE BAJA.\n";
        return false;
    }

    // Modificarmos el campo estado (lo ponemos en false)
    obj.setEstado(false);

    // Sobreescribir
    return modificarRegistro(&obj, sizeof(Musico), pos, nombre);
}

int ArchivoMusico::buscarMusico(int dni) {
    FILE *pCli = fopen(nombre, "rb");
    if (pCli == NULL) {
        return -2;
    }

    int pos = 0;
    Musico obj;

    while (fread(&obj, sizeof(obj), 1, pCli) == 1) {
        if (dni == obj.getDni()) {
            fclose(pCli);
            return pos;
        }
        ++pos;
    }

    fclose(pCli);

    return -1;
}

void ArchivoMusico::mostrarMusicos() {
    FILE *pCli = fopen(nombre, "rb");
    if (pCli == NULL) {
        std::cout << "NO SE PUDO ABRIR EL ARCHIVO.\n";
        return;
    }

    Musico obj;
    int cant = 0;
    while (fread(&obj, sizeof obj, 1, pCli) == 1) {
        if (obj.getEstado()) {
            ++cant;
            std::cout << "-------------------------------------\n";
            std::cout << " Musico " << cant << '\n';
            std::cout << "-------------------------------------\n";
            obj.Mostrar();
            std::cout << '\n';
        }
    }
    fclose(pCli);
}

void ArchivoMusico::buscarPorDNI() {
    int DNI = cargarInt("INGRESE EL DNI A BUSCAR: ");

    int pos = buscarMusico(DNI);
    if (pos == -2) {
        std::cout << "No se pudo abrir el archivo.\n";
        return;
    } else if (pos == -1) {
        std::cout << "No se encontró el registro.\n";
        return;
    }

    Musico obj;
    if (!leerRegistro(&obj, sizeof(Musico), pos, nombre)) {
        std::cout << "No se leer el registro.\n";
        return;
    }

    if (!obj.getEstado()) {
        std::cout << "Registro dado de baja.\n";
        return;
    }

    if (obj.getDni() > 0) {
        std::cout << "---------------------------------\n";
        obj.Mostrar();
        std::cout << "---------------------------------\n";

    } else if (obj.getDni() == -3) {
        std::cout << "Se puso una posición inválida.\n";
    } else if (obj.getDni() == -1) {
        std::cout << "No se pudo leer el registro.\n";
    } else {
        std::cout << "No se pudo abrir el archivo.\n";
    }
}

bool ArchivoMusico::modificarFecha() {
    int dni = cargarInt("Ingrese el DNI a buscar: ");

    int pos = buscarMusico(dni);
    if (pos == -1) {
        std::cout << "NO EXISTE MUSICO CON ESE DNI.\n";
        return false;
    }
    if (pos == -2) {
        std::cout << "NO SE PUDO ABRIR EL ARCHIVO.\n";
        return false;
    }

    Musico obj;
    if (!leerRegistro(&obj, sizeof(Musico), pos, nombre)) {
        std::cout << "No se leer el registro.\n";
        return false;
    }

    if (!obj.getEstado()) {
        std::cout << "Registro dado de baja.\n";
        return false;
    }

    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "Musico: " << obj.getNombre() << " " << obj.getApellido() << '\n';
    std::cout << "Fecha de Inscripción actual: ";
    obj.getFechaInscripcion().Mostrar();
    std::cout << "\n-------------------------------------------------------------------\n";

    Fecha nuevaFecha;
    std::cout << "Ingrese la nueva fecha de inscripcion:\n";
    nuevaFecha.Cargar();

    obj.setFechaInscripcion(nuevaFecha);

    return modificarRegistro(&obj, sizeof(Musico), pos, nombre);
}
