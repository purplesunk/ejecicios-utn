#include "archivoInstrumento.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "claseFecha.h"
#include "claseInstrumento.h"

ArchivoInstrumento::ArchivoInstrumento(const char *nuevoArchivo) {
  strncpy(nombre, nuevoArchivo, 30);
}

void ArchivoInstrumento::agregarRegistro() {
  int autoId = contarRegistros();
  if (autoId == -1) {
    autoId = 1;
  } else {
    ++autoId;
  }

  std::cout << " Ingrese los datos del instrumento musical: \n";
  std::cout << "---------------------------------------------\n";

  Instrumento obj;
  obj.Cargar(autoId);

  int pos = buscarRegistro(obj.getId());

  if (pos == -2) {
    std::cout << "El archivo no se encontro. Creando archivo.\n";
  } else if (pos != -1) {
    std::cout << "Ya hay un registro con ese ID.\n";
    return;
  }

  FILE *archivo = fopen(nombre, "ab");
  if (archivo == NULL) {
    std::cout << "No se pudo abrir el archivo.\n";
    return;
  }

  fwrite(&obj, sizeof(Instrumento), 1, archivo);

  fclose(archivo);
}

void ArchivoInstrumento::mostrarRegistros() {
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO.\n";
    return;
  }

  Instrumento obj;
  while (fread(&obj, sizeof obj, 1, archivo) == 1) {
    if (obj.getEstado()) {
      obj.Mostrar();
      std::cout << "-----------------------------------\n";
    }
  }
  fclose(archivo);
}

Instrumento ArchivoInstrumento::leerRegistro(int p) {
  Instrumento obj;

  if (p < 0) {
    obj.setId(-3);
    return obj;
  }

  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    obj.setId(-2);
    return obj;
  }

  fseek(archivo, (sizeof(Instrumento) * p), SEEK_SET);

  if (!fread(&obj, sizeof(Instrumento), 1, archivo)) {
    obj.setId(-1);
  }

  fclose(archivo);

  return obj;
}

int ArchivoInstrumento::buscarRegistro(int id) {
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    return -2;
  }

  int pos = 0;
  Instrumento obj;

  while (fread(&obj, sizeof(obj), 1, archivo) == 1) {
    if (id == obj.getId()) {
      fclose(archivo);
      return pos;
    }
    ++pos;
  }

  fclose(archivo);

  return -1;
}

bool ArchivoInstrumento::modificarRegistro(Instrumento obj, int pos) {
  FILE *archivo = fopen(nombre, "rb+");
  if (archivo == NULL) {
    std::cout << "ERROR AL REABRIR EL ARCHIVO.\n";
    return false;
  }

  fseek(archivo, sizeof(Instrumento) * pos, SEEK_SET);

  bool aux = fwrite(&obj, sizeof(Instrumento), 1, archivo);
  fclose(archivo);

  return aux;
}

int ArchivoInstrumento::contarRegistros() {
  FILE *generos = fopen(nombre, "rb");
  if (generos == NULL) {
    return -1;
  }

  fseek(generos, 0, SEEK_END);

  int cantidad = ftell(generos) / sizeof(Instrumento);

  fclose(generos);

  return cantidad;
}

void ArchivoInstrumento::buscarPorID() {
  int ID = cargarInt("INGRESE EL ID A BUSCAR: ");

  int pos = buscarRegistro(ID);
  if (pos == -2) {
    std::cout << "No se pudo abrir el archivo.\n";
    return;
  } else if (pos == -1) {
    std::cout << "No se encontró el registro.\n";
    return;
  }

  Instrumento obj = leerRegistro(pos);
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

bool ArchivoInstrumento::bajaLogica() {
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

  Instrumento obj = leerRegistro(pos);

  if (obj.getEstado() == false) {
    std::cout << "EL GENERO INGRESADO YA ESTA DADO DE BAJA.\n";
    return false;
  }

  // Modificarmos el campo estado (lo ponemos en false)
  obj.setEstado(false);

  // Sobreescribir
  return modificarRegistro(obj, pos);
}

bool ArchivoInstrumento::modificarClasificacion() {
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

  Instrumento obj = leerRegistro(pos);

  if (!obj.getEstado()) {
    std::cout << "Registro dado de baja.\n";
    return false;
  }

  std::cout << "---------------------------------------------------------------"
               "----\n";
  std::cout << "Genero: " << obj.getNombre() << '\n';
  std::cout << "Año de origen actual: " << obj.getClasificacion() << '\n';
  std::cout << "---------------------------------------------------------------"
               "----\n";

  int nuevoAnio = cargarInt("Ingresar nuevo año de origen: ");
  obj.setClasificacion(nuevoAnio);

  return modificarRegistro(obj, pos);
}
