#ifndef ARCHIVO_UTILS_H_INCLUDED
#define ARCHIVO_UTILS_H_INCLUDED

#include <iostream>

bool copiarArchivo(const char *fuente, const char *destino, void *obj, size_t tam);

int numeroRegistros(const char *nombre, size_t tam);

const char *agregarExtensionBackup(const char *nombreArchivo);

#endif
