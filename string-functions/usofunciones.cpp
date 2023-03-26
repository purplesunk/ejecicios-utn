#include <iostream>
#include <limits>

void clear_input_buffer() {
    std::cin.clear(); // clear the error state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore remaining characters
}
void cargarCadena(char *pal, int tam);

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

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Cargue la primer cadena: ";
                cargarCadena(s, 80);
                std::cout << "\n";
            break;
            case 2:
                std::cout << "Cargue la segunda cadena: ";
                cargarCadena(t, 80);
                std::cout << "\n";
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 0:
                return 0;
            break;
            default:
                std::cout << "No existe esa opcion.\n";
            break;
        }
    }

    std::cout << "La string \"" << s << "\" tiene " << strlen(s) << " caracteres.\n";
    std::cout << s << "\n";
}

void cargarCadena(char *pal, int tam){
    int i;
    clear_input_buffer();
    for(i=0;i<tam;i++){
        pal[i]= std::cin.get();
	    if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    clear_input_buffer();
}