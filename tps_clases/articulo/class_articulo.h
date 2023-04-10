#ifndef CLASS_ARTICULO_H_INCLUDED
#define CLASS_ARTICULO_H_INCLUDED

#include <string.h>

#include "utils.h"

class Articulo {
  private:
    char codigo[5];
    char descripcion[30];
    float precio;
    int stock;
    bool estado;

  public:
    void Cargar();
    void Mostrar() const;

    Articulo(const char *codArt = "AAAA",
             const char *desc = "No hay descripción.", float valorPrecio = 0,
             int valorStock = 0, bool valorEstado = false);
    Articulo(const char *string);

    const char *getCodigo() const;
    const char *getDescripcion() const;
    float getPrecio() const;
    int getStock() const;
    bool getEstado() const;

    void setCodigo(char *valor);
    void setDescripcion(char *valor);
    void setPrecio(float valor);
    void setStock(int valor);
    void setEstado(bool valor);
};

#endif   // CLASS_ARTICULO_H_INCLUDED
