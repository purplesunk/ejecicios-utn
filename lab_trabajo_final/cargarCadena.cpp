#include "cargarCadena.h"

#include <cstring>
#include <iostream>

#include "claseGeneroMusical.h"
#include "claseInstrumento.h"
#include "claseMusico.h"
#include "clasePais.h"

void ignoreLine() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

void cargarCadena(char *cadena, int tam) {
  std::cin.getline(cadena, tam);
  if (!std::cin) {
    std::cin.clear();
    ignoreLine();
  }
}

int cargarInt(const char *pregunta) {
  int numero;
  std::cout << pregunta;
  std::cin >> numero;

  while (!std::cin) {
    std::cin.clear();
    ignoreLine();
    std::cout << pregunta;
    std::cin >> numero;
  }

  ignoreLine();
  return numero;
}

float cargarFloat(const char *pregunta) {
  float numero;
  std::cout << pregunta;
  std::cin >> numero;

  while (!std::cin) {
    std::cin.clear();
    ignoreLine();
    std::cout << pregunta;
    std::cin >> numero;
  }

  ignoreLine();
  return numero;
}

bool copiarArchivo(const char *fuente, const char *destino, void *obj,
                   size_t tam) {
  FILE *archivo = fopen(fuente, "rb");
  if (archivo == NULL) {
    std::cout << "No se pudo abrir el archivo.\n";
    return false;
  }

  FILE *copia = fopen(destino, "wb");
  if (copia == NULL) {
    std::cout << "No se pudo crear el archivo para copiar.\n";
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

bool restablecerInicio() {
  GeneroMusical obj;
  bool generos = copiarArchivo("datosInicialesGeneros.dat", "generos.dat", &obj,
                               sizeof(obj));

  Musico obj2;
  bool musicos = copiarArchivo("datosInicialesMusicos.dat", "musicos.dat",
                               &obj2, sizeof(obj2));

  return (generos && musicos);
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
