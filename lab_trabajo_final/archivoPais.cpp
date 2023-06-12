#include "archivoPais.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "claseFecha.h"
#include "clasePais.h"

#include "interfaz.h"
#include "rlutil.h"

ArchivoPais::ArchivoPais(const char *nuevoArchivo) {
  int tam = strlen(nuevoArchivo) + 1;

  nombre = new char[tam];
  if (nombre == NULL) {
    exit(1); // ver como hacer con este error :)
  }

  strncpy(nombre, nuevoArchivo, tam);
}

ArchivoPais::~ArchivoPais() { delete nombre; }

void ArchivoPais::agregarRegistro() {
  int autoId = contarRegistros();
  if (autoId == -1) {
    autoId = 1;
  } else {
    ++autoId;
  }

  std::cout << " Ingrese los datos del género musical: \n";
  std::cout << "-----------------------------------------\n";

  Pais obj;
  obj.Cargar(autoId);

  int pos = buscarRegistro(obj.getId());

  if (pos == -2) {
    std::cout << "El archivo no se encontro. Creando archivo.\n";
  } else if (pos != -1) {
    std::cout << "Ya hay un registro con ese ID.\n";
    return;
  }

  FILE *fileGeneroMusical = fopen(nombre, "ab");
  if (fileGeneroMusical == NULL) {
    std::cout << "No se pudo abrir el archivo.\n";
    return;
  }

  fwrite(&obj, sizeof(Pais), 1, fileGeneroMusical);

  fclose(fileGeneroMusical);
}

void ArchivoPais::mostrarRegistros() {
  FILE *fileGeneroMusical = fopen(nombre, "rb");
  if (fileGeneroMusical == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO.\n";
    return;
  }

  Pais obj;
  while (fread(&obj, sizeof obj, 1, fileGeneroMusical) == 1) {
    if (obj.getEstado()) {
      obj.Mostrar();
      std::cout << "-----------------------------------\n";
    }
  }
  fclose(fileGeneroMusical);
}

Pais ArchivoPais::leerRegistro(int p) {
  Pais obj;

  if (p < 0) {
    obj.setId(-3);
    return obj;
  }

  FILE *fileGeneroMusical = fopen(nombre, "rb");
  if (fileGeneroMusical == NULL) {
    obj.setId(-2);
    return obj;
  }

  fseek(fileGeneroMusical, (sizeof(Pais) * p), SEEK_SET);

  if (!fread(&obj, sizeof(Pais), 1, fileGeneroMusical)) {
    obj.setId(-1);
  }

  fclose(fileGeneroMusical);

  return obj;
}

int ArchivoPais::buscarRegistro(int id) {
  FILE *fileGeneroMusical = fopen(nombre, "rb");
  if (fileGeneroMusical == NULL) {
    return -2;
  }

  int pos = 0;
  Pais obj;

  while (fread(&obj, sizeof(obj), 1, fileGeneroMusical) == 1) {
    if (id == obj.getId()) {
      fclose(fileGeneroMusical);
      return pos;
    }
    ++pos;
  }

  fclose(fileGeneroMusical);

  return -1;
}

bool ArchivoPais::modificarRegistro(Pais obj, int pos) {
  FILE *fileGeneroMusical = fopen(nombre, "rb+");
  if (fileGeneroMusical == NULL) {
    std::cout << "ERROR AL REABRIR EL ARCHIVO.\n";
    return false;
  }

  fseek(fileGeneroMusical, sizeof(Pais) * pos, SEEK_SET);

  bool aux = fwrite(&obj, sizeof(Pais), 1, fileGeneroMusical);
  fclose(fileGeneroMusical);

  return aux;
}

int ArchivoPais::contarRegistros() {
  FILE *generos = fopen(nombre, "rb");
  if (generos == NULL) {
    return -1;
  }

  fseek(generos, 0, SEEK_END);

  int cantidad = ftell(generos) / sizeof(Pais);

  fclose(generos);

  return cantidad;
}

