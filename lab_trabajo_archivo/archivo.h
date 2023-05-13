#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <cstddef>

bool agregarRegistro(void* obj, size_t tam, const char* archivo);
bool modificarRegistro(void* obj, size_t tam, int pos, const char* nombreArchivo);
bool leerRegistro(void* obj, size_t tam, int pos, const char* nombreArchivo);
int contarRegistros(const char* nombreArchivo, size_t tam);

#endif
