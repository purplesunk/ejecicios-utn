#include "archivoGenero.h"

#include <cstring>
#include <iostream>

#include "archivo_utils.h"
#include "cargarCadena.h"
#include "claseGeneroMusical.h"

#include "interfaz.h"

ArchivoGeneroMusical::ArchivoGeneroMusical(const char *nuevoArchivo) {
  int tam = strlen(nuevoArchivo) + 1;
  nombre = new char[tam];
  if (nombre == NULL) {
    exit(1); // ver como hacer con este error :)
  }
  strncpy(nombre, nuevoArchivo, tam);
}
ArchivoGeneroMusical::~ArchivoGeneroMusical() { delete nombre; }

void ArchivoGeneroMusical::agregarRegistro() {
  int autoId = contarRegistros();
  if (autoId == -1) {
    autoId = 1;
  } else {
    ++autoId;
  }

  GeneroMusical obj;
  obj.Cargar(autoId);
  if (obj.getId() == -1) {
    mostrarAviso("  NO SE CARGO EL REGISTRO.\n");
    return;
  }

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


void ArchivoGeneroMusical::mostrarRegistros() {
  std::cout << '\n';
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    mostrarAviso("  NO SE PUDO LEER EL ARCHIVO.\n");
    return;
  }
  GeneroMusical obj;
  mostrarAviso("  GENEROS MUSICALES");
  std::cout << "\n\n";
  while (fread(&obj, sizeof obj, 1, archivo) == 1) {
    if (obj.getEstado()) {
      obj.Mostrar();
      std::cout << '\n';
    }
  }
  fclose(archivo);
}


GeneroMusical ArchivoGeneroMusical::leerRegistro(int pos) {
  GeneroMusical obj;
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


int ArchivoGeneroMusical::buscarRegistro(int id) {
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    return -2;
  }

  int pos = 0;
  GeneroMusical obj;
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

int ArchivoGeneroMusical::modificarRegistro(GeneroMusical obj, int pos) {
  return modifyRegistro(&obj, sizeof(obj), pos, nombre);
}

int ArchivoGeneroMusical::contarRegistros() {
  return numeroRegistros(nombre, sizeof(GeneroMusical));
}


void ArchivoGeneroMusical::buscarPorID() {
  int ID = cargaSeleccion("INGRESE EL ID A BUSCAR: ", 1, 2);

  int pos = buscarRegistro(ID);
  if (pos == -2) {
    mostrarAviso("  NO SE PUDO ABRIR EL ARCHIVO.\n");
    return;
  } else if (pos == -1) {
    mostrarAviso("  NO SE ENCONTRO EL REGISTRO.\n");
    return;
  }

  GeneroMusical obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    mostrarAviso("  REGISTRO DADO DE BAJA.\n");
    return;
  }

  if (obj.getId() > 0) {
    std::cout << '\n';
    obj.Mostrar();
  } else if (obj.getId() == -3) {
    mostrarAviso("  SE PUSO UNA POSICIÓN INVALIDA.\n");
  } else if (obj.getId() == -1) {
    mostrarAviso("  NO SE PUDO LEER EL REGISTRO.\n");
  } else {
    mostrarAviso("  NO SE PUDO ABRIR EL ARCHIVO.\n");
  }
}

bool ArchivoGeneroMusical::bajaLogica() {
  int id = cargaSeleccion("INGRESE EL ID A BUSCAR: ", 1, 2);

  int pos = buscarRegistro(id);
  if (pos == -1) {
    mostrarAviso("  NO EXISTE GENERO MUSICAL CON ESE ID.\n");
    return false;
  }
  if (pos == -2) {
    mostrarAviso("  NO SE PUDO ABRIR ARCHIVO.\n");
    return false;
  }

  GeneroMusical obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    mostrarAviso("  EL GENERO MUSICAL INGRESADO YA ESTA DADO DE BAJA.\n");
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

bool ArchivoGeneroMusical::modificarAnioOrigen() {
  int id = cargaSeleccion("INGRESE EL ID A BUSCAR: ", 1, 2);

  int pos = buscarRegistro(id);
  if (pos == -1) {
    mostrarAviso("  NO EXISTE GENERO MUSICAL CON ESE ID.\n");
    return false;
  } else if (pos == -2) {
    mostrarAviso("  NO SE PUDO ABRIR ARCHIVO.\n");
    return false;
  }

  GeneroMusical obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    mostrarAviso("  EL GENERO MUSICAL INGRESADO YA ESTA DADO DE BAJA.\n");
    return false;
  } else {
    int nuevoAnio = cargarInt("INGRESAR NUEVO ANIO DE ORIGEN: ");
    obj.setAnioOrigen(nuevoAnio);
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

bool ArchivoGeneroMusical::copiaSeguridad() {
  const char *backup = agregarExtensionBackup(nombre);

  GeneroMusical obj;
  bool copiado = copiarArchivo(nombre, backup, &obj, sizeof(obj));

  delete backup;
  return copiado;
}

bool ArchivoGeneroMusical::restaurarCopia() {
  const char *backup = agregarExtensionBackup(nombre);

  GeneroMusical obj;
  bool restaurado = copiarArchivo(backup, nombre, &obj, sizeof(obj));

  delete backup;
  return restaurado;
}

bool ArchivoGeneroMusical::restaurarInicio() {
  GeneroMusical obj;
  return copiarArchivo("datosInicialesGeneros.dat", nombre, &obj, sizeof(obj));
}

int ArchivoGeneroMusical::seleccionarRegistro(int posx, int posy, int boxWidth, int boxHeight) {
  int cantActivos = 0;
  int cantRegistros = contarRegistros();
  GeneroMusical *vRegistros = new GeneroMusical[cantRegistros];
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

  int seleccionado = seleccionarObjeto(posx, posy, boxWidth, boxHeight, nombreRegistros, cantActivos, "SELECCIONAR GENERO MUSICAL");
  int id_seleccionado = vRegistros[seleccionado].getId();

  delete[] long_string;
  delete[] nombreRegistros;
  delete[] vRegistros;

  return id_seleccionado;
}

int ArchivoGeneroMusical::cargaSeleccion(const char *pregunta, int posx, int posy) {
    int id = cargarInt(pregunta, posx, posy);
    int busqueda;
    while ((busqueda = buscarRegistro(id)) == -1 || busqueda < 0) {
        if (busqueda == -2) {
            mostrarAviso("  NO SE PUDO COMPROBAR EN EL ARCHIVO.\n");
            id = -1;
            return id;
        }
        mostrarError("GENERO MUSICAL NO ENCONTRADO.");
        int opcion = preguntaBuscarRegistro();
        if (opcion == 1) {
            id = cargarInt(pregunta, posx, posy);
        } else if (opcion == 2) {
            borrarLinea(posy);
            posicion(posx, posy);
            mostrarAviso(pregunta);
            id = seleccionarRegistro();
            posicion(posx, posy);
            mostrarDato(pregunta, id);
        } else {
            id = -1;
            return id;
        }
    }
    return id;
}
