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
    << std::setw(innerWidth) << corner_tr;

  ++posy;
  for (int i = 0; i < innerHeight; ++i) {
    rlutil::locate(posx, posy + i);
    std::cout << vertical;
    rlutil::locate(posx + innerWidth, posy + i);
    std::cout << vertical;
  }

  rlutil::locate(posx, posy + innerHeight);
  std::cout << corner_bl << std::setfill(horizontal)
    << std::setw(innerWidth) << corner_br;
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
    << std::setw(innerWidth) << pipe_r;

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
    std::cout << std::setw(width) << ' ';
  }
}

void clearBox(int posx, int posy, int width, int height) {
  for (int i = 0; i < height; ++i) {
   rlutil::locate(posx, posy + i);
    std::cout << std::setw(width) << ' ';
  } 
}

void ponerColores(int fondo, int letra) {
    rlutil::setBackgroundColor(fondo);
    rlutil::setColor(letra);
}

void mostrarOpcion(const char* texto, int posx, int posy, bool seleccionado) {
    if (seleccionado) {
        ponerColores(rlutil::MAGENTA, rlutil::BLACK);
        rlutil::locate(posx-2,posy);
        std::cout << " >" << texto << "< ";
        ponerColores(rlutil::BLACK, rlutil::WHITE);
    } else {
        ponerColores(rlutil::BLACK, rlutil::WHITE);
        rlutil::locate(posx-2,posy);
        std::cout << "  " << texto << "  ";
    }
    rlutil::setColor(rlutil::BLACK);
}

void pause() {
  // Make an aviso o algo xd
  rlutil::anykey();
}

// int main() {
//   rlutil::cls();
//   dibujarCaja(20,1,30,10);
//   rlutil::anykey();
//   rlutil::cls();
// }
