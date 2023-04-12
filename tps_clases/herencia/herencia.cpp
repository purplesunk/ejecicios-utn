#include <cstring>
#include <iostream>

#include "fecha.h"
#include "utils.h"

class Persona {
   private:
    int Dni;
    char nombre[30];
    char apellido[30];
    char email[30];
    Fecha fechaNacimiento;

   public:
    void setDni(int d) { Dni = d; }
    void setNombre(const char *n) {
        strncpy(nombre, n, 29);
    }
    void setApellido(const char *a) {
        strncpy(apellido, a, 29);
    }
    void setEmail(const char *e) {
        strncpy(email, e, 29);
    }
    void setFechaNacimiento(Fecha aux) { fechaNacimiento = aux; }

    int getDni() { return Dni; }
    const char *getNombre() { return nombre; }
    const char *getApellido() { return apellido; }
    const char *getEmail() {
        return email;
    }
    Fecha getFechaNacimeiento() {
        return fechaNacimiento;
    }
};

class Empleado : Persona {
   private:
    int catergoría;
    int sueldo;
    Fecha ingreso;

   public:
    Empleado(int cat = 1, int sueld = 65, int dia, int mes, int anio) {
        catergoría = cat;
        sueldo = sueld;
        ingreso.setDay(dia);
        ingreso.setMonth(mes);
        ingreso.setYear(anio);
    }
}

class Proveedor : Persona {
   private:
    int cuil;
    int tipoProducto;
    char condicion;

   public:
    Proveedor(int c = 1000, int p = 1, char cond = 'a') {
        cuil = c;
        tipoProducto = p;
        condicion = cond;
    }
}

class Docente : Persona {
   private:
    int legajo;
    char cargo[15];
    Fecha ingreso;

   public:
    Docente(int l, const char *c, int dia, int mes, int anio) {
        legajo = l;
        strncpy(cargo, c, 14);
        ingreso.setDay(dia);
        ingreso.setMonth(mes);
        ingreso.setYear(anio);
    }
}

int
main() {
    std::cout << "Please kill me\n";
    return 0;
}