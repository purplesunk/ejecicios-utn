#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

struct innerBox {
  int posx;
  int posy;
  int width;
  int height;
};

// innerBox dibujarCajaTitulo(int posx, int posy, int width, int height, const char *titulo);
// void dibujarCaja(int posx, int posy, int width, int height);
// void clearBox(int posx, int poxy, int width, int height);
// void clearInnerBox(innerBox caja);

void ponerColores(int fondo, int letra);
void mostrarOpcion(const char* texto, int posx, int posy, bool seleccionado, int fondo = 5, int letra = 0, int minWidth = 30);
// void mostrarSeleccion(int num, const char* texto, int posx, int posy, bool seleccionado, int fondo, int letra, int minWidth);
void mostrarDato(const char *texto, const char *dato);
void mostrarDato(const char *texto, float dato);
void mostrarDato(const char *texto, int dato);
void mostrarAviso(const char *texto);

void pause();
void posicion(int x, int y);
void mostrarCursor();
void ocultarCursor();
void mostrarError(const char *error);
void borrarLinea(int y);
void borrarLineas(int y, int cantLineas);

int seleccionarObjeto(int posx, int posy, int boxWidth, int boxHeight, char **nombreobjetos, int cantObjetos, const char *titulo);

#endif
