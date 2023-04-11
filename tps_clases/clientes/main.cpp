#include <iostream>

#include "cliente.h"
#include "fecha.h"
#include "utils.h"

int cantidadMayores(Cliente vec[], int tam, Fecha fecha);
void cargarClientes(Cliente vec[], int tam);
void mostrarClientesDniMayor(Cliente vec[], int tam);
void mostrarClientes(Cliente vec[], int tam);
int devolverPosDni(Cliente vec[], int tam, int dni);
Cliente buscarPorDni(Cliente vec[], int tam, int dni);

int main() {
    const int CANTIDAD = 2;
    Cliente clientes[CANTIDAD];

    while (true) {
        std::cout << "1. Cargar\n";
        std::cout << "2. Mostrar\n";
        std::cout << "3. Mostrar DNI Mayor a...\n";
        std::cout << "4. Posición de DNI\n";
        std::cout << "5. Objeto de DNI\n";
        std::cout << "6. Cantidad nacidos antes de...\n";
        std::cout << "0. Salir\n";
        int opcion{};
        std::cin >> opcion;
        ignoreLine();

        switch (opcion) {
            case 1:
                cargarClientes(clientes, CANTIDAD);
                break;
            case 2:
                mostrarClientes(clientes, CANTIDAD);
                break;
            case 3:
                mostrarClientesDniMayor(clientes, CANTIDAD);
                break;
            case 4: {
                int dni{};
                std::cout << "Ingrese dni: ";
                std::cin >> dni;
                ignoreLine();

                std::cout << "Posición: " << devolverPosDni(clientes, CANTIDAD, dni) << '\n';
            } break;
            case 5: {
                int dni{};
                std::cout << "Ingrese dni: ";
                std::cin >> dni;
                ignoreLine();

                Cliente cliente = buscarPorDni(clientes, CANTIDAD, dni);

                cliente.Mostrar();
            } break;
            case 6: {
                Fecha fecha;
                std::cout << "Ingrese fecha a buscar: \n";
                fecha.cargar();

                std::cout << "Cantidad: " << cantidadMayores(clientes, CANTIDAD, fecha) << '\n';
            } break;
            case 0:
                return 0;
                break;
            default:
                std::cout << "Opción no existe.\n";
                break;
        }
    }
}

void cargarClientes(Cliente vec[], int tam) {
    for (int i = 0; i < tam; ++i) {
        std::cout << "Cargar cliente " << i + 1 << '\n';
        vec[i].Cargar();
    }
}

void mostrarClientes(Cliente vec[], int tam) {
    for (int i = 0; i < tam; ++i) {
        vec[i].Mostrar();
    }
}

void mostrarClientesDniMayor(Cliente vec[], int tam) {
    std::cout << "Ingrese numero de dni: ";
    int dniMenor{};
    std::cin >> dniMenor;

    for (int i = 0; i < tam; ++i) {
        if (vec[i].getDni() > dniMenor) {
            vec[i].Mostrar();
        }
    }
}

int devolverPosDni(Cliente vec[], int tam, int dni) {
    for (int i = 0; i < tam; ++i) {
        if (vec[i].getDni() == dni) {
            return i;
        }
    }
    return -1;
}

Cliente buscarPorDni(Cliente vec[], int tam, int dni) {
    for (int i = 0; i < tam; ++i) {
        if (vec[i].getDni() == dni) {
            return vec[i];
        }
    }
    Cliente obj(-1);
    return obj;
}

int cantidadMayores(Cliente vec[], int tam, Fecha fecha) {
    int cantidad{0};
    for (int i = 0; i < tam; ++i) {
        int anio = vec[i].getNacimiento().getYear();
        if (anio < fecha.getYear()) {
            ++cantidad;
        } else if (anio == fecha.getYear()) {
            int mes = vec[i].getNacimiento().getMonth();
            if (mes < fecha.getMonth()) {
                ++cantidad;
            } else if (mes == fecha.getMonth()) {
                int dia = vec[i].getNacimiento().getDay();
                if (dia < fecha.getDay()) {
                    ++cantidad;
                }
            }
        }
    }
    return cantidad;
}
