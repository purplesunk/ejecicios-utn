#include <iostream>

#include "fecha.h"

class Edificio {
   private:
    char calle[50];
    int numCalle;
    int codigoPostal;
    char localidad[50];
    int piso;
    Fecha ingreso;
    Fecha operacion;
    int superficie;
    int tipoOperacion;
};

class Casa : Edificio {
   private:
    int cantAmbientes;
    int superficieConstruida;
};

class Departamentos : Edificio {
   private:
    int cantAmbientes;
    char instalacionesComp[50];
};

class Comercio : Edifico {
   private:
    int zona;
    char mejora;
};

int main() {
}