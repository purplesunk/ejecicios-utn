#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha {
   private:
    int dia, mes, anio;

   public:
    Fecha();
    Fecha(const char *texto);

    void Cargar();

    void CargaValida(int posx, int posy);

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
    int getDiaValido(Fecha &fechaActual);
};

#endif  // FECHA_H_INCLUDED
