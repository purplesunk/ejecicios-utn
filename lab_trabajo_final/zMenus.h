#ifndef ZMENUS_H_INCLUDED
#define ZMENUS_H_INCLUDED

void mostrarOpciones(const char *titulo, const char *atras, char opciones[][60], int cantOpciones, int posx, int y) {
  rlutil::locate(posx + 6, 2);
  std::cout << titulo;

  for (int i = 0; i < cantOpciones; ++i) {
    mostrarOpcion(opciones[i], posx, 4 + i,  y == (i + 1));
  }

  mostrarOpcion(atras, posx, 6 + cantOpciones, y == 0);
}

int elegirOpcion(int y, const int MAX_OPT, int (*func)(int)) {
  char key = rlutil::getkey();
  switch(key) {
    case rlutil::KEY_DOWN: {
      ++y;
      if (y > MAX_OPT) {
        y = 0;
      }
    } break;

    case rlutil::KEY_UP: {
      --y;
      if (y < 0) {
        y = MAX_OPT;
      }
    } break;

    case rlutil::KEY_ENTER: {
      if (func(y) == 0) {
        return -1;
      }
    } break;

    default: {
      int opcion = key - 48;
      // solo funciona hastas 9 opciones
      if (opcion >= 0 && opcion <= MAX_OPT) {
        y = opcion;
      }
    } break;
  }
  return y;
}

int opcionesMusicos(int y) {
  rlutil::cls();
  ArchivoMusico archivo("musicos.dat");
  switch (y) {
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
        mostrarAviso("  FECHA MODIFICADA CORRECTAMENTE.\n");
      } else {
        mostrarAviso("  LA FECHA NO FUE MODIFICADA.\n");
      }
      break;
    case 5:
      if (archivo.bajaLogica()) {
        mostrarAviso("  REGISTRO ELIMINADO CORRECTAMENTE.\n");
      } else {
        mostrarAviso("  EL REGISTRO NO PUDO SER ELIMINADO.\n");
      }
      break;
    case 0:
      return 0;
      break;
  }
  pause();
  rlutil::cls();
  return y;
}

void menuMusicos(int posx) {
  int y = 1;
  const int MAX_OPT = 5;
  char opciones[MAX_OPT][60];
  strncpy(opciones[0],  "1) AGREGAR MUSICO", 60);
  strncpy(opciones[1],  "2) LISTAR MUSICO POR DNI", 60);
  strncpy(opciones[2],  "3) LISTAR TODO", 60);
  strncpy(opciones[3],  "4) MODIFICAR FECHA DE INSCRIPCION", 60);
  strncpy(opciones[4],  "5) ELIMINAR REGISTRO", 60);
  while (true) {
    mostrarOpciones("MENU MUSICOS", "0) VOLVER AL MENU PRINCIPAL", opciones, MAX_OPT, posx, y);
    y = elegirOpcion(y, MAX_OPT, &opcionesMusicos);
    if (y == -1) return;
  }
}

int opcionesGeneros(int y) {
  rlutil::cls();
  ArchivoGeneroMusical archivo("generos.dat");
  switch (y) {
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
        mostrarAviso("  ANIO DE ORIGEN MODIFICADO CORRECTAMENTE.\n");
      } else {
        mostrarAviso("  ANIO DE ORIGEN NO PUDO SER MODIFICADO.\n");
      }
      break;
    case 5:
      if (archivo.bajaLogica()) {
        mostrarAviso("  REGISTRO ELIMINADO CORRECTAMENTE.\n");
      } else {
        mostrarAviso("  NO SE PUDO ELIMINAR EL REGISTRO.\n");
      }
      break;
    case 0:
      return 0;
      break;
  }
  pause();
  rlutil::cls();
  return y;
}

