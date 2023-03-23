#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

const int CANTIDAD_MATERIAS = 2;

void cargarCadena(char *pal,int tam)
{
    int i;
    fflush(stdin);
    for (i = 0; i < tam; i++)
    {
        pal[i] = std::cin.get();
        if (pal[i] == '\n') break;
    }
    pal[i] = '\0';
    fflush(stdin);
}


void cargarMaterias(char nombreMateria[][40])
{
    for (int i = 0; i < CANTIDAD_MATERIAS; i++)
    {
        int nro, cantAlum, cantProf;
        std::cout << "Ingrese número de materia: ";
        std::cin >> nro;
        std::cout << "Ingrese nombre de materia: ";
        cargarCadena(nombreMateria[nro - 1], 40);
        std::cout << "Ingrese número de Alumnos: ";
        std::cin >> cantAlum;
        std::cout << "Ingrese número de Profesores: ";
        std::cin >> cantProf;
    }
    system("cls");
}

void ingresosAlumnos(int *horasMateria, int accesoMarzo[][31])
{
    int legajo, dia, mes, nroMateria, horas;
    std::cout << "Ingrese número de legajo: ";
    std::cin >> legajo;
    while (legajo != 0)
    {
        std::cout << "Ingrese número de  día: ";
        std::cin >> dia;
        std::cout << "Ingrese número de mes: ";
        std::cin >> mes;
        std::cout << "Ingrese número de materia: ";
        std::cin >> nroMateria;
        std::cout << "Ingrese cantidad de horas: ";
        std::cin >> horas;

        horasMateria[nroMateria - 1] += horas;

        if (mes == 3)
        {
            accesoMarzo[nroMateria - 1][dia - 1] += 1;
        }

        std::cout << "Ingrese número de legajo: ";
        std::cin >> legajo;
    }
    system("cls");
}

void MateriasNoAcceso(int *horasMateria, char nombreMateria[][40])
{
    std::cout << "Materias que no tuvieron acceso: \n";
    for (int i = 0; i < CANTIDAD_MATERIAS; i++)
    {
        if (horasMateria[i] == 0)
        {
            std::cout << nombreMateria[i] << "\n";
        }
    }
    system("pause");
    system("cls");
}

void MayorAcceso(int *horasMateria, char nombreMateria[][40])
{
    std::cout << "Materia con más horas de acceso: \n";
    int mayor = 0;
    for (int i = 1; i < CANTIDAD_MATERIAS; i++)
    {
        if (horasMateria[mayor] < horasMateria[i])
        {
            mayor = i;
        }
    }
    std::cout << nombreMateria[mayor] << "\n";
    system("pause");
    system("cls");
}

void CantidadAccesosMarzo(int accesoMarzo[][31], char nombreMateria[][40])
{
    std::cout << "Cantidad de accesos por día en Marzo: \n";
    for (int i = 0; i < CANTIDAD_MATERIAS; i++)
    {
        std::cout << nombreMateria[i] << ": \n";
        for (int j = 0; j < 31; j++)
        {
            std::cout << "Dia " << j + 1 << ": " << accesoMarzo[i][j] << "\n";
        }
    }
    system("pause");
    system("cls");
}

#endif // FUNCIONES_H_INCLUDED
