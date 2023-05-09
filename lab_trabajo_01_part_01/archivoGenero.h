#ifndef ARCHIVOGENERO_H_INCLUDED
#define ARCHIVOGENERO_H_INCLUDED

#include "genero.h"

class ArchivoGeneroMusical {
   private:
    char nombre[30];
    int registros = 0;

   public:
    ArchivoGeneroMusical(const char *nombreArchivo);
    // ALTA
    void agregarRegistro();
    void mostrarRegistros();

    // BAJA
    GeneroMusical leerGeneroMusical(int p);
    int buscarGeneroMusical(int id);
    bool bajaLogica();

    // MODIFICACION
    bool modificarRegistro(GeneroMusical obj, int pos);
    bool modificarFecha();
};

#endif  // ARCHIVOGENERO_H_INCLUDED
