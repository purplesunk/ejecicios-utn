#include <cstring>
#include <iostream>

/// Agregar un método que se llame agregarCaracter.
/// Agregar un método que se llame buscarCaracter que devuelva la posición de la
/// primera ocurrencia de ese carácter dentro del objeto. Agregar un método que
/// se llame contarCaracter que devuelva la cantidad de veces que aparece ese
/// carácter en el objeto.
///
/// SOBRECARGA DE OPERADORAS: EXTENDER LA FUNCIONALIDAD DE LOS OPERADORES DEL LENGUAJE.

using namespace std;

class Cadena {
private:
  char *cad;
  int tam;

public:
  Cadena(const char *cadena) {
    tam = strlen(cadena) + 1;
    cad = new char[tam];
    if (cad == NULL)
      exit(-1);
    strcpy(cad, cadena);
    cad[tam - 1] = '\0';
  }

  void setCadena(const char *cadena) {
    delete cad;
    tam = strlen(cadena) + 1;
    cad = new char[tam];
    if (cad == NULL)
      exit(-1);
    strcpy(cad, cadena);
    cad[tam - 1] = '\0';
  }

  void Concatenar(const char *cadena) {
    char *aux;
    aux = new char[tam];
    if (aux == NULL)
      exit(-1);
    strcpy(aux, cad);
    delete cad;
    tam = tam + strlen(cadena);
    cad = new char[tam];
    if (cad == NULL)
      exit(-2);
    strcpy(cad, aux);
    delete aux;
    strcat(cad, cadena);
    cad[tam - 1] = '\0';
  }

  void agregarCaracter(char newChar) {
    tam = tam + 1;

    char *cadenaAux = new char[tam];

    strcpy(cadenaAux, cad);

    delete cad;

    cadenaAux[tam - 2] = newChar;
    cadenaAux[tam - 1] = '\0';

    cad = cadenaAux;
  }

  int buscarCaracter(char charBuscado) {
    for (int i = 0; i < tam; ++i) {
      if(cad[i] == charBuscado) {
        return i + 1;
      }
    }
    return -1;
  }

  int contarCaracter(char charContado) {
    int apariciones = 0;
    for (int i = 0; i < tam; ++i) {
      if (cad[i] == charContado) {
        ++apariciones;
      }
    }
    return apariciones;
  }

  int getTam() { return tam; }
  const char *getCad() { return cad; }

  ~Cadena() { delete cad; }

  void Mostrar() { cout << cad; }

  bool operator==(Cadena otra) {
    if (strcmp(cad, otra.getCad())) return true;
    return false;
  }
};

int main() {
  Cadena obj("PALA");


  return 0;
}
