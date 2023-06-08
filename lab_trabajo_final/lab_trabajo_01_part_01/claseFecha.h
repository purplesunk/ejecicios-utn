#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha {
   private:
    int dia, mes, anio;

   public:
    Fecha();
    Fecha(int d, int m, int a);

    void Cargar();

    void CargaValida();

    void Mostrar();
    /// sets
    void setDia(int x);
    void setMes(int x);
    void setAnio(int x);
    /// gets
    int getDia();
    int getMes();
    int getAnio();

    bool anioBisiesto();
};

#endif  // FECHA_H_INCLUDED
