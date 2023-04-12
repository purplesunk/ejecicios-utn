#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha {
    private:
        int day;
        int month;
        int year;

    public:
        Fecha(int valDay = 1, int valMonth = 1, int valYear = 1999);

        int getDay();
        int getMonth();
        int getYear();

        void setDay(int valor);
        void setMonth(int valor);
        void setYear(int valor);

        void cargar();
        void mostrar();
};

#endif // FECHA_H_INCLUDED
