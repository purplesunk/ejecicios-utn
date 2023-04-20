#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha {
   private:  /// todo lo que se defina ac� s�lo va a ser accesible dentro de la clase
    int dia, mes, anio;

   public:
    Fecha(int d = 1, int m = 1, int a = 1) {
        dia = d;
        mes = m;
        anio = a;
    }
    void Cargar();
    void Mostrar();
    /// sets
    void setDia(int x) {
        if (x > 0 && x < 32) dia = x;
    }
    void setMes(int x) {
        if (x > 0 && x < 13) mes = x;
    }
    void setAnio(int x) { anio = x; }
    /// gets
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }
};

void Fecha::Cargar() {  /// m�todo o funci�n de la clase
    cout << "DIA: ";
    cin >> dia;
    cout << "MES: ";
    cin >> mes;
    cout << "ANIO: ";
    cin >> anio;
}

void Fecha::Mostrar() {  /// m�todo o funci�n de la clase
    /*cout<<"DIA: "<<dia<<endl;
    cout<<"MES: "<<mes<<endl;
    cout<<"ANIO: "<<anio<<endl<<endl;*/
    cout << dia << "/" << mes << "/" << anio << endl;
}

#endif  // FECHA_H_INCLUDED
