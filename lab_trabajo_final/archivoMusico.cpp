#include "archivoMusico.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "claseFecha.h"
#include "claseMusico.h"

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
  std::cout << " Ingrese los datos del músico: \n";
  std::cout << "--------------------------------\n";
  obj.Cargar();

  int pos = buscarMusico(obj.getDni());

  if (pos == -2) {
    std::cout << "El archivo no se encontro. Creando archivo.\n";
  } else if (pos != -1) {
    std::cout << "Ya hay un registro con ese DNI.\n";
    return;
  }

  FILE *pCli = fopen(nombre, "ab");
  if (pCli == NULL) {
    std::cout << "No se pudo abrir el archivo.\n";
    return;
  }

  fwrite(&obj, sizeof(Musico), 1, pCli);
  fclose(pCli);
}

bool ArchivoMusico::bajaLogica() {
  // Solicitar que registro se quiere dar de baja
  int DNI = cargarInt("INGRESE EL DNI A BUSCAR: ");

  // Buscar el registro en el archivo
  int pos = buscarMusico(DNI);
  if (pos == -1) {
    std::cout << "NO EXISTE MUSICO CON ESE DNI.\n";
    return false;
  }
  if (pos == -2) {
    std::cout << "NO SE PUDO ABRIR ARCHIVO\n";
    return false;
  }

  Musico obj = leerMusico(pos);

  if (obj.getEstado() == false) {
    std::cout << "EL MUSICO INGRESADO YA ESTA DADO DE BAJA.\n";
    return false;
  }

  // Modificarmos el campo estado (lo ponemos en false)
  obj.setEstado(false);

  // Sobreescribir
  return modificarRegistro(obj, pos);
}

Musico ArchivoMusico::leerMusico(int p) {
  Musico obj;

  if (p < 0) {
    obj.setDNI(-3);
    return obj;
  }

  FILE *pCli = fopen(nombre, "rb");
  if (pCli == NULL) {
    obj.setDNI(-2);
    return obj;
  }

  fseek(pCli, (sizeof(Musico) * p), SEEK_SET);

  if (!fread(&obj, sizeof(Musico), 1, pCli)) {
    obj.setDNI(-1);
  }

  fclose(pCli);

  return obj;
}

int ArchivoMusico::buscarMusico(int dni) {
  FILE *pCli = fopen(nombre, "rb");
  if (pCli == NULL) {
    return -2;
  }

  int pos = 0;
  Musico obj;

  while (fread(&obj, sizeof(obj), 1, pCli) == 1) {
    if (dni == obj.getDni()) {
      fclose(pCli);
      return pos;
    }
    ++pos;
  }

  fclose(pCli);

  return -1;
}

bool ArchivoMusico::modificarRegistro(Musico obj, int pos) {
  FILE *pCli = fopen(nombre, "rb+");
  if (pCli == NULL) {
    std::cout << "ERROR AL REABRIR EL ARCHIVO.\n";
    return false;
  }

  fseek(pCli, sizeof(Musico) * pos, SEEK_SET);

  bool aux = fwrite(&obj, sizeof(Musico), 1, pCli);
  fclose(pCli);

  return aux;
}

void ArchivoMusico::mostrarRegistros() {
  FILE *pCli = fopen(nombre, "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO ABRIR EL ARCHIVO.\n";
    return;
  }

  Musico obj;
  int cant = 0;
  while (fread(&obj, sizeof obj, 1, pCli) == 1) {
    if (obj.getEstado()) {
      ++cant;
      std::cout << "-------------------------------------\n";
      std::cout << " Musico " << cant << '\n';
      std::cout << "-------------------------------------\n";
      obj.Mostrar();
      std::cout << '\n';
    }
  }
  fclose(pCli);
}

bool ArchivoMusico::escribirRegistro(Musico obj) {
  FILE *archivo = fopen(nombre, "ab");
  if (archivo == NULL) {
    std::cout << "NO SE PUDO CREAR EL ARCHIVO.\n";
    return false;
  }

  bool aux = fwrite(&obj, sizeof(obj), 1, archivo);

  fclose(archivo);

  return aux;
}

void ArchivoMusico::buscarPorDNI() {
  int DNI = cargarInt("INGRESE EL DNI A BUSCAR: ");

  int pos = buscarMusico(DNI);
  if (pos == -2) {
    std::cout << "No se pudo abrir el archivo.\n";
    return;
  } else if (pos == -1) {
    std::cout << "No se encontró el registro.\n";
    return;
  }

  Musico obj = leerMusico(pos);
  if (!obj.getEstado()) {
    std::cout << "Registro dado de baja.\n";
    return;
  }

  if (obj.getDni() > 0) {
    std::cout << "---------------------------------\n";
    obj.Mostrar();
    std::cout << "---------------------------------\n";

  } else if (obj.getDni() == -3) {
    std::cout << "Se puso una posición inválida.\n";
  } else if (obj.getDni() == -1) {
    std::cout << "No se pudo leer el registro.\n";
  } else {
    std::cout << "No se pudo abrir el archivo.\n";
  }
}

bool ArchivoMusico::modificarFecha() {
  int dni = cargarInt("Ingrese el DNI a buscar: ");

  int pos = buscarMusico(dni);
  if (pos == -1) {
    std::cout << "NO EXISTE MUSICO CON ESE DNI.\n";
    return false;
  }
  if (pos == -2) {
    std::cout << "NO SE PUDO ABRIR EL ARCHIVO.\n";
    return false;
  }

  Musico obj = leerMusico(pos);

  if (!obj.getEstado()) {
    std::cout << "Registro dado de baja.\n";
    return false;
  }

  std::cout << "---------------------------------------------------------------"
               "----\n";
  std::cout << "Musico: " << obj.getNombre() << " " << obj.getApellido()
            << '\n';
  std::cout << "Fecha de Inscripción actual: ";
  obj.getFechaInscripcion().Mostrar();
  std::cout << "\n-------------------------------------------------------------"
               "------\n";

  Fecha nuevaFecha;
  std::cout << "Ingrese la nueva fecha de inscripcion:\n";
  nuevaFecha.Cargar();

  obj.setFechaInscripcion(nuevaFecha);

  return modificarRegistro(obj, pos);
}

int ArchivoMusico::contarRegistros() {
  FILE *musicos = fopen(nombre, "rb");
  if (musicos == NULL) {
    return -1;
  }

  fseek(musicos, 0, SEEK_END);

  int cantidad = ftell(musicos) / sizeof(Musico);

  fclose(musicos);

  return cantidad;
}

// añadir auto creado de nombre.bkp o algo así
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
