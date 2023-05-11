#include "archivoMusico.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "claseFecha.h"
#include "claseMusico.h"

ArchivoMusico::ArchivoMusico(const char *nuevoArchivo) {
    strncpy(nombre, nuevoArchivo, 30);
}

void ArchivoMusico::agregarRegistro() {
    Musico obj;
    obj.Cargar();

    int pos = buscarMusico(obj.getDni());

    if (pos == -2) {
        std::cout << "El archivo no se encontro. Creando archivo.\n";
    } else if (pos != -1) {
        std::cout << "Ya hay un registro con ese DNI.\n";
        return;
    }

    FILE *pCli = fopen(nombre, "ab");
    if (pCli == NULL) {
        std::cout << "No se pudo abrir el archivo.\n";
        return;
    }

    fwrite(&obj, sizeof(Musico), 1, pCli);
    fclose(pCli);
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

    Musico obj = leerMusico(pos);

    if (obj.getEstado() == false) {
        std::cout << "EL MUSICO INGRESADO YA ESTA DADO DE BAJA.\n";
        return false;
    }

    // Modificarmos el campo estado (lo ponemos en false)
    obj.setEstado(false);

    // Sobreescribir
    return modificarRegistro(obj, pos);
}

Musico ArchivoMusico::leerMusico(int p) {
    Musico obj;

    if (p < 0) {
        obj.setDNI(-3);
        return obj;
    }

    FILE *pCli = fopen(nombre, "rb");
    if (pCli == NULL) {
        obj.setDNI(-2);
        return obj;
    }

    fseek(pCli, (sizeof(Musico) * p), SEEK_SET);

    if (!fread(&obj, sizeof(Musico), 1, pCli)) {
        obj.setDNI(-1);
    }

    return obj;
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

bool ArchivoMusico::modificarRegistro(Musico obj, int pos) {
    FILE *pCli = fopen(nombre, "rb+");
    if (pCli == NULL) {
        std::cout << "ERROR AL REABRIR EL ARCHIVO.\n";
        return false;
    }

    fseek(pCli, sizeof(Musico) * pos, SEEK_SET);

    bool aux = fwrite(&obj, sizeof(Musico), 1, pCli);
    fclose(pCli);

    return aux;
}

void ArchivoMusico::mostrarRegistros() {
    FILE *pCli = fopen(nombre, "rb");
    if (pCli == NULL) {
        std::cout << "NO SE PUDO ABRIR EL ARCHIVO.\n";
        return;
    }

    Musico obj;
    while (fread(&obj, sizeof obj, 1, pCli) == 1) {
        if (obj.getEstado()) {
            obj.Mostrar();
            std::cout << '\n';
        }
    }
    fclose(pCli);
}

bool ArchivoMusico::escribirRegistro(Musico obj) {
    FILE *archivo = fopen(nombre, "ab");
    if (archivo == NULL) {
        std::cout << "NO SE PUDO CREAR EL ARCHIVO.\n";
        return false;
    }

    bool aux = fwrite(&obj, sizeof(obj), 1, archivo);

    fclose(archivo);

    return aux;
}

void ArchivoMusico::buscarPorDNI() {
    int DNI = cargarInt("INGRESE EL DNI A BUSCAR: ");

    int pos = buscarMusico(DNI);
    Musico obj = leerMusico(pos);
    if (obj.getDni() > 0) {
        obj.Mostrar();
    } else if (obj.getDni() == -3 || obj.getDni() == -1) {
        std::cout << "SE PUSO UNA POSICIÓN EQUIVOCADA\n";
    } else {
        std::cout << "ERROR DE ARCHIVO.\n";
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
        std::cout << "NO SE PUDO ABRIR ARCHIVO.\n";
        return false;
    }

    Musico obj = leerMusico(pos);

    if (!obj.getEstado()) {
        std::cout << "Registro dado de baja.\n";
        return false;
    }

    Fecha nuevaFecha;
    std::cout << "Ingrese la nueva fecha de inscripcion:\n";
    nuevaFecha.Cargar();

    obj.setFechaInscripcion(nuevaFecha);

    return modificarRegistro(obj, pos);
}

int ArchivoMusico::contarRegistros() {
    FILE *musicos = fopen(nombre, "rb");
    if (musicos == NULL) {
        return -1;
    }

    fseek(musicos, 0, SEEK_END);

    int cantidad = ftell(musicos) / sizeof(Musico);

    fclose(musicos);

    return cantidad;
}