#ifndef ARCHIVOINSTRUMENTO_H_INCLUDED
#define ARCHIVOINSTRUMENTO_H_INCLUDED

#include "claseInstrumento.h"

class ArchivoInstrumento {
private:
  char *nombre;

public:
  ArchivoInstrumento(const char *nombreArchivo);
  ~ArchivoInstrumento();

  void agregarRegistro();
  void mostrarRegistros();
  int contarRegistros();

  Instrumento leerRegistro(int p);
  int buscarRegistro(int id);
  void buscarPorID();

  // MODIFICACION
  bool bajaLogica();
  bool modificarRegistro(Instrumento obj, int pos);
  bool modificarNombre();

  // BACKUP
  bool copiaSeguridad();
  bool restaurarCopia();
  bool restaurarInicio();

  int seleccionarRegistro(int posx = -1, int posy = 4, int boxWidth = 40, int boxHeight = -1);
};

#endif
