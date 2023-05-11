#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED

#include "claseMusico.h"

class ArchivoMusico {
   private:
    char nombre[30];

   public:
    ArchivoMusico(const char *nombreArchivo);
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
};

#endif  // ARCHIVOCLIENTE_H_INCLUDED