void ArchivoPais::buscarPorID() {
  int ID = cargarInt("INGRESE EL ID A BUSCAR: ");

  int pos = buscarRegistro(ID);
  if (pos == -2) {
    std::cout << "No se pudo abrir el archivo.\n";
    return;
  } else if (pos == -1) {
    std::cout << "No se encontró el registro.\n";
    return;
  }

  Pais obj = leerRegistro(pos);
  if (!obj.getEstado()) {
    std::cout << "Registro dado de baja.\n";
    return;
  }

  if (obj.getId() > 0) {
    std::cout << "---------------------------------\n";
    obj.Mostrar();
    std::cout << "---------------------------------\n";

  } else if (obj.getId() == -3) {
    std::cout << "Se puso una posición inválida.\n";
  } else if (obj.getId() == -1) {
    std::cout << "No se pudo leer el registro.\n";
  } else {
    std::cout << "No se pudo abrir el archivo.\n";
  }
}

bool ArchivoPais::bajaLogica() {
  // Solicitar que registro se quiere dar de baja
  int id = cargarInt("INGRESE EL ID A BUSCAR: ");

  // Buscar el registro en el archivo
  int pos = buscarRegistro(id);
  if (pos == -1) {
    std::cout << "NO EXISTE GENERO CON ESE ID.\n";
    return false;
  }
  if (pos == -2) {
    std::cout << "NO SE PUDO ABRIR ARCHIVO.\n";
    return false;
  }

  Pais obj = leerRegistro(pos);

  if (obj.getEstado() == false) {
    std::cout << "EL GENERO INGRESADO YA ESTA DADO DE BAJA.\n";
    return false;
  }

  // Modificarmos el campo estado (lo ponemos en false)
  obj.setEstado(false);

  // Sobreescribir
  return modificarRegistro(obj, pos);
}

bool ArchivoPais::modificarContinente() {
  int ID = cargarInt("Ingrese el ID a buscar: ");

  int pos = buscarRegistro(ID);
  if (pos == -1) {
    std::cout << "No existe genero con ese ID.\n";
    return false;
  }
  if (pos == -2) {
    std::cout << "No se pudo abrir el archivo.\n";
    return false;
  }

  Pais obj = leerRegistro(pos);

  if (!obj.getEstado()) {
    std::cout << "Registro dado de baja.\n";
    return false;
  }

  std::cout << "---------------------------------------------------------------"
               "----\n";
  std::cout << "Pais: " << obj.getNombre() << '\n';
  std::cout << "Continente Actual: " << obj.getContinente() << '\n';
  std::cout << "---------------------------------------------------------------"
               "----\n";

  char continente[30];
  std::cout << "Ingrese nuevo contienente: ";
  cargarCadena(continente, 30);

  obj.setContinente(continente);

  return modificarRegistro(obj, pos);
}

bool ArchivoPais::modificarNombre() {
  int ID = cargarInt("Ingrese el ID a buscar: ");

  int pos = buscarRegistro(ID);
  if (pos == -1) {
    std::cout << "No existe genero con ese ID.\n";
    return false;
  }
  if (pos == -2) {
    std::cout << "No se pudo abrir el archivo.\n";
    return false;
  }

  Pais obj = leerRegistro(pos);

  if (!obj.getEstado()) {
    std::cout << "Registro dado de baja.\n";
    return false;
  }

  std::cout << "---------------------------------------------------------------"
               "----\n";
  std::cout << "Nombre Actual: " << obj.getNombre() << '\n';
  std::cout << "Continente: " << obj.getContinente() << '\n';
  std::cout << "---------------------------------------------------------------"
               "----\n";

  char nombre[30];
  std::cout << "Ingrese nuevo nombre: ";
  cargarCadena(nombre, 30);

  obj.setNombre(nombre);

  return modificarRegistro(obj, pos);
}

