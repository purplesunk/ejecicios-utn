#include <iostream>
#include <limits>

void cargarCadena(char *pal, int tam);
char* elegirCadena(char *s, char *t);
int elegirOpcion();
void clearConsole();

#include "stringre.h"

int main(void) 
{
    char s[161] = "hola mundo";
    char t[81] = " como estas?"; 

    while (true) {
        std::cout << "1. Cargar primer cadena\n";
        std::cout << "2. Cargar segunda cadena\n";
        std::cout << "3. Mostrar cadenas\n";
        std::cout << "4. Mostrar tamaño de cadena\n";
        std::cout << "5. Copiar cadenas\n";
        std::cout << "6. Comparar cadenas\n";
        std::cout << "7. Concatenar cadenas\n";
        std::cout << "0. Salir\n";

        switch (elegirOpcion()) {
            case 1:
                clearConsole();
                std::cout << "Cargue la primer cadena: ";
                cargarCadena(s, 80);
                std::cout << "\n";
            break;
            case 2:
                clearConsole();
                std::cout << "Cargue la segunda cadena: ";
                cargarCadena(t, 80);
                std::cout << "\n";
            break;
            case 3:
                clearConsole();
                std::cout << "Primer cadena: " << s << "\n";
                std::cout << "Segunda cadena: " << t << "\n";
            break;
            case 4: {
                clearConsole();
                char *cadena = elegirCadena(s, t);
                std::cout << "La cadena \"" << cadena << "\" tiene " << strlen(cadena) << " caracteres.\n";
            }
            break;
            case 5: {
                clearConsole();
                std::cout << "Cadena que elija va a ser la que se copie a la otra.\n"; 
                char *cadena = elegirCadena(s, t);
                if (strcmp(s, cadena) == 0) {
                    strcpy(t, cadena);
                } 
                else {
                    strcpy(s, cadena);
                }
                std::cout << "Cadenas copiadas\n";
            }
            break;
            case 6: {
                clearConsole();
                std::cout << "Cadena que elija va a ser la que se compare a la otra.\n"; 
                char *cadena = elegirCadena(s, t);
                if (strcmp(s, cadena) == 0) {
                    std::cout << "Resultado de strcmp: " << strcmp(s, t) << "\n";
                }
                else {
                    std::cout << "Resultado de strcmp: " << strcmp(t, s) << "\n";
                }
            }
            break;
            case 7:
                clearConsole();
                if (strlen(s) + strlen(t) < 160) {
                    strcat(s,t);
                    std::cout << "Cadena concatenada: " << s << "\n";
                }
                else {
                    std::cout << "Limite de caracteres excedido.";
                }
            break;
            case 0:
                return 0;
            break;
            default:
                clearConsole();
                std::cout << "No existe esa opcion.\n";
            break;
        }
    }
}

void clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}

int elegirOpcion() {
    int num;
    std::cin >> num;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Número invalido. Use un entero: ";
        std::cin >> num;
    }
    return num;
}

char* elegirCadena(char *s, char *t) {
    while (true) {
        std::cout << "Elija cadena: ";
        switch(elegirOpcion()) {
            case 1:
                return s; 
            break;
            case 2:
                return t;
            break;
            default:
                std::cout << "No existe esa cadena.\n";
            break;
        }
    }
}


void cargarCadena(char *pal, int tam){
    int i;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore remaining characters
    for(i=0;i<tam;i++){
        pal[i]= std::cin.get();
	    if(pal[i]=='\n') break;
    }
    pal[i]='\0';
}