#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#include "fecha.h"

class Musico {
   protected:
    int dni;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int claustro;     // entre 1 y 4
    int instrumento;  // entre 1 y 15
    int tipoMusica;   // entre 1 y 10
    Fecha fechaInscripcion;
    float matricula;
    bool estado;

   public:
    int getDni();
    const char *getNombre();
    const char *getApellido();
    const char *getEmail();
    const char *getTelefono();
    bool getEstado();

    void setDNI(const int d);
    void setNombre(const char *n);
    void setApellido(const char *a);
    void setEmail(const char *e);
    void setTelefono(const char *t);
    void setEstado(bool b);
    void setFechaInscripcion(Fecha nuevaFecha);

    void Cargar();
    void Mostrar();
};

#endif  // MUSICO_H_INCLUDED