void menuGeneros(int posx) {
  int y = 1;
  const int MAX_OPT = 5;
  char opciones[MAX_OPT][60];
  strncpy(opciones[0],  "1) AGREGAR GENERO", 60);
  strncpy(opciones[1],  "2) LISTAR GENERO POR ID", 60);
  strncpy(opciones[2],  "3) LISTAR TODO", 60);
  strncpy(opciones[3],  "4) MODIFICAR ANIO DE ORIGEN", 60);
  strncpy(opciones[4],  "5) ELIMINAR REGISTRO", 60);
  while (true) {
    mostrarOpciones("MENU GENEROS MUSICALES", "0) VOLVER AL MENU PRINCIPAL", opciones, MAX_OPT, posx, y);
    y = elegirOpcion(y, MAX_OPT, &opcionesGeneros);
    if (y == -1) return;
  }
}

int opcionesPaises(int y) {
  rlutil::cls();
  ArchivoPais archivo("paises.dat");
  switch (y) {
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
      if (archivo.modificarNombre()) {
        mostrarAviso("  NOMBRE MODIFICADO.");
      } else {
        mostrarAviso("  NO SE PUDO MODIFICAR EL NOMBRE.\n");
      }
      break;
    case 5:
      if (archivo.bajaLogica()) {
        mostrarAviso("  REGISTRO ELIMINADO CORRECTAMENTE.\n");
      } else {
        mostrarAviso("  NO SE PUDO ELIMINAR EL REGISTRO.\n");
      }
      break;
    case 0:
      return 0;
      break;
  }
  pause();
  rlutil::cls();
  return y;
}

void menuPaises(int posx) {
  int y = 1;
  const int MAX_OPT = 5;
  char opciones[MAX_OPT][60];
  strncpy(opciones[0],  "1) AGREGAR PAIS", 60);
  strncpy(opciones[1],  "2) LISTAR PAIS POR ID", 60);
  strncpy(opciones[2],  "3) LISTAR TODO", 60);
  strncpy(opciones[3],  "4) MODIFICAR NOMBRE", 60);
  strncpy(opciones[4],  "5) ELIMINAR REGISTRO", 60);
  while (true) {
    mostrarOpciones("MENU PAISES", "0) VOLVER AL MENU PRINCIPAL", opciones, MAX_OPT, posx, y);
    y = elegirOpcion(y, MAX_OPT, &opcionesPaises);
    if (y == -1) return;
  }

}

int opcionesInstrumentos(int y) {
  rlutil::cls();
  ArchivoInstrumento archivo("instrumentos.dat");
  switch (y) {
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
      if (archivo.modificarNombre()) {
        mostrarAviso("  NOMBRE MODIFICADO CORRECTAMENTE.\n");
      } else {
        mostrarAviso("  NOMBRE NO PUDO SER MODIFICADO.\n");
      }
      break;
    case 5:
      if (archivo.bajaLogica()) {
        mostrarAviso("  REGISTRO ELIMINADO CORRECTAMENTE.\n"); 
      } else {
        mostrarAviso("  NO SE PUDO ELIMINAR EL REGISTRO.\n");
      }
      break;
    case 0:
      return 0;
      break;
  }
  pause();
  rlutil::cls();
  return y;
}

void menuInstrumentos(int posx) {
  int y = 1;
  const int MAX_OPT = 5;
  char opciones[MAX_OPT][60];
  strncpy(opciones[0],  "1) AGREGAR INSTRUMENTO", 60);
  strncpy(opciones[1],  "2) LISTAR INSTRUMENTO POR ID", 60);
  strncpy(opciones[2],  "3) LISTAR TODO", 60);
  strncpy(opciones[3],  "4) MODIFICAR NOMBRE", 60);
  strncpy(opciones[4],  "5) ELIMINAR REGISTRO", 60);
  while (true) {
    mostrarOpciones("MENU INSTRUMENTOS", "0) VOLVER AL MENU PRINCIPAL", opciones, MAX_OPT, posx, y);
    y = elegirOpcion(y, MAX_OPT, &opcionesInstrumentos);
    if (y == -1) return;
  }
}

