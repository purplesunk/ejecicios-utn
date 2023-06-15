#include "archivoPais.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "archivo_utils.h"
#include "clasePais.h"

#include "interfaz.h"

ArchivoPais::ArchivoPais(const char *nuevoArchivo) {
  int tam = strlen(nuevoArchivo) + 1;

  nombre = new char[tam];
  if (nombre == NULL) {
    exit(1); // ver como hacer con este error :)
  }

  strncpy(nombre, nuevoArchivo, tam);
}

ArchivoPais::~ArchivoPais() { delete nombre; }


void ArchivoPais::agregarRegistro() {
  int autoId = contarRegistros();
  if (autoId == -1) {
    autoId = 1;
  } else {
    ++autoId;
  }

  Pais obj;
  obj.Cargar(autoId);

  int pos = buscarRegistro(obj.getId());
  if (pos == -2) {
    mostrarAviso("\nEL ARCHIVO NO SE ENCONTRO. CREANDO ARCHIVO.\n");
  } else if (pos != -1) {
    mostrarAviso("\nYA HAY UN REGISTRO CON ESE ID.\n");
    return;
  }

  int agregado = appendRegistro(&obj, sizeof(obj), nombre);
  if (agregado == -1) {
    mostrarAviso("\nNO SE PUDO ABRIR EL ARCHIVO.\n");
  } else if (agregado == 0) {
    mostrarAviso("\nNO SE PUDO AGREGAR EL REGISTRO.\n");
  }
}


void ArchivoPais::mostrarRegistros() {
  std::cout << '\n';
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    mostrarAviso("NO SE PUDO LEER EL ARCHIVO.\n");
    return;
  }
  Pais obj;
  mostrarAviso("PAISES");
  std::cout << "\n\n";
  while (fread(&obj, sizeof obj, 1, archivo) == 1) {
    if (obj.getEstado()) {
      obj.Mostrar();
      std::cout << '\n';
    }
  }
  fclose(archivo);
}


Pais ArchivoPais::leerRegistro(int pos) {
  Pais obj;
  if (pos < 0) {
    obj.setId(-3);
    return obj;
  }

  int leido = readRegistro(&obj, sizeof(obj), pos, nombre);
  if (leido == -1) {
    obj.setId(-1);
  } else if (leido == 0) {
    obj.setId(-2);
  }
  return obj;
}


int ArchivoPais::buscarRegistro(int id) {
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    return -2;
  }

  int pos = 0;
  Pais obj;
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

int ArchivoPais::modificarRegistro(Pais obj, int pos) {
  return modifyRegistro(&obj, sizeof(obj), pos, nombre);
}

int ArchivoPais::contarRegistros() {
  return numeroRegistros(nombre, sizeof(Pais));
}


void ArchivoPais::buscarPorID() {
  std::cout << '\n';
  int ID = cargarInt("INGRESE EL ID A BUSCAR: ");

  int pos = buscarRegistro(ID);
  if (pos == -2) {
    mostrarAviso("NO SE PUDO ABRIR EL ARCHIVO.\n");
    return;
  } else if (pos == -1) {
    mostrarAviso("NO SE ENCONTRO EL REGISTRO.\n");
    return;
  }

  Pais obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    mostrarAviso("REGISTRO DADO DE BAJA.\n");
    return;
  }

  if (obj.getId() > 0) {
    std::cout << '\n';
    obj.Mostrar();
  } else if (obj.getId() == -3) {
    mostrarAviso("SE PUSO UNA POSICION INVALIDA.\n");
  } else if (obj.getId() == -1) {
    mostrarAviso("NO SE PUDO LEER EL REGISTRO.\n");
  } else {
    mostrarAviso("NO SE PUDO ABRIR EL ARCHIVO.\n");
  }
}

