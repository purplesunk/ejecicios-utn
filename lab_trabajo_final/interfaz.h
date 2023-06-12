#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

struct innerBox {
  int posx;
  int posy;
  int width;
  int height;
};

void dibujarCaja(int posx, int posy, int width, int height);
innerBox dibujarCajaTitulo(int posx, int posy, int width, int height, const char *titulo);
void clearInnerBox(innerBox caja);
void clearBox(int posx, int poxy, int width, int height);

void ponerColores(int fondo, int letra);
void mostrarOpcion(const char* texto, int posx, int posy, bool seleccionado);

void centrarTexto(const char *texto, int posy);

void pause();

#endif
