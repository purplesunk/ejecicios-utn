#ifndef ARCHIVOINSTRUMENTO_H_INCLUDED
#define ARCHIVOINSTRUMENTO_H_INCLUDED

#include "claseInstrumento.h"

class ArchivoInstrumento {
private:
  char *nombre;

public:
  ArchivoInstrumento(const char *nombreArchivo);
  ~ArchivoInstrumento();

  // ALTA
  void agregarRegistro();
  void mostrarRegistros();

  // BAJA
  Instrumento leerRegistro(int p);
  int buscarRegistro(int id);

  bool bajaLogica();

  void buscarPorID();

  int contarRegistros();

  // MODIFICACION
  bool modificarRegistro(Instrumento obj, int pos);
  bool modificarClasificacion();
  bool modificarNombre();

  // BACKUP
  bool copiaSeguridad();
  bool restaurarCopia();
};

#endif
