#include "archivoPais.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "archivo_utils.h"
#include "claseFecha.h"
#include "clasePais.h"

#include "interfaz.h"

#include "rlutil.h"

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

  FILE *archivo = fopen(nombre, "ab");
  if (archivo == NULL) {
    std::cout << "No se pudo abrir el archivo.\n";
    return;
  }

  fwrite(&obj, sizeof(Pais), 1, archivo);

  fclose(archivo);
}

void ArchivoPais::mostrarRegistros() {
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO.\n";
    return;
  }

  Pais obj;
  while (fread(&obj, sizeof obj, 1, archivo) == 1) {
    if (obj.getEstado()) {
      obj.Mostrar();
      std::cout << "-----------------------------------\n";
    }
  }
  fclose(archivo);
}

Pais ArchivoPais::leerRegistro(int p) {
  Pais obj;

  if (p < 0) {
    obj.setId(-3);
    return obj;
  }

  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL) {
    obj.setId(-2);
    return obj;
  }

  fseek(archivo, (sizeof(Pais) * p), SEEK_SET);

  if (!fread(&obj, sizeof(Pais), 1, archivo)) {
    obj.setId(-1);
  }

  fclose(archivo);

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

bool ArchivoPais::modificarRegistro(Pais obj, int pos) {
  FILE *archivo = fopen(nombre, "rb+");
  if (archivo == NULL) {
    std::cout << "ERROR AL REABRIR EL ARCHIVO.\n";
    return false;
  }

  fseek(archivo, sizeof(Pais) * pos, SEEK_SET);

  bool aux = fwrite(&obj, sizeof(Pais), 1, archivo);
  fclose(archivo);

  return aux;
}

int ArchivoPais::contarRegistros() {
  return numeroRegistros(nombre, sizeof(Pais));
}

void ArchivoPais::buscarPorID() {
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

bool ArchivoPais::bajaLogica() {
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

bool ArchivoPais::modificarNombre() {
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
  std::cout << "---------------------------------------------------------------"
               "----\n";

  char nombre[30];
  std::cout << "NUEVO NOMBRE: ";
  cargarCadena(nombre, 30);
  obj.setNombre(nombre);

  return modificarRegistro(obj, pos);
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
