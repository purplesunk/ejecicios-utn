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
    void Cargar(int autoId);
    void Mostrar();

    int getId();
    bool getEstado();
    int getPaisOrigen();
    int getAnioOrigen();
    const char* getNombre();

    void setId(int nuevoId);
    void setEstado(bool nuevoEstado);
    void setAnioOrigen(int nuevoAnio);
    void setPaisOrigen(int nuevoPais);
    void setNombre(const char* n);
};

#endif