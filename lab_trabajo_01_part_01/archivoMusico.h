#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED

#include "musico.h"

class ArchivoMusico {
   private:
    char nombre[30];

   public:
    ArchivoMusico(const char *nombreArchivo);
    // ALTA
    void agregarRegistro();
    void mostrarRegistros();

    // BAJA
    Musico leerMusico(int p);
    int buscarMusico(int dni);
    bool bajaLogica();

    // MODIFICACION
    bool modificarRegistro(Musico obj, int pos);
    bool modificarFecha();

    // LISTADOS
    void buscarPorDNI();
};

#endif  // ARCHIVOCLIENTE_H_INCLUDED
