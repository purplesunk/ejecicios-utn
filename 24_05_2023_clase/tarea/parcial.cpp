#include <cstring>
#include <iostream>

using namespace std;

#include "parcial1.h"

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
    bool cambio = true;
    Proyecto proyectoTmp;
    int vueltas = 1;
    while (cambio) {
        cambio = false;
        for (int i = 0; i < cant - vueltas; ++i) {
            if (strcasecmp(vProy[i].getNombre(), vProy[i + 1].getNombre()) > 0) {
                proyectoTmp = vProy[i + 1];
                vProy[i + 1] = vProy[i];
                vProy[i] = proyectoTmp;
                cambio = true;
            }
        }
        vueltas++;
    }

    for (int i = 0; i < cant; i++) {
        vProy[i].Mostrar();
    }

    delete[] vProy;

    return 0;
}
