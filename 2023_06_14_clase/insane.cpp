#include <cstring>
#include <iostream>

using namespace std;

#include "parcial1.h"

class VisibilidadCiudad {
private:
  char codigoCiudad[5];
  char nombre[30];
  float promedioVisibilidad;

public:
  void setCodigo(const char *codigo) { strncpy(codigoCiudad, codigo, 4); }
  void setNombre(const char *name) { strncpy(nombre, name, 29); }
  void setPromedio(int cant) { promedioVisibilidad = cant; }

  void operator=() {
  }
};

// Ciudades.dat
// Código de ciudad, nombre, código de provincia (1 a 24).
//
// Mediciones.dat
// Código de ciudad, visibilidad, temperatura, fecha (día, mes y año).

void puntoA();
void puntoB();

int main() { 
  puntoA();
  puntoB();
}

void puntoA() {
  ArchivoCiudad ciudades("ciudades.dat");
  int cantCiudades = ciudades.contarRegistros();
  Ciudad *vCiudades = new Ciudad[cantCiudades];
  for (int i = 0; i < cantCiudades; ++i) {
    vCiudades[i] = ciudades.leerRegistro(i);
  }

  ArchivoMediciones mediciones("mediciones.dat");
  int cantMediciones = mediciones.contarRegistros();
  Medicion *vMediciones = new Medicion[cantMediciones];
  for (int i = 0; i < cantMediciones; ++i) {
    vMediciones[i] = mediciones.leerRegistro(i);
  }

  int visibilidad = 0;
  int contarMediciones = 0;
  VisibilidadCiudad obj;
  for (int i = 0; i < cantCiudades; ++i) {
    for (int j = 0; j < cantMediciones; ++j) {
      // Meibi string cmp dont know: 
      if (vCiudades[i].getCodigo() == vMediciones[j].getCodigoCiudad()){
        visibilidad += vMediciones[j].getVisibilidad();  
        ++contarMediciones;
      }
      
      if (contarMediciones > 0) {
        FILE *archivo = fopen("punto_a.dat", "ab");
        if (archivo == NULL) { return; } 

        float promedio = (float)visibilidad / (float)contarMediciones;

        VisibilidadCiudad.setCodigo(vCiudades[i].getCodigo());
        VisibilidadCiudad.setNombre(vCiudades[i].getNombre());
        VisibilidadCiudad.setPromedio(promedio);

        fwrite(&obj, sizeof(obj), 1, archivo);
        fclose(archivo);
      }
    }
  }

  delete[] vMediciones;
  delete[] vCiudades;
}

void puntoB() {
  ArchivoMediciones mediciones("mediciones.dat");
  int cantMediciones = mediciones.contarRegistros();
  Medicion *vMediciones = new Medicion[cantMediciones];
  for (int i = 0; i < cantMediciones; ++i) {
    vMediciones[i] = mediciones.leerRegistro(i);
  }

  int contarGrados[6][31] = {0}; 
  for (int i = 0; i < cantMediciones; ++i) {
    if (vMediciones[i].getMes() == 5) {
      int visibilidad = vMediciones[i].getVisibilidad();
      int dia = vMediciones[i].getDia();
      int grado;
      if (visibilidad > 0 && visibilidad <= 50) {
        grado = 1;
      } else if (visibilidad > 50 && visibilidad <= 500) {
        grado = 2;
      } else if (visibilidad > 500 && visibilidad <= 1000) {
        grado = 3;
      } else if (visibilidad > 1000 && visibilidad <= 4000) {
        grado = 4;
      } else if (visibilidad > 4000 && visibilidad <= 10000) {
        grado = 5;
      }else if (visibilidad > 10000) {
        grado = 6;
      }

      ++contarGrados[grado][dia - 1];
    }
  }

  for (int i = 0; i < 6; ++i) {
    cout << "Grado " << i << '\n';
    for (int j = 0; j < 31; ++j) {
      cout << "Dia " << j << ": ";
      cout << contarGrados[i][j] << '\n';
    }
  }
}
