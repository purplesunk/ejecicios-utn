#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

class Instrumento {
private:
  int id;
  char nombre[30];
  int clasificacion;
  bool estado;

public:
  void Cargar(int autoId);
  void Mostrar();

  int getId();
  const char *getNombre();
  int getClasificacion();
  bool getEstado();

  void setId(int nuevoId);
  void setNombre(const char *n);
  void setClasificacion(int c);
  void setEstado(bool nuevoEstado);
};

#endif