int opcionesConfiguracion(int y) {
  rlutil::cls();
  bool hecho;
  switch (y) {
    case 1: {
      ArchivoMusico archivo("musicos.dat");
      hecho = archivo.copiaSeguridad();
    } break;
    case 2: {
      ArchivoGeneroMusical archivo("generos.dat");
      hecho = archivo.copiaSeguridad();
    } break;
    case 3: {
      ArchivoInstrumento archivo("instrumentos.dat");
      hecho = archivo.copiaSeguridad();
    } break;
    case 4: {
      ArchivoPais archivo("paises.dat");
      hecho = archivo.copiaSeguridad();
    } break;
    case 5: {
      ArchivoMusico archivo("musicos.dat");
      hecho = archivo.restaurarCopia();
    } break;
    case 6: {
      ArchivoGeneroMusical archivo("generos.dat");
      hecho = archivo.restaurarCopia();
    } break;
    case 7: {
      ArchivoInstrumento archivo("instrumentos.dat");
      hecho = archivo.restaurarCopia();
    } break;
    case 8: {
      ArchivoPais archivo("paises.dat");
      hecho = archivo.restaurarCopia();
    } break;
    case 9:{
      ArchivoPais paises("paises.dat");
      ArchivoMusico musicos("musicos.dat");
      ArchivoInstrumento instrumentos("instrumentos.dat");
      ArchivoGeneroMusical generos("generos.dat");
      bool p = paises.restaurarInicio();
      bool m = musicos.restaurarInicio();
      bool i = instrumentos.restaurarInicio();
      bool g = generos.restaurarInicio();
      hecho = p && m && i && g;
    }
    break;
    case 0:
      return 0;
      break;
  }

  if (hecho) {
    mostrarAviso("  ACCION REALIZADA CORRECTAMENTE.\n");
  } else {
    mostrarAviso("  NO SE PUDO REALIZAR LA ACCION.\n");
  }

  pause();
  rlutil::cls();
  return y;
}

void menuConfiguracion(int posx) {
  int y = 1;
  const int MAX_OPT = 9;
  char opciones[MAX_OPT][60];
  strncpy(opciones[0], "1) COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS", 60);
  strncpy(opciones[1], "2) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS", 60);
  strncpy(opciones[2], "3) COPIA DE SEGURIDAD DEL ARCHIVO DE INSTRUMENTOS", 60);
  strncpy(opciones[3], "4) COPIA DE SEGURIDAD DEL ARCHIVO DE PAISES", 60);
  strncpy(opciones[4], "5) RESTAURAR EL ARCHIVO DE MUSICOS", 60);
  strncpy(opciones[5], "6) RESTAURAR EL ARCHIVO DE GENEROS", 60);
  strncpy(opciones[6], "7) RESTAURAR EL ARCHIVO DE INSTRUMENTOS", 60);
  strncpy(opciones[7], "8) RESTAURAR EL ARCHIVO DE PAISES", 60);
  strncpy(opciones[8], "9) ESTABLECER DATOS DE INICIO", 60);
  while (true) {
    mostrarOpciones("MENU CONFIGURACION", "0) VOLVER AL MENU PRINCIPAL", opciones, MAX_OPT, posx, y);
    y = elegirOpcion(y, MAX_OPT, &opcionesConfiguracion);
    if (y == -1) return;
  }
}

int opcionesReportes(int y) {
  rlutil::cls();
  switch (y) {
    case 1:
      punto1();
      break;
    case 2:
      punto2();
      break;
    case 3:
      punto3();
      break;
    case 0:
      return 0;
      break;
  }
  pause();
  rlutil::cls();
  return y;
}

void menuReportes(int posx) {
  int y = 1;
  const int MAX_OPT = 3;
  char opciones[MAX_OPT][60];
  strncpy(opciones[0], "1) PUNTO 1", 60);
  strncpy(opciones[1], "2) PUNTO 2", 60);
  strncpy(opciones[2], "3) PUNTO 3", 60);
  while (true) {
    mostrarOpciones("MENU REPORTES", "0) VOLVER AL MENU PRINCIPAL", opciones, MAX_OPT, posx, y);
    y = elegirOpcion(y, MAX_OPT, &opcionesReportes);
    if (y == -1) return;
  }
}

#endif
