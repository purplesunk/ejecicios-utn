#include <iostream>

using namespace std;

#include "prototipos.h"

int main()
{
    int vec[10];
    while(true)
    {
        cout << "-----------------------\n";
        cout << "1. Cargar Vector \n";
        cout << "2. Mostrar Vector \n";
        cout << "3. Máximo \n";
        cout << "4. Mínimo \n";
        cout << "0. Salir \n";
        cout << "-----------------------\n";

        int opcion;
        cin >> opcion;

        system("cls");

        switch (opcion)
        {
            case 1:
                cargarVector(vec, 10);
            break;
            case 2:
                mostrarVector(vec, 10);
            break;
            case 3:
                mostrarMax(vec, 10);
            break;
            case 4:
                mostrarMin(vec, 10);
            break;
            case 0:
                return 0;
            break;
            default:
                std::cout << "OPCIÓN NO VALIDA\n";
                system("pause");
                system("cls");
            break;
        }
    }
}
