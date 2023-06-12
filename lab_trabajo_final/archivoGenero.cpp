#include "archivoGenero.h"

#include <cstring>
#include <iostream>

#include "cargarCadena.h"
#include "claseFecha.h"
#include "claseGeneroMusical.h"

#include "interfaz.h"
#include "rlutil.h"

ArchivoGeneroMusical::ArchivoGeneroMusical(const char *nuevoArchivo) {
  int tam = strlen(nuevoArchivo) + 1;

  nombre = new char[tam];
  if (nombre == NULL) {
    exit(1); // ver como hacer con este error :)
  }

  strncpy(nombre, nuevoArchivo, tam);
}

ArchivoGeneroMusical::~ArchivoGeneroMusical() { delete nombre; }

void ArchivoGeneroMusical::agregarRegistro() {
  int autoId = contarRegistros();
  if (autoId == -1) {
    autoId = 1;
  } else {
    ++autoId;
  }

  std::cout << " Ingrese los datos del género musical: \n";
  std::cout << "-----------------------------------------\n";

  GeneroMusical obj;
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

  fwrite(&obj, sizeof(GeneroMusical), 1, fileGeneroMusical);

  fclose(fileGeneroMusical);
}

void ArchivoGeneroMusical::mostrarRegistros() {
  FILE *fileGeneroMusical = fopen(nombre, "rb");
  if (fileGeneroMusical == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO.\n";
    return;
  }

  GeneroMusical obj;
  while (fread(&obj, sizeof obj, 1, fileGeneroMusical) == 1) {
    if (obj.getEstado()) {
      obj.Mostrar();
      std::cout << "-----------------------------------\n";
    }
  }
  fclose(fileGeneroMusical);
}

GeneroMusical ArchivoGeneroMusical::leerRegistro(int p) {
  GeneroMusical obj;

  if (p < 0) {
    obj.setId(-3);
    return obj;
  }

  FILE *fileGeneroMusical = fopen(nombre, "rb");
  if (fileGeneroMusical == NULL) {
    obj.setId(-2);
    return obj;
  }

  fseek(fileGeneroMusical, (sizeof(GeneroMusical) * p), SEEK_SET);

  if (!fread(&obj, sizeof(GeneroMusical), 1, fileGeneroMusical)) {
    obj.setId(-1);
  }

  fclose(fileGeneroMusical);

  return obj;
}

int ArchivoGeneroMusical::buscarRegistro(int id) {
  FILE *fileGeneroMusical = fopen(nombre, "rb");
  if (fileGeneroMusical == NULL) {
    return -2;
  }

  int pos = 0;
  GeneroMusical obj;

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

bool ArchivoGeneroMusical::modificarRegistro(GeneroMusical obj, int pos) {
  FILE *fileGeneroMusical = fopen(nombre, "rb+");
  if (fileGeneroMusical == NULL) {
    std::cout << "ERROR AL REABRIR EL ARCHIVO.\n";
    return false;
  }

  fseek(fileGeneroMusical, sizeof(GeneroMusical) * pos, SEEK_SET);

  bool aux = fwrite(&obj, sizeof(GeneroMusical), 1, fileGeneroMusical);
  fclose(fileGeneroMusical);

  return aux;
}

bool ArchivoGeneroMusical::escribirRegistro(GeneroMusical obj) {
  FILE *archivo = fopen(nombre, "ab");
  if (archivo == NULL) {
    std::cout << "NO SE PUDO CREAR EL ARCHIVO.\n";
    return false;
  }

  bool aux = fwrite(&obj, sizeof(obj), 1, archivo);

  fclose(archivo);

  return aux;
}

int ArchivoGeneroMusical::contarRegistros() {
  FILE *generos = fopen(nombre, "rb");
  if (generos == NULL) {
    return -1;
  }

  fseek(generos, 0, SEEK_END);

  int cantidad = ftell(generos) / sizeof(GeneroMusical);

  fclose(generos);

  return cantidad;
}

void ArchivoGeneroMusical::buscarPorID() {
  int ID = cargarInt("INGRESE EL ID A BUSCAR: ");

  int pos = buscarRegistro(ID);
  if (pos == -2) {
    std::cout << "No se pudo abrir el archivo.\n";
    return;
  } else if (pos == -1) {
    std::cout << "No se encontró el registro.\n";
    return;
  }

  GeneroMusical obj = leerRegistro(pos);
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

bool ArchivoGeneroMusical::bajaLogica() {
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

  GeneroMusical obj = leerRegistro(pos);

  if (obj.getEstado() == false) {
    std::cout << "EL GENERO INGRESADO YA ESTA DADO DE BAJA.\n";
    return false;
  }

  // Modificarmos el campo estado (lo ponemos en false)
  obj.setEstado(false);

  // Sobreescribir
  return modificarRegistro(obj, pos);
}

bool ArchivoGeneroMusical::modificarAnioOrigen() {
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

  GeneroMusical obj = leerRegistro(pos);

  if (!obj.getEstado()) {
    std::cout << "Registro dado de baja.\n";
    return false;
  }

  std::cout << "---------------------------------------------------------------"
               "----\n";
  std::cout << "Genero: " << obj.getNombre() << '\n';
  std::cout << "Año de origen actual: " << obj.getAnioOrigen() << '\n';
  std::cout << "---------------------------------------------------------------"
               "----\n";

  int nuevoAnio = cargarInt("Ingresar nuevo año de origen: ");
  obj.setAnioOrigen(nuevoAnio);

  return modificarRegistro(obj, pos);
}

bool ArchivoGeneroMusical::copiaSeguridad() {
  const char *backup = agregarExtensionBackup(nombre);

  GeneroMusical obj;
  bool copiado = copiarArchivo(nombre, backup, &obj, sizeof(obj));

  delete backup;
  return copiado;
}

bool ArchivoGeneroMusical::restaurarCopia() {
  const char *backup = agregarExtensionBackup(nombre);

  GeneroMusical obj;
  bool restaurado = copiarArchivo(backup, nombre, &obj, sizeof(obj));

  delete backup;
  return restaurado;
}

int listarSeleccion(int pagina, int height, int posx, int posy, GeneroMusical vRegistros[], int cantActivos) {
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

int ArchivoGeneroMusical::seleccionarRegistro(int posx, int posy, int boxWidth, int boxHeight) {
  if (posx < 0) {
    posx = rlutil::tcols() - boxWidth;
  }

  if (boxHeight < 0) {
    boxHeight = rlutil::trows() - 10;
  }

  innerBox inner = dibujarCajaTitulo(posx, posy, boxWidth, boxHeight, "SELECCIONAR PAIS");
  int cantRegistros = contarRegistros();

  GeneroMusical *vRegistros = new GeneroMusical[cantRegistros];
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
