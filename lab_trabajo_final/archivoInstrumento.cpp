#include "archivoInstrumento.h"

#include <cstring>
#include <iostream>

#include "archivo_utils.h"
#include "cargarCadena.h"
#include "claseInstrumento.h"
#include "interfaz.h"

ArchivoInstrumento::ArchivoInstrumento(const char *nuevoArchivo) {
  int tam = strlen(nuevoArchivo) + 1;

  nombre = new char[tam];
  if (nombre == NULL) {
    exit(1); // ver como hacer con este error :)
  }

  strncpy(nombre, nuevoArchivo, tam);
}

ArchivoInstrumento::~ArchivoInstrumento() { delete nombre; }


void ArchivoInstrumento::agregarRegistro() {
  int autoId = contarRegistros();
  if (autoId == -1) {
    autoId = 1;
  } else {
    ++autoId;
  }

  Instrumento obj;
  obj.Cargar(autoId);

  int pos = buscarRegistro(obj.getId());
  if (pos == -2) {
    mostrarAviso("  EL ARCHIVO NO SE ENCONTRO. CREANDO ARCHIVO.\n");
  } else if (pos != -1) {
    mostrarAviso("  YA HAY UN REGISTRO CON ESE ID.\n");
    return;
  }

  int agregado = appendRegistro(&obj, sizeof(obj), nombre);
  if (agregado == -1) {
    mostrarAviso("  NO SE PUDO ABRIR EL ARCHIVO.\n");
  } else if (agregado == 0) {
    mostrarAviso("  NO SE PUDO AGREGAR EL REGISTRO.\n");
  }
}


void ArchivoInstrumento::mostrarRegistros() {
  std::cout << '\n';
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    mostrarAviso("  NO SE PUDO LEER EL ARCHIVO.\n");
    return;
  }
  Instrumento obj;
  mostrarAviso("  INSTRUMENTOS");
  std::cout << "\n\n";
  while (fread(&obj, sizeof obj, 1, archivo) == 1) {
    if (obj.getEstado()) {
      obj.Mostrar();
      std::cout << '\n';
    }
  }
  fclose(archivo);
}


Instrumento ArchivoInstrumento::leerRegistro(int pos) {
  Instrumento obj;
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

int ArchivoInstrumento::modificarRegistro(Instrumento obj, int pos) {
  return modifyRegistro(&obj, sizeof(obj), pos, nombre);
}

int ArchivoInstrumento::contarRegistros() {
  return numeroRegistros(nombre, sizeof(Instrumento));
}


void ArchivoInstrumento::buscarPorID() {
  std::cout << '\n';
  int ID = cargarInt("INGRESE EL ID A BUSCAR: ");

  int pos = buscarRegistro(ID);
  if (pos == -2) {
    mostrarAviso("  NO SE PUDO ABRIR EL ARCHIVO.\n");
    return;
  } else if (pos == -1) {
    mostrarAviso("  NO SE ENCONTRO EL REGISTRO.\n");
    return;
  }

  Instrumento obj = leerRegistro(pos);
  if (obj.getEstado() == false) {
    mostrarAviso("  REGISTRO DADO DE BAJA.\n");
    return;
  }

  if (obj.getId() > 0) {
    std::cout << '\n';
    obj.Mostrar();
  } else if (obj.getId() == -3) {
    mostrarAviso("  SE PUSO UNA POSICION INVALIDA.\n");
  } else if (obj.getId() == -1) {
    mostrarAviso("  NO SE PUDO LEER EL REGISTRO.\n");
  } else {
    mostrarAviso("  NO SE PUDO ABRIR EL ARCHIVO.\n");
  }
}

bool ArchivoInstrumento::bajaLogica() {
  std::cout << '\n';
  int id = cargarInt("INGRESE EL ID A BUSCAR: ");

  int pos = buscarRegistro(id);
  if (pos == -1) {
    mostrarAviso("  NO EXISTE INSTRUMENTO CON ESE ID.\n");
    return false;
  }
  if (pos == -2) {
    mostrarAviso("  NO SE PUDO ABRIR ARCHIVO.\n");
    return false;
  }

  Instrumento obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    mostrarAviso("  EL INSTRUMENTO INGRESADO YA ESTA DADO DE BAJA.\n");
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

bool ArchivoInstrumento::modificarNombre() {
  std::cout << '\n';
  int id = cargarInt("INGRESE EL ID A BUSCAR: ");

  int pos = buscarRegistro(id);
  if (pos == -1) {
    mostrarAviso("  NO EXISTE INSTRUMENTO CON ESE ID.\n");
    return false;
  }
  if (pos == -2) {
    mostrarAviso("  NO SE PUDO ABRIR ARCHIVO.\n");
    return false;
  }

  Instrumento obj = leerRegistro(pos);
  if (obj.getEstado() == false) {
    mostrarAviso("  EL INSTRUMENTO INGRESADO YA ESTA DADO DE BAJA.\n");
    return false;
  } else {
    char nuevo_nombre[30];
    mostrarAviso("  NUEVO NOMBRE: ");
    cargarCadena(nuevo_nombre, 30);
    obj.setNombre(nuevo_nombre);
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

bool ArchivoInstrumento::copiaSeguridad() {
  const char *backup = agregarExtensionBackup(nombre);

  Instrumento obj;
  bool copiado = copiarArchivo(nombre, backup, &obj, sizeof(obj));

  delete backup;
  return copiado;
}

bool ArchivoInstrumento::restaurarCopia() {
  const char *backup = agregarExtensionBackup(nombre);

  Instrumento obj;
  bool restaurado = copiarArchivo(backup, nombre, &obj, sizeof(obj));

  delete backup;
  return restaurado;
}

bool ArchivoInstrumento::restaurarInicio() {
  Instrumento obj;
  return copiarArchivo("datosInicialesInstrumentos.dat", nombre, &obj, sizeof(obj));
}

int ArchivoInstrumento::seleccionarRegistro(int posx, int posy, int boxWidth, int boxHeight) {
  int cantActivos = 0;
  int cantRegistros = contarRegistros();
  Instrumento *vRegistros = new Instrumento[cantRegistros];
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

  int seleccionado = seleccionarObjeto(posx, posy, boxWidth, boxHeight, nombreRegistros, cantActivos, "SELECCIONAR INSTRUMENTO");
  int id_seleccionado = vRegistros[seleccionado].getId();

  delete[] long_string;
  delete[] nombreRegistros;
  delete[] vRegistros;

  return id_seleccionado;
}
