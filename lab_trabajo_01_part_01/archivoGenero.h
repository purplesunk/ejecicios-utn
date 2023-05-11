#ifndef ARCHIVOGENERO_H_INCLUDED
#define ARCHIVOGENERO_H_INCLUDED

class ArchivoGeneroMusical {
   private:
    char nombre[30];

   public:
    ArchivoGeneroMusical(const char *nombreArchivo);
    // ALTA
    void agregarRegistro();
    void mostrarRegistros();

    // BAJA
    GeneroMusical leerGeneroMusical(int p);
    int buscarGeneroMusical(int id);
    bool bajaLogica();

    void buscarPorID();

    bool escribirRegistro(GeneroMusical obj);

    int contarRegistros();

    // MODIFICACION
    bool modificarRegistro(GeneroMusical obj, int pos);
    bool modificarAnioOrigen();
};

#endif  // ARCHIVOGENERO_H_INCLUDED
