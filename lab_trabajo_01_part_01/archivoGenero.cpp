#include "archivoGenero.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "claseFecha.h"
#include "claseGeneroMusical.h"

ArchivoGeneroMusical::ArchivoGeneroMusical(const char *nuevoArchivo) {
    strncpy(nombre, nuevoArchivo, 30);
}

void ArchivoGeneroMusical::agregarRegistro() {
    GeneroMusical obj;

    int autoId = contarRegistros();

    if (autoId == -1) {
        autoId = 1;
    } else {
        ++autoId;
    }

    obj.Cargar(autoId);

    int pos = buscarGeneroMusical(obj.getId());

    if (pos == -2) {
        std::cout << "El archivo no se encontro. Creando archivo.\n";
    } else if (pos != -1) {
        std::cout << "Ya hay un registro con ese ID.\n";
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

bool ArchivoGeneroMusical::modificarAnioOrigen() {
    int ID = cargarInt("Ingrese el ID a buscar: ");

    int pos = buscarGeneroMusical(ID);
    if (pos == -1) {
        std::cout << "No existe genero con ese ID.\n";
        return false;
    }
    if (pos == -2) {
        std::cout << "No se pudo abrir el archivo.\n";
        return false;
    }

    GeneroMusical obj;

    if (!obj.getEstado()) {
        std::cout << "Registro dado de baja.\n";
        return false;
    }

    int nuevoAnio = cargarInt("Ingresar nuevo año de origen: ");
    obj.setAnioOrigen(nuevoAnio);

    return modificarRegistro(obj, pos);
}

bool ArchivoGeneroMusical::bajaLogica() {
    // Solicitar que registro se quiere dar de baja
    int id = cargarInt("INGRESE EL ID A BUSCAR: ");

    // Buscar el registro en el archivo
    int pos = buscarGeneroMusical(id);
    if (pos == -1) {
        std::cout << "NO EXISTE GENERO CON ESE ID.\n";
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

void ArchivoGeneroMusical::buscarPorID() {
    int ID = cargarInt("INGRESE EL ID A BUSCAR: ");

    int pos = buscarGeneroMusical(ID);
    GeneroMusical obj = leerGeneroMusical(pos);
    if (obj.getId() > 0) {
        obj.Mostrar();
    } else if (obj.getId() == -3 || obj.getId() == -1) {
        std::cout << "SE PUSO UNA POSICIÓN EQUIVOCADA\n";
    } else {
        std::cout << "ERROR DE ARCHIVO.\n";
    }
}

bool ArchivoGeneroMusical::escribirRegistro(GeneroMusical obj) {
    FILE *archivo = fopen(nombre, "ab");
    if (archivo == NULL) {
        std::cout << "NO SE PUDO CREAR EL ARCHIVO.\n";
        return false;
    }

    bool aux = fwrite(&obj, sizeof(obj), 1, archivo);

    fclose(archivo);

    return aux;
}

int ArchivoGeneroMusical::contarRegistros() {
    FILE *generos = fopen(nombre, "rb");
    if (generos == NULL) {
        return -1;
    }

    fseek(generos, 0, SEEK_END);

    int cantidad = ftell(generos) / sizeof(GeneroMusical);

    fclose(generos);

    return cantidad;
}
