#ifndef CARGARCADENA_H_INCLUDED
#define CARGARCADENA_H_INCLUDED

void ignoreLine();

void cargarCadena(char *cadena, int tam);
void cargarCadena(const char *pregunta, char *cadena, int tam, int posx, int posy);

int cargarInt(const char *pregunta);
int cargarInt(const char *pregunta, int posx, int posy);

float cargarFloat(const char *pregunta);
float cargarFloat(const char *pregunta, int posx, int posy);

#endif
