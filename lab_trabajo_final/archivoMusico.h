#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED

#include "claseMusico.h"

class ArchivoMusico {
private:
  char *nombre;

public:
  ArchivoMusico(const char *nombreArchivo);
  ~ArchivoMusico();

  void agregarRegistro();
  void mostrarRegistros();
  int contarRegistros();

  void buscarPorDNI();
  int buscarRegistro(int dni);
  Musico leerRegistro(int p);

  // MODIFICACION
  bool bajaLogica();
  int modificarRegistro(Musico obj, int pos);
  bool modificarFecha();

  // BACKUPS
  bool copiaSeguridad();
  bool restaurarCopia();
  bool restaurarInicio();

  int seleccionarRegistro(int posx = -1, int posy = 4, int boxWidth = 40, int boxHeight = -1);
};

#endif // ARCHIVOCLIENTE_H_INCLUDED
