#include "interfaz.h"

#include <iostream>
#include <cstring>
#include <iomanip>

#include "rlutil.h"

void dibujarCaja(int posx, int posy, int width, int height) {
  char corner_tr = char(191);
  char corner_br = char(217);
  char corner_bl = char(192);
  char corner_tl = char(218);
  char vertical = char(179);
  char horizontal = char(196);
  int innerWidth = width - 2;
  int innerHeight = height - 2;

  rlutil::locate(posx, posy);
  std::cout << corner_tl << std::setfill(horizontal)
    << std::setw(innerWidth) << std::right << corner_tr;

  ++posy;
  for (int i = 0; i < innerHeight; ++i) {
    rlutil::locate(posx, posy + i);
    std::cout << vertical;
    rlutil::locate(posx + innerWidth, posy + i);
    std::cout << vertical;
  }

  rlutil::locate(posx, posy + innerHeight);
  std::cout << corner_bl << std::setfill(horizontal)
    << std::setw(innerWidth) << std::right << corner_br;
}

innerBox dibujarCajaTitulo(int posx, int posy, int width, int height, const char *titulo) {
  int tamTitulo = strlen(titulo);
  int tamBordes = 2;
  int padding = 2;
  if (tamTitulo > width) {
    width = tamTitulo + tamBordes + padding;
  }

  dibujarCaja(posx, posy, width, height);
  rlutil::locate(posx + 2, posy + 1);
  std::cout << titulo;
  
  char pipe_r = char(180);
  char pipe_l = char(195);
  char horizontal = char(196);
  int innerWidth = width - tamBordes;

  rlutil::locate(posx, posy + 2);
  std::cout << pipe_l << std::setfill(horizontal)
    << std::setw(innerWidth) << std::right << pipe_r;

  innerBox caja;
  caja.posx = posx + 1;
  caja.posy = posy + 3;
  caja.width = innerWidth;
  caja.height = height - 4;

  return caja;
}

void clearInnerBox(innerBox caja) {
  int width = caja.width - 1;
  for (int i = 0; i < caja.height; ++i) {
   rlutil::locate(caja.posx, caja.posy + i);
    std::cout << std::setfill(' ') << std::setw(width) << ' ';
  }
}

void clearBox(int posx, int posy, int width, int height) {
  for (int i = 0; i < height; ++i) {
   rlutil::locate(posx, posy + i);
    std::cout << std::setfill(' ') << std::setw(width) << ' ';
  } 
}

void ponerColores(int fondo, int letra) {
    rlutil::setBackgroundColor(fondo);
    rlutil::setColor(letra);
}

void mostrarOpcion(const char* texto, int posx, int posy, bool seleccionado, int fondo, int letra, int minWidth) {
    rlutil::locate(posx,posy);
    if (seleccionado) {
      ponerColores(fondo, letra);
      std::cout << " > " << std::left << std::setfill(' ') << std::setw(minWidth) << texto << " < ";
    } else {
      std::cout << "   " << std::left << std::setfill(' ') << std::setw(minWidth) << texto << "   ";
    }
    ponerColores(rlutil::BLACK, rlutil::WHITE);
}

void mostrarSeleccion(int num, const char* texto, int posx, int posy, bool seleccionado, int fondo, int letra, int minWidth) {
    minWidth -= 11;
    rlutil::locate(posx,posy);
    if (seleccionado) {
      ponerColores(fondo, letra);
      std::cout << "> " << std:: right << std::setfill(' ') << std::setw(3) << num << " - " << std::left << std::setw(minWidth) << texto << " <";
    } else {
      std::cout << "  " << std:: right << std::setfill(' ') << std::setw(3) << num << " - " << std::left << std::setw(minWidth) << texto << "  ";
    }
    ponerColores(rlutil::BLACK, rlutil::WHITE);
}

void centrarTexto(const char *texto, int posy) {
  int text_width = strlen(texto);
  int term_width = rlutil::tcols();

  int centro = (term_width - text_width) / 2;
  
  rlutil::locate(centro, posy);
  std::cout << texto;
}

void pause() {
  std::cout << "\n  Presione una tecla para continuar.\n";
  rlutil::anykey();
}

int listarSeleccion(int pagina, int height, int posx, int posy, char **nombreObjetos, int cantObjetos, int seleccionado) {
  int mostrados = 0;
  for (int i = pagina * (height); i < cantObjetos && mostrados < height; ++i) {
    mostrarSeleccion(i, nombreObjetos[i], posx, posy + mostrados, seleccionado == i, 0, 2, 38);
    ++mostrados;
  }
  return mostrados;
}

