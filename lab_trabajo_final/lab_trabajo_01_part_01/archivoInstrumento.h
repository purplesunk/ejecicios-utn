#ifndef ARCHIVOINSTRUMENTO_H_INCLUDED
#define ARCHIVOINSTRUMENTO_H_INCLUDED

#include "claseInstrumento.h"

class ArchivoInstrumento {
private:
  char nombre[30];

public:
  ArchivoInstrumento(const char *nombreArchivo);
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
};

#endif
