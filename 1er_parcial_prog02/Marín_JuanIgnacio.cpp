#include <cstring>
#include <iostream>

using namespace std;

#include "parcial1.h"

class ProyectosNoTerminados {
private:
  char codigo[5];
  char nombre[30];
  Fecha fecha;

public:
  void setNombre(const char *n) { strncpy(nombre, n, 30); }
  void setCodigo(const char *c) { strncpy(codigo, c, 5); }
  void setFecha(Fecha f) { fecha = f; }
  void Mostrar() {
    cout << codigo << " " << nombre << " ";
    cout << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio()
         << '\n';
  }
};

void pregunta1();
void mostrarPregunta1();
void pregunta2();

int main() {
  pregunta1();
  mostrarPregunta1();
  pregunta2();
}

void pregunta1() {
  ArchivoProyecto entrada("proyectos.dat");

  int cantRegistros = entrada.contarRegistros();

  Proyecto proyecto;
  ProyectosNoTerminados proyectoNoTerminado;
  for (int i = 0; i < cantRegistros; ++i) {
    proyecto = entrada.leerRegistro(i);

    if (proyecto.getEstadoDesarrollo() != 4 &&
        proyecto.getFechaInicio().getAnio() == 2023) {
      FILE *salida = fopen("proyectosNoTerminados2023.dat", "ab");
      if (salida == NULL) {
        cout << "No se pudo abrir el nuevo archivo.\n";
        return;
      }

      proyectoNoTerminado.setCodigo(proyecto.getCodigoProyecto());
      proyectoNoTerminado.setNombre(proyecto.getNombre());
      proyectoNoTerminado.setFecha(proyecto.getFechaInicio());

      fwrite(&proyectoNoTerminado, sizeof(ProyectosNoTerminados), 1, salida);

      fclose(salida);
    }
  }
}

void mostrarPregunta1() {
  FILE *salida = fopen("proyectosNoTerminados2023.dat", "rb");
  if (salida == NULL) {
    cout << "No se pudo abrir el nuevo archivo.\n";
    return;
  }

  ProyectosNoTerminados proyectoNoTerminado;

  cout << "Archivo generado: \n";
  cout << "-----------------------\n";
  while (fread(&proyectoNoTerminado, sizeof(proyectoNoTerminado), 1, salida)) {
    proyectoNoTerminado.Mostrar();
  }

  fclose(salida);

  cout << '\n';
}

void pregunta2() {
  ArchivoTarea entrada("tareas.dat");

  int cantRegistros = entrada.contarRegistros();

  int cantTareasXCategoria[5] = {};
  Tarea tarea;

  for (int i = 0; i < cantRegistros; ++i) {
    tarea = entrada.leerRegistro(i);

    ++cantTareasXCategoria[tarea.getCategoria() - 1];
  }

  int indiceMinCategoria = 0;

  for (int i = 0; i < 5; ++i) {
    if (cantTareasXCategoria[i] < cantTareasXCategoria[indiceMinCategoria]) {
      indiceMinCategoria = i;
    }
  }

  cout << "La categoria con menos cantidad de tareas es la "
       << indiceMinCategoria + 1 << '\n';
}