int seleccionarObjeto(int posx, int posy, int boxWidth, int boxHeight, char **nombreObjetos, int cantObjetos, const char *titulo) {
  if (posx < 0) {
    posx = rlutil::tcols() - boxWidth;
  }
  if (boxHeight < 0) {
    int tHeight = rlutil::trows();
    if (tHeight > 19) {
      boxHeight = 14;
    } else {
      posy = 0;
      boxHeight = tHeight - 1;
    }
  }
  innerBox inner = dibujarCajaTitulo(posx, posy, boxWidth, boxHeight, titulo);

  int pagina = 0;
  int posxPagina = posx + (boxWidth / 2) - 5;
  int posyPagina = inner.posy + inner.height + 1;
  int cantPaginas = cantObjetos / inner.height;
  if (cantObjetos % inner.height == 0) {
    --cantPaginas;
  }
  int mostrados = 0;
  int seleccionado = 0;
  int cursor = inner.posy;

  while (true) {
    mostrados = listarSeleccion(pagina, inner.height, inner.posx, inner.posy, nombreObjetos, cantObjetos, seleccionado);
    rlutil::locate(posxPagina, posyPagina);
    std::cout << "Pagina " << std::left << std::setfill(' ') << std::setw(4) << pagina + 1;

    int pos_max_mostrados = inner.posy + mostrados - 1;
    

    char key = rlutil::getkey();
    switch (key) {
      case rlutil::KEY_DOWN: {
        ++cursor;
        if (cursor > pos_max_mostrados) {
          cursor = pos_max_mostrados;
          if (cantPaginas > 0 && pagina < cantPaginas) {
            ++pagina;
            clearInnerBox(inner);
            cursor = inner.posy;
          }
        }
        seleccionado = (pagina * inner.height) + cursor - inner.posy;
      } break;

      case rlutil::KEY_UP: {
        --cursor;
        if (cursor < inner.posy) {
          cursor = inner.posy;
          if (cantPaginas > 0 && pagina > 0) {
            --pagina;
            clearInnerBox(inner);
            cursor = pos_max_mostrados;
          }
        }
        seleccionado = (pagina * inner.height) + cursor - inner.posy;
      } break;

      case rlutil::KEY_LEFT: {
        --pagina;
        if (pagina < 0) {
          pagina = 0;
        }
        seleccionado = (pagina * inner.height) + cursor - inner.posy;
        clearInnerBox(inner);
      } break;

      case rlutil::KEY_RIGHT: {
        ++pagina;
        if (pagina > cantPaginas) {
          pagina = cantPaginas;
        }
        seleccionado = (pagina * inner.height) + cursor - inner.posy;
        if(seleccionado > cantObjetos) {
          seleccionado = cantObjetos - 1;
        }
        clearInnerBox(inner);
      } break;

      case rlutil::KEY_ENTER: {
        clearBox(posx, posy, boxWidth, boxHeight);
        rlutil::locate(posxPagina, posyPagina);
        std::cout << std::setfill(' ') << std::setw(10) << ' ';
        return seleccionado;
      } break;

      default: {
        int opcion = key - 48;
        if (opcion >= 0 && opcion <= pos_max_mostrados) {
          seleccionado = (pagina * inner.height) + opcion;
        }
      } break;
    }
  }
}

void mostrarDato(const char *texto, const char *dato) {
  std::cout << std::right << std::setw(26) << texto << dato << '\n';
}

void mostrarDato(const char *texto, float dato) {
  std::cout << std::right << std::setw(26) << texto << dato << '\n';
}

void mostrarDato(const char *texto, int dato) {
  std::cout << std::right << std::setw(26) << texto << dato << '\n';
}

void mostrarAviso(const char *texto) {
  std::cout << std::right << std::setw(26) << texto;
}

void posicion(int x, int y) {
  rlutil::locate(x, y);
}

void mostrarCursor() {
  rlutil::showcursor();
}

void ocultarCursor() {
  rlutil::hidecursor();
}

void mostrarError(const char *error) { 
    int anchoConsola = rlutil::tcols();
    int centrox = (anchoConsola / 2) - (strlen(error) / 2);
    int posy = rlutil::trows() - 1;

    ponerColores(4, 0);
    rlutil::locate(1, posy);
    std::cout << std::setfill(' ') << std::setw(anchoConsola) << ' ';
    
    rlutil::locate(centrox, posy);
    std::cout << error;

    ponerColores(0, rlutil::WHITE);
}

void borrarLinea(int y) {
  int anchoConsola = rlutil::tcols();
  rlutil::locate(1, y);
  std::cout << std::setfill(' ') << std::setw(anchoConsola) << ' ';
}

void borrarLineas(int y, int cantLineas) {
  int hasta = y + cantLineas;
  int anchoConsola = rlutil::tcols();
  for (int i = y; i <= hasta; ++i) {
    rlutil::locate(1, i);
    std::cout << std::setfill(' ') << std::setw(anchoConsola) << ' ';
  }
}
