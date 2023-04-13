#include "puntos.h"

#include <iostream>

bool cargarClientes(Cliente vec[], int tam) {
    for (int i = 0; i < tam; ++i) {
        std::cout << "Cargar cliente " << i + 1 << '\n';
        vec[i].Cargar();
    }

    return true;
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

void punto4(Cliente* v, int tam) {
    int dni{};
    std::cout << "Ingrese dni: ";
    std::cin >> dni;
    ignoreLine();

    std::cout << "Posición: " << devolverPosDni(v, tam, dni) << '\n';
}

void punto5(Cliente* v, int tam) {
    int dni{};
    std::cout << "Ingrese dni: ";
    std::cin >> dni;
    ignoreLine();

    Cliente cliente = buscarPorDni(v, tam, dni);

    cliente.Mostrar();
}

void punto6(Cliente* v, int tam) {
    Fecha fecha;
    std::cout << "Ingrese fecha a buscar: \n";
    fecha.cargar();

    std::cout << "Cantidad: " << cantidadMayores(v, tam, fecha) << '\n';
}

int cantidadMayores(Cliente vec[], int tam, Fecha fecha) {
    int cantidad{0};
    Fecha nacimiento;
    for (int i = 0; i < tam; ++i) {
        nacimiento = vec[i].getNacimiento();
        if (nacimiento.getYear() < fecha.getYear()) {
            cantidad += 1;
        } else if (nacimiento.getYear() == fecha.getYear()) {
            if (nacimiento.getMonth() < fecha.getMonth()) {
                cantidad += 1;
            } else if (nacimiento.getMonth() == fecha.getMonth()) {
                if (nacimiento.getDay() < fecha.getDay()) {
                    cantidad += 1;
                }
            }
        }
    }
    return cantidad;
}