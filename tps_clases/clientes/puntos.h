#ifndef PUNTOS_H_INCLUDED
#define PUNTOS_H_INCLUDED

#include <cstring>

#include "cliente.h"
#include "fecha.h"
#include "utils.h"

int cantidadMayores(Cliente vec[], int tam, Fecha fecha);
bool cargarClientes(Cliente vec[], int tam);
void mostrarClientesDniMayor(Cliente vec[], int tam);
void mostrarClientes(Cliente vec[], int tam);
int devolverPosDni(Cliente vec[], int tam, int dni);
Cliente buscarPorDni(Cliente vec[], int tam, int dni);
void punto4(Cliente *v, int tam);
void punto5(Cliente *v, int tam);
void punto6(Cliente *v, int tam);

#endif  // PUNTOS_H_INCLUDED
