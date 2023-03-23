#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

void cargarVector(int vec[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        std::cout << "Cargar número: ";
        std::cin >> vec[i];
    }
    system("cls");
}

void mostrarVector(int vec[], int tam)
{
    std::cout << "Vector: " << "\n";
    for (int i = 0; i < tam; i++)
    {
        std::cout << vec[i] << "\n";
    }
    system("pause");
    system("cls");
}

void mostrarMax(int *vec, int tam)
{
    std::cout << "Máximo: ";
    int max = vec[0];
    for (int i = 1; i < tam; i++)
    {
        if (vec[max] < vec[i])
        {
            max = i;
        }
    }
    std::cout << vec[max] << "\n";
    system("pause");
    system("cls");
}

void mostrarMin(int *vec, int tam)
{
    std::cout << "Mínimo: ";
    int min = 0;
    for (int i = 1; i < tam; i++)
    {
        if (vec[min] > vec[i])
        {
            min = i;
        }
    }
    std::cout << vec[min] << "\n";
    system("pause");
    system("cls");
}

#endif // PROTOTIPOS_H_INCLUDED
