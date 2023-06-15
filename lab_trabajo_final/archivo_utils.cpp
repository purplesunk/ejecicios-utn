#include "archivo_utils.h"

#include <cstring>
#include <iostream>

bool copiarArchivo(const char *fuente, const char *destino, void *obj, size_t tam) {
  FILE *archivo = fopen(fuente, "rb");
  if (archivo == NULL) {
    std::cout << "  NO SE PUDO ABRIR EL ARCHIVO " << fuente << '\n';
    return false;
  }

  FILE *copia = fopen(destino, "wb");
  if (copia == NULL) {
    std::cout << "  NO SE PUDO CREAR EL ARCHIVO PARA COPIAR " << destino << '\n';
    fclose(archivo);
    return false;
  }

  while (fread(obj, tam, 1, archivo)) {
    fwrite(obj, tam, 1, copia);
  }

  fclose(archivo);
  fclose(copia);

  return true;
}

int numeroRegistros(const char *nombre, size_t tam) {
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    return -1;
  }

  fseek(archivo, 0, SEEK_END);

  int cantidad = ftell(archivo) / tam;

  fclose(archivo);

  return cantidad;
}

int appendRegistro(void* obj, size_t tam, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "ab");
    if (archivo == NULL) {
        return -1;
    }

    int agregado = fwrite(obj, tam, 1, archivo);

    fclose(archivo);

    return agregado;
}

int modifyRegistro(void* obj, size_t tam, int pos, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "rb+");
    if (archivo == NULL) {
        return -1;
    }

    fseek(archivo, tam * pos, SEEK_SET);

    int modificado = fwrite(obj, tam, 1, archivo);

    fclose(archivo);

    return modificado;
}

int readRegistro(void* obj, size_t tam, int pos, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        return -1;
    }

    fseek(archivo, tam * pos, SEEK_SET);

    int leido = fread(obj, tam, 1, archivo);

    fclose(archivo);

    return leido;
}

const char *agregarExtensionBackup(const char *nombreArchivo) {
  const char *extension_bkp = ".bkp";
  int tam_extension_bkp = strlen(extension_bkp) + sizeof('\0');

  char extension[5];
  int tam_nombre = strlen(nombreArchivo) + sizeof('\0');
  for (int i = 0, n = sizeof(extension); i < n; ++i) {
    extension[i] = nombreArchivo[tam_nombre - n + i];
  }

  // Checkear si el nombre del archivo tiene .dat
  // Si tiene reemplazar por .bkp, sino agregar extension
  // Meibi i should see this function and only add .bkp
  char *backup = {};
  if (strcmp(extension, ".dat") == 0) {
    backup = new char[tam_nombre];
    if (backup == NULL) {
      exit(1);
    }

    strncpy(backup, nombreArchivo, tam_nombre - tam_extension_bkp);
    strncat(backup, extension_bkp, tam_extension_bkp);
  } else {
    backup = new char[tam_nombre + tam_extension_bkp - sizeof('\0')];
    strncpy(backup, nombreArchivo, tam_nombre);
    strncat(backup, extension_bkp, tam_extension_bkp);
  }

  return backup;
}
