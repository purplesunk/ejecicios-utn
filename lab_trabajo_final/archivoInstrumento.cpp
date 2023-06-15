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
  // rlutil::locate((rlutil::tcols() - strlen("instrumentos")) / 2, 2);
  std::cout << "INTRUMENTOS"<< "\n\n";
  // int space = 4;
  // rlutil::locate(10, space);
  std::cout << "----------------------------------------\n";
  while (fread(&obj, sizeof obj, 1, archivo) == 1) {
    if (obj.getEstado()) {
      obj.Mostrar();
      // space += 4;
      // rlutil::locate(10, space);
      std::cout << "----------------------------------------\n";
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
  return numeroRegistros(nombre, sizeof(Instrumento));
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

bool ArchivoInstrumento::modificarNombre() {
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
  std::cout << "Instrumento: " << obj.getNombre() << '\n';
  std::cout << "---------------------------------------------------------------"
               "----\n";

  char nuevo_nombre[30];
  std::cout << "NUEVO NOMBRE: ";
  cargarCadena(nuevo_nombre, 30);
  obj.setNombre(nuevo_nombre);

  return modificarRegistro(obj, pos);
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
