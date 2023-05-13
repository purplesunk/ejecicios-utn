#include "archivo.h"

#include <iostream>

bool agregarRegistro(void* obj, size_t tam, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "ab");
    if (archivo == NULL) {
        return false;
    }

    bool agregado = fwrite(&obj, tam, 1, archivo);

    fclose(archivo);

    return agregado;
}

bool modificarRegistro(void* obj, size_t tam, int pos, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "rb+");
    if (archivo == NULL) {
        return false;
    }

    fseek(archivo, tam * pos, SEEK_SET);

    bool modificado = fwrite(obj, tam, 1, archivo);

    fclose(archivo);

    return modificado;
}

bool leerRegistro(void* obj, size_t tam, int pos, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        return false;
    }

    fseek(archivo, tam * pos, SEEK_SET);

    bool leido = fread(obj, tam, 1, archivo);

    fclose(archivo);

    return leido;
}

int contarRegistros(const char* nombreArchivo, size_t tamObjeto) {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        return -1;
    }

    fseek(archivo, 0, SEEK_END);

    int cantidad = ftell(archivo) / tamObjeto;

    fclose(archivo);

    return cantidad;
}

/* Don't know how i could make it without knowking the type
int buscarRegistro(void* obj, size_t tam, const char* nombreArchivo, void* pId, int id) {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        return -2;
    }

    int posicion = 0;

    while (fread(obj, tam, 1, archivo)) {
        if (id == *(int*)pId) {
            return posicion;
        }

        ++posicion;
    }

    fclose(archivo);

    return -1;
}
*/
