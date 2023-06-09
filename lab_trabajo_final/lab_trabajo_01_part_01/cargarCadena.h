#ifndef CARGARCADENA_H_INCLUDED
#define CARGARCADENA_H_INCLUDED

#include <iostream>

void ignoreLine();

void cargarCadena(char *cadena, int tam);

int cargarInt(const char *pregunta);

float cargarFloat(const char *pregunta);

bool copiarArchivo(const char *fuente, const char *destino, void *obj,
                   size_t tam);

bool restablecerInicio();

const char *agregarExtensionBackup(const char *nombreArchivo);

#endif
