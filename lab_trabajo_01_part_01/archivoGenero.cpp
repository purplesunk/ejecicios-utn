#include "archivoGenero.h"

#include <cstring>
#include <iostream>

#include "archivoGeneroMusical.h"
#include "cargarcadena.h"
#include "fecha.h"
#include "genero.h"

ArchivoGeneroMusical::ArchivoGeneroMusical(const char *nuevoArchivo) {
    strncpy(nombre, nuevoArchivo, 30);
}

void ArchivoGeneroMusical::agregarRegistro() {
    GeneroMusical obj;
    obj.Cargar();

    int pos = buscarGeneroMusical(obj.getDni());

    if (pos == -2) {
        std::cout << "El archivo no se encontro. Creando archivo.\n";
    } else if (pos != -1) {
        std::cout << "Ya hay un registro con ese DNI.\n";
        return;
    }

    FILE *fileGeneroMusical = fopen(nombre, "ab");
    if (fileGeneroMusical == NULL) {
        std::cout << "No se pudo abrir el archivo.\n";
        return;
    }

    fwrite(&obj, sizeof(GeneroMusical), 1, fileGeneroMusical);
    fclose(fileGeneroMusical);
}

void ArchivoGeneroMusical::mostrarRegistros() {
    FILE *fileGeneroMusical = fopen(nombre, "rb");
    if (fileGeneroMusical == NULL) {
        std::cout << "NO SE PUDO CREAR EL ARCHIVO.\n";
        return;
    }

    GeneroMusical obj;
    while (fread(&obj, sizeof obj, 1, fileGeneroMusical) == 1) {
        if (obj.getEstado()) {
            obj.Mostrar();
            std::cout << '\n';
        }
    }
    fclose(fileGeneroMusical);
}

GeneroMusical ArchivoGeneroMusical::leerGeneroMusical(int p) {
    GeneroMusical obj;

    if (p < 0) {
        obj.setId(-3);
        return obj;
    }

    FILE *fileGeneroMusical = fopen(nombre, "rb");
    if (fileGeneroMusical == NULL) {
        obj.setId(-2);
        return obj;
    }

    fseek(fileGeneroMusical, (sizeof(GeneroMusical) * p), SEEK_SET);

    if (!fread(&obj, sizeof(GeneroMusical), 1, fileGeneroMusical)) {
        obj.setId(-1);
    }

    return obj;
}

int ArchivoGeneroMusical::buscarGeneroMusical(int id) {
    FILE *fileGeneroMusical = fopen(nombre, "rb");
    if (fileGeneroMusical == NULL) {
        return -2;
    }

    int pos = 0;
    GeneroMusical obj;

    while (fread(&obj, sizeof(obj), 1, fileGeneroMusical) == 1) {
        if (id == obj.getId()) {
            fclose(fileGeneroMusical);
            return pos;
        }
        ++pos;
    }

    fclose(fileGeneroMusical);

    return -1;
}

bool ArchivoGeneroMusical::modificarRegistro(GeneroMusical obj, int pos) {
    FILE *fileGeneroMusical = fopen(nombre, "rb+");
    if (fileGeneroMusical == NULL) {
        std::cout << "ERROR AL REABRIR EL ARCHIVO.\n";
        return false;
    }

    fseek(fileGeneroMusical, sizeof(GeneroMusical) * pos, SEEK_SET);

    bool aux = fwrite(&obj, sizeof(GeneroMusical), 1, fileGeneroMusical);
    fclose(fileGeneroMusical);

    return aux;
}

bool ArchivoGeneroMusical::modificarFecha() {
    return false;
}

bool ArchivoGeneroMusical::bajaLogica() {
    // Solicitar que registro se quiere dar de baja
    int id;
    std::cout << "INGRESE EL ID A BUSCAR: ";
    std::cin >> id;
    ignoreLine();

    // Buscar el registro en el archivo
    int pos = buscarGeneroMusical(id);
    if (pos == -1) {
        std::cout << "NO EXISTE GENERO CON ESE DNI.\n";
        return false;
    }
    if (pos == -2) {
        std::cout << "NO SE PUDO ABRIR ARCHIVO\n";
        return false;
    }

    GeneroMusical obj = leerGeneroMusical(pos);

    if (obj.getEstado() == false) {
        std::cout << "EL GENERO INGRESADO YA ESTA DADO DE BAJA.\n";
        return false;
    }

    // Modificarmos el campo estado (lo ponemos en false)
    obj.setEstado(false);

    // Sobreescribir
    return modificarRegistro(obj, pos);
}