bool ArchivoPais::copiaSeguridad() {
  const char *backup = agregarExtensionBackup(nombre);

  Pais obj;
  bool copiado = copiarArchivo(nombre, backup, &obj, sizeof(obj));

  delete backup;

  return copiado;
}

bool ArchivoPais::restaurarCopia() {
  const char *backup = agregarExtensionBackup(nombre);

  Pais obj;
  bool restaurado = copiarArchivo(backup, nombre, &obj, sizeof(obj));

  delete backup;

  return restaurado;
}

int listarSeleccion(int pagina, int height, int posx, int posy, Pais vRegistros[], int cantActivos) {
  int mostrados = 0;
  for (int i = pagina * (height); i < cantActivos && mostrados < height; ++i) {
    rlutil::locate(posx, posy + mostrados);
    if (vRegistros[i].getEstado()) {
      vRegistros[i].MostrarSeleccion();
      ++mostrados;
    }
  }
  return mostrados;
}

int ArchivoPais::seleccionarRegistro(int posx, int posy, int boxWidth, int boxHeight) {
  if (posx < 0) {
    posx = rlutil::tcols() - boxWidth;
  }

  if (boxHeight < 0) {
    boxHeight = rlutil::trows() - 10;
  }

  innerBox inner = dibujarCajaTitulo(posx, posy, boxWidth, boxHeight, "SELECCIONAR PAIS");
  int cantRegistros = contarRegistros();

  Pais *vRegistros = new Pais[cantRegistros];
  int cantActivos = 0;
  for (int i = 0; i < cantRegistros; ++i) {
    vRegistros[cantActivos] = leerRegistro(i);
    if (vRegistros[cantActivos].getEstado()) {
      ++cantActivos;
    }
  }

  int cantPaginas = cantActivos / inner.height;
  int pagina = 0;

  int mostrados = listarSeleccion(pagina, inner.height, inner.posx, inner.posy, vRegistros, cantActivos);

  int cursor = inner.posy;
  int seleccionado = 0;
  rlutil::locate(inner.posx, cursor);
  std::cout << '>';
  while (true) {
    switch (rlutil::getkey()) {
      case rlutil::KEY_DOWN: {
        rlutil::locate(inner.posx, cursor);
        std::cout << ' ';

        ++cursor;
        if (cursor > inner.posy + mostrados - 1) {
          cursor = inner.posy + mostrados - 1;
          if (cantPaginas > 0 && pagina < cantPaginas) {
            ++pagina;
            clearInnerBox(inner);
            mostrados = listarSeleccion(pagina, inner.height, inner.posx, inner.posy, vRegistros, cantActivos);
            cursor = inner.posy;
          }
        }
        seleccionado = cursor - inner.posy;

        rlutil::locate(inner.posx, cursor);
        std::cout << '>';
      } break;

      case rlutil::KEY_UP: {
        rlutil::locate(inner.posx, cursor);
        std::cout << ' ';

        --cursor;
        if (cursor < inner.posy) {
          cursor = inner.posy;
          if (cantPaginas > 0 && pagina > 0) {
            --pagina;
            clearInnerBox(inner);
            mostrados = listarSeleccion(pagina, inner.height, inner.posx, inner.posy, vRegistros, cantActivos);
            cursor = inner.posy + mostrados - 1;
          }
        }
        seleccionado = cursor - inner.posy;

        rlutil::locate(inner.posx, cursor);
        std::cout << '>';
      } break;

      case rlutil::KEY_LEFT: {
        // Hacer que cargatInt();
        // checkeando en el vector si existe el id del instrumento
        // y está en alta.
      } break;

      case rlutil::KEY_ENTER: {
        int id_seleccionada = vRegistros[seleccionado].getId();
        delete[] vRegistros;
        clearBox(posx, posy, boxWidth, boxHeight);
        return id_seleccionada;
      } break;
    }
  }

  delete[] vRegistros;
  return 0;
}
