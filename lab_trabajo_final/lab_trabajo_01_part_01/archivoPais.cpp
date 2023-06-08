#include "archivoPais.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "claseFecha.h"
#include "clasePais.h"

ArchivoPaises::ArchivoPaises(const char *nuevoArchivo) {
  strncpy(nombre, nuevoArchivo, 30);
}

void ArchivoPaises::agregarRegistro() {
  int autoId = contarRegistros();
  if (autoId == -1) {
    autoId = 1;
  } else {
    ++autoId;
  }

  std::cout << " Ingrese los datos del género musical: \n";
  std::cout << "-----------------------------------------\n";

  Pais obj;
  obj.Cargar(autoId);

  int pos = buscarRegistro(obj.getId());

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

  fwrite(&obj, sizeof(Pais), 1, fileGeneroMusical);

  fclose(fileGeneroMusical);
}

void ArchivoPaises::mostrarRegistros() {
  FILE *fileGeneroMusical = fopen(nombre, "rb");
  if (fileGeneroMusical == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO.\n";
    return;
  }

  Pais obj;
  while (fread(&obj, sizeof obj, 1, fileGeneroMusical) == 1) {
    if (obj.getEstado()) {
      obj.Mostrar();
      std::cout << "-----------------------------------\n";
    }
  }
  fclose(fileGeneroMusical);
}

Pais ArchivoPaises::leerRegistro(int p) {
  Pais obj;

  if (p < 0) {
    obj.setId(-3);
    return obj;
  }

  FILE *fileGeneroMusical = fopen(nombre, "rb");
  if (fileGeneroMusical == NULL) {
    obj.setId(-2);
    return obj;
  }

  fseek(fileGeneroMusical, (sizeof(Pais) * p), SEEK_SET);

  if (!fread(&obj, sizeof(Pais), 1, fileGeneroMusical)) {
    obj.setId(-1);
  }

  fclose(fileGeneroMusical);

  return obj;
}

int ArchivoPaises::buscarRegistro(int id) {
  FILE *fileGeneroMusical = fopen(nombre, "rb");
  if (fileGeneroMusical == NULL) {
    return -2;
  }

  int pos = 0;
  Pais obj;

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

bool ArchivoPaises::modificarRegistro(Pais obj, int pos) {
  FILE *fileGeneroMusical = fopen(nombre, "rb+");
  if (fileGeneroMusical == NULL) {
    std::cout << "ERROR AL REABRIR EL ARCHIVO.\n";
    return false;
  }

  fseek(fileGeneroMusical, sizeof(Pais) * pos, SEEK_SET);

  bool aux = fwrite(&obj, sizeof(Pais), 1, fileGeneroMusical);
  fclose(fileGeneroMusical);

  return aux;
}

int ArchivoPaises::contarRegistros() {
  FILE *generos = fopen(nombre, "rb");
  if (generos == NULL) {
    return -1;
  }

  fseek(generos, 0, SEEK_END);

  int cantidad = ftell(generos) / sizeof(Pais);

  fclose(generos);

  return cantidad;
}

void ArchivoPaises::buscarPorID() {
  int ID = cargarInt("INGRESE EL ID A BUSCAR: ");

  int pos = buscarRegistro(ID);
  if (pos == -2) {
    std::cout << "No se pudo abrir el archivo.\n";
    return;
  } else if (pos == -1) {
    std::cout << "No se encontró el registro.\n";
    return;
  }

  Pais obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    std::cout << "Registro dado de baja.\n";
    return;
  }

  if (obj.getId() > 0) {
    std::cout << "---------------------------------\n";
    obj.Mostrar();
    std::cout << "---------------------------------\n";

  } else if (obj.getId() == -3) {
    std::cout << "Se puso una posición inválida.\n";
  } else if (obj.getId() == -1) {
    std::cout << "No se pudo leer el registro.\n";
  } else {
    std::cout << "No se pudo abrir el archivo.\n";
  }
}

bool ArchivoPaises::bajaLogica() {
  // Solicitar que registro se quiere dar de baja
  int id = cargarInt("INGRESE EL ID A BUSCAR: ");

  // Buscar el registro en el archivo
  int pos = buscarRegistro(id);
  if (pos == -1) {
    std::cout << "NO EXISTE GENERO CON ESE ID.\n";
    return false;
  }
  if (pos == -2) {
    std::cout << "NO SE PUDO ABRIR ARCHIVO.\n";
    return false;
  }

  Pais obj = leerRegistro(pos);

  if (obj.getEstado() == false) {
    std::cout << "EL GENERO INGRESADO YA ESTA DADO DE BAJA.\n";
    return false;
  }

  // Modificarmos el campo estado (lo ponemos en false)
  obj.setEstado(false);

  // Sobreescribir
  return modificarRegistro(obj, pos);
}

bool ArchivoPaises::modificarContinente() {
  int ID = cargarInt("Ingrese el ID a buscar: ");

  int pos = buscarRegistro(ID);
  if (pos == -1) {
    std::cout << "No existe genero con ese ID.\n";
    return false;
  }
  if (pos == -2) {
    std::cout << "No se pudo abrir el archivo.\n";
    return false;
  }

  Pais obj = leerRegistro(pos);

  if (!obj.getEstado()) {
    std::cout << "Registro dado de baja.\n";
    return false;
  }

  std::cout << "---------------------------------------------------------------"
               "----\n";
  std::cout << "Pais: " << obj.getNombre() << '\n';
  std::cout << "Continente Actual: " << obj.getContinente() << '\n';
  std::cout << "---------------------------------------------------------------"
               "----\n";

  char continente[30];
  std::cout << "Ingrese nuevo contienente: ";
  cargarCadena(continente, 30);

  obj.setContinente(continente);

  return modificarRegistro(obj, pos);
}

bool ArchivoPaises::modificarNombre() {
  int ID = cargarInt("Ingrese el ID a buscar: ");

  int pos = buscarRegistro(ID);
  if (pos == -1) {
    std::cout << "No existe genero con ese ID.\n";
    return false;
  }
  if (pos == -2) {
    std::cout << "No se pudo abrir el archivo.\n";
    return false;
  }

  Pais obj = leerRegistro(pos);

  if (!obj.getEstado()) {
    std::cout << "Registro dado de baja.\n";
    return false;
  }

  std::cout << "---------------------------------------------------------------"
               "----\n";
  std::cout << "Nombre Actual: " << obj.getNombre() << '\n';
  std::cout << "Continente: " << obj.getContinente() << '\n';
  std::cout << "---------------------------------------------------------------"
               "----\n";

  char nombre[30];
  std::cout << "Ingrese nuevo nombre: ";
  cargarCadena(nombre, 30);

  obj.setNombre(nombre);

  return modificarRegistro(obj, pos);
}
