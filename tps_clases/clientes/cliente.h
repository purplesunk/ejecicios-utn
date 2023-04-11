#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "fecha.h"
#include "utils.h"

class Cliente {
  private:
    int dni;
    Fecha nacimiento;
    char nombre[50];
    char apellido[50];
    char email[80];
    char telefono[20];

  public:
    Cliente(const char *valorNombre);

    Cliente(int valorDni = 11111111, int dia = 12, int mes = 12,
            int anio = 2022, const char *valorNom = "Name",
            const char *valorApellido = "Apellido",
            const char *valorTel = "+54 011 1234-3243",
            const char *valorEmail = "noemail@clientes.h");

    void Cargar();
    void Mostrar();

    Fecha getNacimiento();
    int getDni();
    const char *getNombre();
    const char *getApellido();
    const char *getEmail();
    const char *getTelefono();

    void setDni(int valor);
    void setNacimiento(int dia, int mes, int anio);
    void setNombre(const char *valor);
    void setApellido(const char *valor);
    void setEmail(const char *valor);
    void setTelefono(const char *valor);
};

#endif   // CLIENTE_H_INCLUDED
