#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED

class ArchivoMusico {
   private:
    char nombre[30];

   public:
    ArchivoMusico(const char *nombreArchivo);
    // ALTA
    void agregarMusico();
    void mostrarMusicos();

    // BAJA
    int buscarMusico(int dni);
    bool bajaLogica();

    // MODIFICACION
    bool modificarFecha();

    // LISTADOS
    void buscarPorDNI();
};

#endif  // ARCHIVOCLIENTE_H_INCLUDED
