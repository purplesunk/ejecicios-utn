#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED

#include "claseMusico.h"

class ArchivoMusico {
private:
  char *nombre;

public:
  ArchivoMusico(const char *nombreArchivo);
  ~ArchivoMusico();

  // ALTA
  void agregarRegistro();
  void mostrarRegistros();

  bool escribirRegistro(Musico obj);

  // BAJA
  Musico leerMusico(int p);
  int buscarMusico(int dni);
  bool bajaLogica();

  // MODIFICACION
  bool modificarRegistro(Musico obj, int pos);
  bool modificarFecha();

  int contarRegistros();

  // LISTADOS
  void buscarPorDNI();

  // BACKUPS
  bool copiaSeguridad();
  bool restaurarCopia();

  int seleccionarRegistro(int posx = -1, int posy = 4, int boxWidth = 40, int boxHeight = -1);
};

#endif // ARCHIVOCLIENTE_H_INCLUDED