#include <cstring>
#include <iostream>

// UTILIDADES
#include "cargarCadena.h"
#include "rlutil.h"

// CLASES
#include "claseFecha.h"
#include "claseGeneroMusical.h"
#include "claseInstrumento.h"
#include "claseMusico.h"
#include "clasePais.h"

// ARCHIVOS
#include "archivoGenero.h"
#include "archivoInstrumento.h"
#include "archivoMusico.h"
#include "archivoPais.h"

// OTROS
#include "interfaz.h"
#include "reportes.h"
#include "zMenus.h"

int opcionesMenuPrincipal(int y);

int main() {
  rlutil::cls();
  rlutil::hidecursor();

  int posx = 10;
  int y = 1;
  const int MAX_OPT = 6;

  char opciones[MAX_OPT][60];
  strncpy(opciones[0],  "1) MENU MUSICOS", 60);
  strncpy(opciones[1],  "2) MENU GENEROS", 60);
  strncpy(opciones[2],  "3) MENU INSTRUMENTOS", 60);
  strncpy(opciones[3],  "4) MENU PAISES", 60);
  strncpy(opciones[4],  "5) REPORTES", 60);
  strncpy(opciones[5],  "6) CONFIGURACION", 60);
  while (true) {
    mostrarOpciones("MENU PRINCIPAL", "0) FIN PROGRAMA", opciones, MAX_OPT, posx, y);
    y = elegirOpcion(y, MAX_OPT, &opcionesMenuPrincipal);
    if (y == -1) return 0;
  }
}

int opcionesMenuPrincipal(int y) {
  int posx = 10;
  rlutil::cls();
  switch (y) {
    case 1:
      menuMusicos(posx);
      break;
    case 2:
      menuGeneros(posx);
      break;
    case 5:
      menuReportes(posx);
      break;
    case 6:
      menuConfiguracion(posx);
      break;
    case 3:
      menuInstrumentos(posx);
      break;
    case 4:
      menuPaises(posx);
      break;
    case 0:
      return 0;
      break;
  }
  rlutil::cls();
  return y;
}
