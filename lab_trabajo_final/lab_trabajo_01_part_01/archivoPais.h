#ifndef ARCHIVOPAIS_H_INCLUDED
#define ARCHIVOPAIS_H_INCLUDED

#include "clasePais.h"

class ArchivoPaises {
private:
  char nombre[30];

public:
  ArchivoPaises(const char *nombreArchivo);
  // ALTA
  void agregarRegistro();
  void mostrarRegistros();

  // BAJA
  Pais leerRegistro(int p);
  int buscarRegistro(int id);

  bool bajaLogica();

  void buscarPorID();

  int contarRegistros();

  // MODIFICACION
  bool modificarRegistro(Pais obj, int pos);

  bool modificarNombre();
  bool modificarContinente();
};

#endif
