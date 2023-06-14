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
  GeneroMusical leerRegistro(int p);
  int buscarRegistro(int id);
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
  bool restaurarInicio();

  int seleccionarRegistro(int posx = -1, int posy = 4, int boxWidth = 40, int boxHeight = -1);
};

#endif // ARCHIVOGENERO_H_INCLUDED
