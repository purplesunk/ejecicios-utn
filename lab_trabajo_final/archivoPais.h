#ifndef ARCHIVOPAIS_H_INCLUDED
#define ARCHIVOPAIS_H_INCLUDED

#include "clasePais.h"

class ArchivoPais {
private:
  char *nombre;

public:
  ArchivoPais(const char *nombreArchivo);
  ~ArchivoPais();

  void agregarRegistro();
  void mostrarRegistros();
  int contarRegistros();

  Pais leerRegistro(int p);
  int buscarRegistro(int id);
  void buscarPorID();

  // MODIFICACION
  int modificarRegistro(Pais obj, int pos);
  bool bajaLogica();
  bool modificarNombre();

  // BACKUP
  bool copiaSeguridad();
  bool restaurarCopia();
  bool restaurarInicio();

  int seleccionarRegistro(int posx = -1, int posy = 4, int boxWidth = 40, int boxHeight = -1);
};

#endif
