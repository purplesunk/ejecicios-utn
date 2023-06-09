#ifndef ZMENUS_H_INCLUDED
#define ZMENUS_H_INCLUDED

int menuMusicos() {
  ArchivoMusico archivo("musicos.dat");

  while (true) {
    std::cout << "  MENU MUSICOS\n";
    std::cout << "---------------------------------------\n";
    std::cout << "1) AGREGAR MUSICOS\n";
    std::cout << "2) LISTAR MUSICO POR DNI\n";
    std::cout << "3) LISTAR TODOS LOS MUSICOS\n";
    std::cout << "4) MODIFICAR FECHA DE INSCRIPCION\n";
    std::cout << "5) ELIMINAR REGISTRO DE MUSICO\n";
    std::cout << "---------------------------------------\n";
    std::cout << "0) VOLVER AL MENÚ PRINCIPAL\n\n";

    int opcion = cargarInt("SELECCIONAR OPCION: ");

    rlutil::cls();

    switch (opcion) {
    case 1:
      archivo.agregarRegistro();
      break;
    case 2:
      archivo.buscarPorDNI();
      break;
    case 3:
      archivo.mostrarRegistros();
      break;
    case 4:
      if (archivo.modificarFecha()) {
        std::cout << "Fecha modificada correctamente.\n";
      } else {
        std::cout << "La fecha no fue modificada.\n";
      }
      break;
    case 5:
      if (archivo.bajaLogica()) {
        std::cout << "Registro eliminado correctamente.\n";
      } else {
        std::cout << "El registro no pudo ser eliminado.\n";
      }
      break;
    case 0:
      return 0;
      break;
    default:
      std::cout << "LA OPCION NO EXISTE.\n";
      break;
    }
    rlutil::anykey();
    rlutil::cls();
  }
}

int menuGeneros() {
  ArchivoGeneroMusical archivo("generos.dat");

  while (true) {
    std::cout << "  MENU GÉNEROS\n";
    std::cout << "---------------------------------------\n";
    std::cout << "1) AGREGAR GÉNERO\n";
    std::cout << "2) LISTAR GÉNERO POR ID\n";
    std::cout << "3) LISTAR TODO\n";
    std::cout << "4) MODIFICAR AÑO DE ORIGEN\n";
    std::cout << "5) ELIMINAR REGISTRO\n";
    std::cout << "---------------------------------------\n";
    std::cout << "0) VOLVER AL MENÚ PRINCIPAL\n\n";

    int opcion = cargarInt("SELECCIONAR OPCION: ");

    rlutil::cls();

    switch (opcion) {
    case 1:
      archivo.agregarRegistro();
      break;
    case 2:
      archivo.buscarPorID();
      break;
    case 3:
      archivo.mostrarRegistros();
      break;
    case 4:
      if (archivo.modificarAnioOrigen()) {
        std::cout << "Año de origen modificado correctamente.\n";
      } else {
        std::cout << "Año de origen no pudo ser modificado.\n";
      }
      break;
    case 5:
      if (archivo.bajaLogica()) {
        std::cout << "Registro eliminado correctamente.\n";
      } else {
        std::cout << "No se pudo eliminar el registro.\n";
      }
      break;
    case 0:
      return 0;
      break;
    default:
      std::cout << "LA OPCION NO EXISTE.\n";
      break;
    }
    rlutil::anykey();
    rlutil::cls();
  }
}

int menuConfiguracion() {
  while (true) {
    std::cout << "  MENÚ CONFIGURACIÓN\n";
    std::cout << "---------------------------------------\n";
    std::cout << "1) COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS\n";
    std::cout << "2) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS\n";
    std::cout << "3) COPIA DE SEGURIDAD DEL ARCHIVO DE INSTRUMENTOS\n";
    std::cout << "4) COPIA DE SEGURIDAD DEL ARCHIVO DE PAISES\n";
    std::cout << "5) RESTAURAR EL ARCHIVO DE MUSICOS\n";
    std::cout << "6) RESTAURAR EL ARCHIVO DE GENEROS\n";
    std::cout << "7) RESTAURAR EL ARCHIVO DE INSTRUMENTOS\n";
    std::cout << "8) RESTAURAR EL ARCHIVO DE PAISES\n";
    std::cout << "9) ESTABLECER DATOS DE INICIO\n";
    std::cout << "---------------------------------------\n";
    std::cout << "0) VOLVER AL MENÚ PRINCIPAL\n\n";

    int opcion = cargarInt("SELECCIONAR OPCION: ");

    rlutil::cls();

    switch (opcion) {
    case 1: {
      ArchivoMusico archivo("musicos.dat");
      if (archivo.copiaSeguridad()) {
        std::cout << "Copia de seguridad completada.\n";
      } else {
        std::cout << "Copia de seguridad no se pudo completar.\n";
      }
    } break;
    case 2: {
      ArchivoGeneroMusical archivo("generos.dat");
      if (archivo.copiaSeguridad()) {
        std::cout << "Copia de seguridad completada.\n";
      } else {
        std::cout << "Copia de seguridad no se pudo completar.\n";
      }
    } break;
    case 3: {
      ArchivoInstrumento archivo("instrumentos.dat");
      if (archivo.copiaSeguridad()) {
        std::cout << "Copia de seguridad completada.\n";
      } else {
        std::cout << "Copia de seguridad no se pudo completar.\n";
      }
    } break;
    case 4: {
      ArchivoPais archivo("paises.dat");
      if (archivo.copiaSeguridad()) {
        std::cout << "Copia de seguridad completada.\n";
      } else {
        std::cout << "Copia de seguridad no se pudo completar.\n";
      }
    } break;

    case 5: {
      ArchivoMusico archivo("musicos.dat");
      if (archivo.restaurarCopia()) {
        std::cout << "Copia de seguridad restaurada.\n";
      } else {
        std::cout << "Copia de seguridad no se pudo restaurar.\n";
      }
    } break;
    case 6: {
      ArchivoGeneroMusical archivo("generos.dat");
      if (archivo.restaurarCopia()) {
        std::cout << "Copia de seguridad restaurada.\n";
      } else {
        std::cout << "Copia de seguridad no se pudo restaurar.\n";
      }
    } break;
    case 7: {
      ArchivoInstrumento archivo("instrumentos.dat");
      if (archivo.restaurarCopia()) {
        std::cout << "Copia de seguridad restaurada.\n";
      } else {
        std::cout << "Copia de seguridad no se pudo restaurar.\n";
      }
    } break;
    case 8: {
      ArchivoPais archivo("paises.dat");
      if (archivo.restaurarCopia()) {
        std::cout << "Copia de seguridad restaurada.\n";
      } else {
        std::cout << "Copia de seguridad no se pudo restaurar.\n";
      }
    } break;
    case 9:
      if (restablecerInicio()) {
        std::cout << "Datos iniciales restablecidos.\n";
      } else {
        std::cout
            << "Datos iniciales no pudieron ser restablecidos correctamente.\n";
      }
      break;
    case 0:
      return 0;
      break;
    default:
      std::cout << "LA OPCION NO EXISTE.\n";
      break;
    }
    rlutil::anykey();
    rlutil::cls();
  }
}

