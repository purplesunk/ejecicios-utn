#include <cstring>
#include <iostream>

using namespace std;

#include "parcial1.h"

void mergeSort(Proyecto vProyecto[], int tam, int inicio);
void bubbleSort(Proyecto vProy[], int cant);

/// VAMOS A CARGAR EL ARCHIVO proyectos.dat EN UN VECTOR DINAMICO.

int main() {
    ArchivoProyecto arcProy("proyectos.dat");
    Proyecto *vProy;

    int cant = arcProy.contarRegistros();

    vProy = new Proyecto[cant];
    if (vProy == NULL) {
        cout << "NO SE PUDO ASIGNAR MEMORIA" << endl;
        return -1;
    }

    for (int i = 0; i < cant; i++) {
        vProy[i] = arcProy.leerRegistro(i);
        if (vProy[i].getUbicacion() == -1) {
            return -1;
        }
    }


    /// REORDENAR EL VECTOR POR NOMBRE DE PROYECTO
    mergeSort(vProy, 10, 0);

    //mergeSort(vProy, cant, 0);

    for (int i = 0; i < cant; i++) {
        vProy[i].Mostrar();
    }

    delete[] vProy;

    return 0;
}

void mergeSort(Proyecto vProyecto[], int tam, int inicio) {
    if (tam <= 1) {
        return;
    }

    int mitad = tam / 2;

    // sort izquierda:
    mergeSort(vProyecto, mitad, inicio);

    // sort derecha:
    mergeSort(vProyecto, mitad, mitad - 1);

    // merge the thingys:
    Proyecto *vBuffer = new Proyecto[tam];

    int cantDerecha = 0;
    int cantIzquierda = 0;
    bool cmpDerecha = false;

    for (int i = 0; i < tam - 1; ++i) {

        if (cantDerecha == mitad) {
            vBuffer [i + 1] = vProyecto[inicio + cantIzquierda];
            ++cantIzquierda;
        }
        if (cantIzquierda == mitad) {
            vBuffer [i + 1] = vProyecto[inicio + mitad + cantDerecha];
            ++cantDerecha;
        }

        if (cmpDerecha) {
            if (strcmp(vProyecto[inicio + mitad + cantDerecha].getNombre(), vProyecto[inicio + cantIzquierda].getNombre()) < 0) {
                vBuffer[i] = vProyecto[inicio + mitad + cantDerecha];
                cmpDerecha = false;
                ++cantDerecha;
            } else {
                vBuffer[i] = vProyecto[inicio + cantIzquierda];
                cmpDerecha = true;
                ++cantIzquierda;
            }
        } else {
            if (strcmp(vProyecto[inicio + cantIzquierda].getNombre(), vProyecto[inicio + mitad + cantDerecha].getNombre()) < 0) {
                vBuffer[i] = vProyecto[inicio + cantIzquierda];
                cmpDerecha = true;
                ++cantIzquierda;
            } else {
                vBuffer[i] = vProyecto[inicio + cantDerecha];
                cmpDerecha = false;
                ++cantDerecha;
            }
        }
    }

    for (int i = 0; i < tam; ++i) {
        vProyecto[inicio + i] = vBuffer[i];
    }

    delete[] vBuffer;
}

void bubbleSort(Proyecto vProy[], int cant) {
    bool cambio = true;
    Proyecto proyectoTmp;
    int vueltas = 1;
    while (cambio) {
        cambio = false;
        for (int i = 0; i < cant - vueltas; ++i) {
            if (strcmp(vProy[i].getNombre(), vProy[i + 1].getNombre()) > 0) {
                proyectoTmp = vProy[i + 1];
                vProy[i + 1] = vProy[i];
                vProy[i] = proyectoTmp;
                cambio = true;
            }
        }
        vueltas++;
    }
}
