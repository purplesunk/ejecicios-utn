#include <iostream>

#include "utils.h"
#include "fecha.h"

int main()
{
    Fecha diaDeAyer(1, 10, 2010);

    diaDeAyer.mostrar();

    diaDeAyer.cargar();

    diaDeAyer.mostrar();

    return 0;
}
