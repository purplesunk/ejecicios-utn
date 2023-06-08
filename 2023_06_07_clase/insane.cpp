#include <cstring>
#include <iostream>

using namespace std;

#include "parcial1.h"

class ProyectoTareas {
private:
  char codigoProyecto[5];
  char nombre[30];
  int cantTareas;

public:
  void setCodigo(const char *codigo) { strncpy(codigoProyecto, codigo, 4); }
  void setNombre(const char *name) { strncpy(nombre, name, 29); }
  void setTareas(int cant) { cantTareas = cant; }

  void operator=(Proyecto &p) {
    strncpy(codigoProyecto, p.getCodigoProyecto(), 4);
    strncpy(nombre, p.getNombre(), 29);
  }
};

void puntoA();

int main() { puntoA(); }

void puntoA() {
  ArchivoProyecto fProyectos("proyectos.dat");
  ArchivoTarea fTareas("tareas.dat");

  int cantProyectos = fProyectos.contarRegistros();
  int cantTareas = fTareas.contarRegistros();

  Proyecto proyectoAux;
  Tarea tareaAux;
  int cantTareasProyecto;
  for (int i = 0; i < cantProyectos; ++i) {
    proyectoAux = fProyectos.leerRegistro(i);
    cantTareasProyecto = 0;

    for (int j = 0; j < cantTareas; ++j) {
      tareaAux = fTareas.leerRegistro(j);

      bool comparar =
          (proyectoAux.getCodigoProyecto() == tareaAux.getCodigoProyecto());

      if (comparar)
        ++cantTareasProyecto;
    }

    FILE *newFile = fopen("ProyectoCantTareas.dat", "ab");
    if (newFile == NULL) {
      return;
    }

    ProyectoTareas newThingy;
    newThingy = proyectoAux;
    newThingy.setTareas(cantTareasProyecto);

    fwrite(&newThingy, sizeof(newThingy), 1, newFile);

    fclose(newFile);
  }
}

void puntoB() {
  ArchivoTarea fTareas("tareas.dat");
  ArchivoEmpleado fEmpleados("empleados.dat");

  int cantEmpleados = fEmpleados.contarRegistros();
  int cantTareas = fTareas.contarRegistros();

  Empleado empleadoAux;
  Tarea tareaAux;
  int cantTareasEmpleados;
  for (int i = 0; i < cantEmpleados; ++i) {
    empleadoAux = fEmpleados.leerRegistro(i);
    cantTareasEmpleados = 0;

    for (int j = 0; j < cantTareas; ++j) {
      tareaAux = fTareas.leerRegistro(j);

      bool comparar = (empleadoAux.get() == tareaAux.getCodigoProyecto());

      if (comparar)
        ++cantTareasEmpleados;
    }

    FILE *newFile = fopen("ProyectoCantTareas.dat", "ab");
    if (newFile == NULL) {
      return;
    }

    ProyectoTareas newThingy;
    newThingy = proyectoAux;
    newThingy.setTareas(cantTareasProyecto);

    fwrite(&newThingy, sizeof(newThingy), 1, newFile);

    fclose(newFile);
  }
}
