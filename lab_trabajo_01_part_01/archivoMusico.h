#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED

class ArchivoMusico {
   private:
    char nombre[30];

   public:
    ArchivoMusico(const char *nombreArchivo) {
        strncpy(nombre, nombreArchivo, 30);
    }
    // ALTA
    void agregarRegistro();
    void mostrarRegistros();

    // BAJA
    Musico leerMusico(int p);
    int buscarMusico(int dni);
    bool bajaLogica();

    // MODIFICACION
    bool modificarRegistro(Musico obj, int pos);

    // LISTADOS
    void buscarPorDNI();
};

#endif  // ARCHIVOCLIENTE_H_INCLUDED