bool ArchivoPais::bajaLogica() {
  std::cout << '\n';
  int id = cargarInt("INGRESE EL ID A BUSCAR: ");

  int pos = buscarRegistro(id);
  if (pos == -1) {
    mostrarAviso("NO EXISTE PAIS CON ESE ID.\n");
    return false;
  }
  if (pos == -2) {
    mostrarAviso("NO SE PUDO ABRIR ARCHIVO.\n");
    return false;
  }

  Pais obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    mostrarAviso("EL PAIS INGRESADO YA ESTA DADO DE BAJA.\n");
    return false;
  } else {
    obj.setEstado(false);
  }

  int modificado = modificarRegistro(obj, pos);
  if (modificado == -1) {
    mostrarAviso("NO SE PUDO REABRIR EL ARCHIVO.\n");
    return false;
  } else if (modificado == 0){
    return false;
  } else {
    return true;
  }
}

bool ArchivoPais::modificarNombre() {
  std::cout << '\n';
  int id = cargarInt("INGRESE EL ID A BUSCAR: ");

  int pos = buscarRegistro(id);
  if (pos == -1) {
    mostrarAviso("NO EXISTE PAIS CON ESE ID.\n");
    return false;
  }
  if (pos == -2) {
    mostrarAviso("NO SE PUDO ABRIR ARCHIVO.\n");
    return false;
  }

  Pais obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    mostrarAviso("EL PAIS INGRESADO YA ESTA DADO DE BAJA.\n");
    return false;
  } else {
    char nuevo_nombre[30];
    mostrarAviso("NUEVO NOMBRE: ");
    cargarCadena(nuevo_nombre, 30);
    obj.setNombre(nuevo_nombre);
  }

  int modificado = modificarRegistro(obj, pos);
  if (modificado == -1) {
    mostrarAviso("NO SE PUDO REABRIR EL ARCHIVO.\n");
    return false;
  } else if (modificado == 0){
    return false;
  } else {
    return true;
  }
}

bool ArchivoPais::copiaSeguridad() {
  const char *backup = agregarExtensionBackup(nombre);

  Pais obj;
  bool copiado = copiarArchivo(nombre, backup, &obj, sizeof(obj));

  delete backup;

  return copiado;
}

bool ArchivoPais::restaurarCopia() {
  const char *backup = agregarExtensionBackup(nombre);

  Pais obj;
  bool restaurado = copiarArchivo(backup, nombre, &obj, sizeof(obj));

  delete backup;

  return restaurado;
}

bool ArchivoPais::restaurarInicio() {
  Pais obj;
  return copiarArchivo("datosInicialesPaises.dat", nombre, &obj, sizeof(obj));
}

int ArchivoPais::seleccionarRegistro(int posx, int posy, int boxWidth, int boxHeight) {
  int cantActivos = 0;
  int cantRegistros = contarRegistros();
  Pais *vRegistros = new Pais[cantRegistros];
  if (vRegistros == NULL) {
    return -1;
  }
  for (int i = 0; i < cantRegistros; ++i) {
    vRegistros[cantActivos] = leerRegistro(i);
    if (vRegistros[cantActivos].getEstado()) {
      ++cantActivos;
    }
  }

  int tamNombres = 50;
  char *long_string = new char[tamNombres * cantActivos];
  char **nombreRegistros = new char*[cantActivos];
  for (int i = 0; i < cantActivos; ++i) {
    nombreRegistros[i] = (long_string + (tamNombres * i));
  }

  for (int i = 0; i < cantActivos; ++i) {
    strncpy(nombreRegistros[i], vRegistros[i].getNombre(), tamNombres);
  }

  int seleccionado = seleccionarObjeto(posx, posy, boxWidth, boxHeight, nombreRegistros, cantActivos, "SELECCIONAR PAIS");
  int id_seleccionado = vRegistros[seleccionado].getId();

  delete[] long_string;
  delete[] nombreRegistros;
  delete[] vRegistros;

  return id_seleccionado;
}
