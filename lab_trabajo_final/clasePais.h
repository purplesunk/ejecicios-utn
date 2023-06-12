#ifndef CLASEPAIS_H_INCLUDED
#define CLASEPAIS_H_INCLUDED

class Pais {
private:
  int id;
  char nombre[30];
  char continente[30];
  bool estado;

public:
  void Cargar(int autoId);
  void Mostrar();
  void MostrarSeleccion();

  int getId();
  const char *getNombre();
  const char *getContinente();
  bool getEstado();

  void setId(int nuevoId);
  void setNombre(const char *n);
  void setContinente(const char *c);
  void setEstado(bool nuevoEstado);
};

#endif
