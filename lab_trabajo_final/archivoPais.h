#ifndef ARCHIVOPAIS_H_INCLUDED
#define ARCHIVOPAIS_H_INCLUDED

#include "clasePais.h"

class ArchivoPais {
private:
  char *nombre;

public:
  ArchivoPais(const char *nombreArchivo);
  ~ArchivoPais();

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

  // BACKUP
  bool copiaSeguridad();
  bool restaurarCopia();
};

#endif
