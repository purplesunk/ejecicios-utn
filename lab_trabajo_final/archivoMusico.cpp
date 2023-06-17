#include "archivoMusico.h"

#include <cstring>
#include <iostream>

#include "archivo_utils.h"
#include "cargarCadena.h"
#include "claseFecha.h"
#include "claseMusico.h"

#include "interfaz.h"

ArchivoMusico::ArchivoMusico(const char *nuevoArchivo) {
  int tam = strlen(nuevoArchivo) + 1;

  nombre = new char[tam];
  if (nombre == NULL) {
    exit(1); // ver como hacer con este error :)
  }

  strncpy(nombre, nuevoArchivo, tam);
}

ArchivoMusico::~ArchivoMusico() { delete nombre; }

void ArchivoMusico::agregarRegistro() {
  Musico obj;
  obj.Cargar();
  if (obj.getDni() == -1) {
    mostrarAviso("  NO SE CARGO EL REGISTRO.\n");
    return;
  }

  int pos = buscarRegistro(obj.getDni());
  if (pos == -2) {
    mostrarAviso("  EL ARCHIVO NO SE ENCONTRO. CREANDO ARCHIVO.\n");
  } else if (pos != -1) {
    mostrarAviso("  YA HAY UN REGISTRO CON ESE DNI.\n");
    return;
  }

  int agregado = appendRegistro(&obj, sizeof(obj), nombre);
  if (agregado == -1) {
    mostrarAviso("  NO SE PUDO ABRIR EL ARCHIVO.\n");
  } else if (agregado == 0) {
    mostrarAviso("  NO SE PUDO AGREGAR EL REGISTRO.\n");
  }
}


void ArchivoMusico::mostrarRegistros() {
  std::cout << '\n';
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    mostrarAviso("  NO SE PUDO LEER EL ARCHIVO.\n");
    return;
  }
  Musico obj;
  mostrarAviso("  MUSICOS");
  std::cout << "\n\n";
  while (fread(&obj, sizeof obj, 1, archivo) == 1) {
    if (obj.getEstado()) {
      obj.Mostrar();
      std::cout << '\n';
    }
  }
  fclose(archivo);
}


Musico ArchivoMusico::leerRegistro(int pos) {
  Musico obj;
  if (pos < 0) {
    obj.setDNI(-3);
    return obj;
  }

  int leido = readRegistro(&obj, sizeof(obj), pos, nombre);
  if (leido == -1) {
    obj.setDNI(-1);
  } else if (leido == 0) {
    obj.setDNI(-2);
  }
  return obj;
}


int ArchivoMusico::buscarRegistro(int id) {
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    return -2;
  }

  int pos = 0;
  Musico obj;
  while (fread(&obj, sizeof(obj), 1, archivo) == 1) {
    if (id == obj.getDni()) {
      fclose(archivo);
      return pos;
    }
    ++pos;
  }
  fclose(archivo);
  return -1;
}

int ArchivoMusico::modificarRegistro(Musico obj, int pos) {
  return modifyRegistro(&obj, sizeof(obj), pos, nombre);
}

int ArchivoMusico::contarRegistros() {
  return numeroRegistros(nombre, sizeof(Musico));
}


void ArchivoMusico::buscarPorDNI() {
  std::cout << '\n';
  int DNI = cargarInt("INGRESE EL DNI A BUSCAR: ");

  int pos = buscarRegistro(DNI);
  if (pos == -2) {
    mostrarAviso("  NO SE PUDO ABRIR EL ARCHIVO.\n");
    return;
  } else if (pos == -1) {
    mostrarAviso("  NO SE ENCONTRO EL REGISTRO.\n");
    return;
  }

  Musico obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    mostrarAviso("  REGISTRO DADO DE BAJA.\n");
    return;
  }

  int dni = obj.getDni();
  if (dni > 0) {
    std::cout << '\n';
    obj.Mostrar();
  } else if (dni == -3) {
    mostrarAviso("  SE PUSO UNA POSICION INVALIA.\n");
  } else if (dni == -1) {
    mostrarAviso("  NO SE PUDO LEER EL REGISTRO.\n");
  } else {
    mostrarAviso("  NO SE PUDO ABRIR EL ARCHIVO.\n");
  }
}

bool ArchivoMusico::bajaLogica() {
  std::cout << '\n';
  int id = cargarInt("INGRESE EL DNI A BUSCAR: ");

  int pos = buscarRegistro(id);
  if (pos == -1) {
    mostrarAviso("  NO EXISTE MUSICO CON ESE DNI.\n");
    return false;
  }
  if (pos == -2) {
    mostrarAviso("  NO SE PUDO ABRIR ARCHIVO.\n");
    return false;
  }

  Musico obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    mostrarAviso("  EL MUSICO INGRESADO YA ESTA DADO DE BAJA.\n");
    return false;
  } else {
    obj.setEstado(false);
  }

  int modificado = modificarRegistro(obj, pos);
  if (modificado == -1) {
    mostrarAviso("  NO SE PUDO REABRIR EL ARCHIVO.\n");
    return false;
  } else if (modificado == 0){
    return false;
  } else {
    return true;
  }
}

bool ArchivoMusico::modificarFecha() {
  std::cout << '\n';
  int dni = cargarInt("INGRESE EL DNI A BUSCAR: ");

  int pos = buscarRegistro(dni);
  if (pos == -1) {
    mostrarAviso("  NO EXISTE MUSICO CON ESE DNI.\n");
    return false;
  } else if (pos == -2) {
    mostrarAviso("  NO SE PUDO ABRIR ARCHIVO.\n");
    return false;
  }

  Musico obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    mostrarAviso("  EL MUSICO INGRESADO YA ESTA DADO DE BAJA.\n");
    return false;
  } else {
    Fecha nuevaFecha;
    mostrarAviso("  INGRESE LA NUEVA FECHA DE INSCRIPCION:\n");
    nuevaFecha.CargaValida();
    obj.setFechaInscripcion(nuevaFecha);
  }

  int modificado = modificarRegistro(obj, pos);
  if (modificado == -1) {
    mostrarAviso("  NO SE PUDO REABRIR EL ARCHIVO.\n");
    return false;
  } else if (modificado == 0){
    return false;
  } else {
    return true;
  }
}

bool ArchivoMusico::copiaSeguridad() {
  const char *backup = agregarExtensionBackup(nombre);
  Musico obj;

  bool copiado = copiarArchivo(nombre, backup, &obj, sizeof(obj));

  delete backup;
  return copiado;
}

bool ArchivoMusico::restaurarCopia() {
  const char *backup = agregarExtensionBackup(nombre);

  Musico obj;
  bool restaurado = copiarArchivo(backup, nombre, &obj, sizeof(obj));

  delete backup;
  return restaurado;
}

bool ArchivoMusico::restaurarInicio() {
  Musico obj;
  return copiarArchivo("datosInicialesMusicos.dat", nombre, &obj, sizeof(obj));
}