void menuReportes() {
  while (true) {
    std::cout << "  REPORTES\n";
    std::cout << "---------------------------------------\n";
    std::cout << "1) Listar Bateristas\n";
    std::cout << "2) Instrumento con menos Músicos\n";
    std::cout << "3) Generar archivo\n";
    std::cout << "---------------------------------------\n";
    std::cout << "0) VOLVER AL MENU PRINCIPAL\n\n";

    int opcion = cargarInt("SELECCIONAR OPCION: ");

    rlutil::cls();

    switch (opcion) {
    case 1:
      listarBateristas();
      break;
    case 2:
      instrumentoMenosMusicos();
      break;
    case 3:
      generarNoGuitarristas();
      break;
    case 0:
      return;
      break;
    }
    rlutil::anykey();
    rlutil::cls();
  }
}

void menuPaises() {
  ArchivoPais archivo("paises.dat");

  while (true) {
    std::cout << "  MENU PAISES\n";
    std::cout << "---------------------------------------\n";
    std::cout << "1) AGREGAR PAISES\n";
    std::cout << "2) LISTAR PAIS POR ID\n";
    std::cout << "3) LISTAR TODO\n";
    std::cout << "4) MODIFICAR CONTINENTE\n";
    std::cout << "5) ELIMINAR REGISTRO\n";
    std::cout << "---------------------------------------\n";
    std::cout << "0) VOLVER AL MENU PRINCIPAL\n\n";

    int opcion = cargarInt("SELECCIONAR OPCION: ");

    rlutil::cls();

    switch (opcion) {
    case 1:
      archivo.agregarRegistro();
      break;
    case 2:
      archivo.buscarPorID();
      break;
    case 3:
      archivo.mostrarRegistros();
      break;
    case 4:
      if (archivo.modificarContinente()) {
        std::cout << "Continenete modificado.";
      } else {
        std::cout << "No se pudo modificar el continente.\n";
      }
      break;
    case 5:
      if (archivo.bajaLogica()) {
        std::cout << "Registro eliminado correctamente.\n";
      } else {
        std::cout << "No se pudo eliminar el registro.\n";
      }
      break;
    case 0:
      return;
      break;
    default:
      std::cout << "LA OPCION NO EXISTE.\n";
      break;
    }
    rlutil::anykey();
    rlutil::cls();
  }
}

void menuInstrumentos() {
  ArchivoInstrumento archivo("instrumentos.dat");

  while (true) {
    std::cout << "  MENU INSTRUMENTOS\n";
    std::cout << "---------------------------------------\n";
    std::cout << "1) AGREGAR Instrumento\n";
    std::cout << "2) LISTAR Instrumento POR ID\n";
    std::cout << "3) LISTAR TODO\n";
    std::cout << "4) MODIFICAR Clasificacion\n";
    std::cout << "5) ELIMINAR REGISTRO\n";
    std::cout << "---------------------------------------\n";
    std::cout << "0) VOLVER AL MENU PRINCIPAL\n\n";

    int opcion = cargarInt("SELECCIONAR OPCION: ");

    rlutil::cls();

    switch (opcion) {
    case 1:
      archivo.agregarRegistro();
      break;
    case 2:
      archivo.buscarPorID();
      break;
    case 3:
      archivo.mostrarRegistros();
      break;
    case 4:
      if (archivo.modificarClasificacion()) {
        std::cout << "Clasificacion modificada correctamente.\n";
      } else {
        std::cout << "Clasificacion no pudo ser modificado.\n";
      }
      break;
    case 5:
      if (archivo.bajaLogica()) {
        std::cout << "Registro eliminado correctamente.\n";
      } else {
        std::cout << "No se pudo eliminar el registro.\n";
      }
      break;
    case 0:
      return;
      break;
    default:
      std::cout << "LA OPCION NO EXISTE.\n";
      break;
    }
    rlutil::anykey();
    rlutil::cls();
  }
}

#endif
