#ifndef ARCHIVOGENERO_H_INCLUDED
#define ARCHIVOGENERO_H_INCLUDED

#include "claseGeneroMusical.h"

class ArchivoGeneroMusical {
private:
  char *nombre;

public:
  ArchivoGeneroMusical(const char *nombreArchivo);

  ~ArchivoGeneroMusical();
  // ALTA
  void agregarRegistro();
  void mostrarRegistros();

  // BAJA
  GeneroMusical leerGeneroMusical(int p);
  int buscarGeneroMusical(int id);
  bool bajaLogica();

  void buscarPorID();

  bool escribirRegistro(GeneroMusical obj);

  int contarRegistros();

  // MODIFICACION
  bool modificarRegistro(GeneroMusical obj, int pos);
  bool modificarAnioOrigen();

  // BACKUP
  bool copiaSeguridad();
  bool restaurarCopia();
};

#endif // ARCHIVOGENERO_H_INCLUDED
