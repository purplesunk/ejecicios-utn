#include <iostream>
#include <cstring>
#include <limits>


int main() {
    const int CARGAR = 100;
    char matriz[5][10];

    for (int i = 0; i < 5; i++) {
        std::cout << "Cargue la cadena " << i + 1 << ": \n";
        std::cin.getline(matriz[i], CARGAR);
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << "Cadenas cargadas: \n";
    for (int i = 0; i < 5; i++) {
        std::cout << matriz[i] << "\n";
    }
}

/* 
Si se cargar más de diez carácteres el caracter señalador de final de cadena '\0'
se borrará al ingresar una nueva cadena, entonces cuando mostremos las cadenas se
 en la primer cadena se mostraran toda la matriz, en la segunda se mostrará desde 
 la segunda hasta el final y así. Si se cargan cadenas muy grandes puede haber un
overflow. 
*/