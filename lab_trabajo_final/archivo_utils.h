#ifndef ARCHIVO_UTILS_H_INCLUDED
#define ARCHIVO_UTILS_H_INCLUDED

#include <iostream>

bool copiarArchivo(const char *fuente, const char *destino, void *obj, size_t tam);

int numeroRegistros(const char *nombre, size_t tam);

int readRegistro(void* obj, size_t tam, int pos, const char* nombreArchivo);

int modifyRegistro(void* obj, size_t tam, int pos, const char* nombreArchivo);

int appendRegistro(void* obj, size_t tam, const char* nombreArchivo);

const char *agregarExtensionBackup(const char *nombreArchivo);

#endif
