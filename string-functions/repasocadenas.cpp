#include <iostream>
#include <cstring>

//Primer punto hecho en string-functions/stringre.h

void CambiarCaracterEnCadena(char *cadena, const char dest, const char src);
void InsertarCaraterEnPosicion(char *cadena, int pos, const char caracter);
void ListarCadena(const char *cadena);

int main() {
    char s[] = "La mar estaba serena";

    CambiarCaracterEnCadena(s, 'a', 'i');

    InsertarCaraterEnPosicion(s, 2, 'p');

    ListarCadena(s);
}

void CambiarCaracterEnCadena(char *cadena, const char dest, const char src) {
    for (int i = 0, n = strlen(cadena); i < n; i++) {
        if (cadena[i] == dest) {
            cadena[i] = src;
        }
    }
}

void InsertarCaraterEnPosicion(char *cadena, int pos, const char caracter) {
    int n = strlen(cadena);
    if (pos < n && pos >= 0) {
        cadena[pos] = caracter;
    }
}

void ListarCadena(const char *cadena) {
    for (int i = 0, n = strlen(cadena); i < n; i++) {
        std::cout << cadena[i] << "\n";
    }
}