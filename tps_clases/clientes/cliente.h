#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "utils.h"
#include "fecha.h"

class Cliente {
    private:
        char dni[9];
        Fecha nacimiento;
        char nombre[50];
        char apellido[50];
        char email[80];
        char telefono[20];

    public:
        Cliente(const char* valorNombre);

        Cliente(const char *valorDni = "11111111", Fecha valorNac = Fecha(10,10,2023), const char *valorNom = "Name",
                const char *valorApellido = "Apellido", const char *valorTel = "+54 011 1234-3243",
                const char *valorEmail = "noemail@clientes.h");

        void Cargar();
        void Mostrar();

        Fecha getNacimiento();
        const char* getDni();
        const char* getNombre();
        const char* getApellido();
        const char* getEmail();
        const char* getTelefono();

        void setDni(const char* valor);
        void setNacimiento(Fecha valor);
        void setNombre(const char* valor);
        void setApellido(const char* valor);
        void setEmail(const char* valor);
        void setTelefono(const char* valor);
};

#endif // CLIENTE_H_INCLUDED
