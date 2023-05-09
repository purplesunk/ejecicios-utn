#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED

class GeneroMusical {
   private:
    int id;
    char nombre[30];
    int paisOrigen;
    int anioOrigen;
    bool estado;

   public:
    void cargar(int autoId);
    void mostrar();

    int getId();
    void setId(int nuevoId);
    int getEstado();
    void setEstado(bool nuevoEstado);
    void setAnioOrigen(int nuevoAnio);
};

#endif