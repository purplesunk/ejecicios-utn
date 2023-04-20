#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "cargarcadena.h"
#include "fecha.h"

class Persona {
   protected:
    int DNI;
    Fecha fechaNacimiento;
    char nombre[25];
    char apellido[25];
    char email[25];
    char telefono[20];

   public:
    Fecha getFechaNacimiento() {
        return fechaNacimiento;
    }

    int getDNI() { return DNI; }
    const char *getNombre() { return nombre; }
    const char *getApellido() { return apellido; }
    const char *getEmail() { return email; }
    const char *getTelefono() { return telefono; }

    void setDNI(const int d) { DNI = d; }
    void setFechaNacimiento(Fecha f) { fechaNacimiento = f; }
    void setNombre(const char *n) { strcpy(nombre, n); }
    void setApellido(const char *a) { strcpy(apellido, a); }
    void setEmail(const char *e) { strcpy(email, e); }
    void setTelefono(const char *t) { strcpy(telefono, t); }

    void Cargar();
    void Mostrar();
};

void Persona::Cargar() {
    cout << "DNI: ";
    cin >> DNI;
    cout << "Fecha Nacimiento: " << endl;
    fechaNacimiento.Cargar();
    cout << "Nombre: ";
    ignoreLine();
    cargarCadena(nombre, 25);
    cout << "APELLIDO: ";
    cargarCadena(apellido, 25);
    cout << "EMAIL: ";
    cargarCadena(email, 25);
    cout << "TELEFONO: ";
    cargarCadena(telefono, 20);
}

void Persona::Mostrar() {
    cout << "DNI: ";
    cout << DNI << endl;
    cout << "Fecha Nacimiento: " << endl;
    fechaNacimiento.Mostrar();
    cout << "Nombre: ";
    cout << nombre << endl;
    cout << "APELLIDO: ";
    cout << apellido << endl;
    cout << "EMAIL: ";
    cout << email << endl;
    cout << "TELEFONO: ";
    cout << telefono << endl;
}
/// fin de la clase Persona

#endif  // PERSONA_H_INCLUDED
