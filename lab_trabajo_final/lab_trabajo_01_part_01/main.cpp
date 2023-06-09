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
#include "reportes.h"
#include "zMenus.h"

int main() {
  while (true) {
    std::cout << "  MENU PRINCIPAL\n";
    std::cout << "---------------------------------------\n";
    std::cout << "1) MENU MUSICOS\n";
    std::cout << "2) MENU GENEROS\n";
    std::cout << "3) MENU INSTRUMENTOS\n";
    std::cout << "4) MENU PAISES\n";
    std::cout << "5) REPORTES\n";
    std::cout << "6) CONFIGURACION\n";
    std::cout << "---------------------------------------\n";
    std::cout << "0) FIN PROGRAMA\n\n";

    int opcion = cargarInt("SELECCIONAR OPCION: ");

    rlutil::cls();

    switch (opcion) {
    case 1:
      menuMusicos();
      break;
    case 2:
      menuGeneros();
      break;
    case 5:
      menuReportes();
      break;
    case 6:
      menuConfiguracion();
      break;
    case 3:
      menuInstrumentos();
      break;
    case 4:
      menuPaises();
      break;
    case 0:
      return 0;
      break;
    default:
      std::cout << "LA OPCION NO EXISTE.\n";
      break;
    }
    rlutil::cls();
  }
}
