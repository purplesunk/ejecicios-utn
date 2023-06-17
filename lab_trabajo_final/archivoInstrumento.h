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
  int modificarRegistro(Instrumento obj, int pos);
  bool bajaLogica();
  bool modificarNombre();

  // BACKUP
  bool copiaSeguridad();
  bool restaurarCopia();
  bool restaurarInicio();

  int seleccionarRegistro(int posx = -1, int posy = 4, int boxWidth = 40, int boxHeight = -1);
  int cargaSeleccion(const char *pregunta, int posx, int posy);
};

#endif
