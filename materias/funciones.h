#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void clearConsoleW() {
    std::system("cls");
}
void clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}
#ifdef _WIN32
    #define clearConsole clearConsoleW
#endif



void pause() {
    std::cout << "Presione Enter para continuar...";
    std::cin.get();
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void cargarCadena(char *pal, int tam)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    std::cin.getline(pal, tam);
    if (std::cin.fail()) {
        std::cin.clear();
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
}


void cargarMaterias(char nombreMateria[][40], const int cantidadMaterias)
{
    for (int i = 0; i < cantidadMaterias; i++)
    {
        int nro, cantAlum, cantProf;
        std::cout << "Ingrese n�mero de materia: ";
        std::cin >> nro;
        std::cout << "Ingrese nombre de materia: ";
        cargarCadena(nombreMateria[nro - 1], 40);
        std::cout << "Ingrese n�mero de Alumnos: ";
        std::cin >> cantAlum;
        std::cout << "Ingrese n�mero de Profesores: ";
        std::cin >> cantProf;
    }
    clearConsole();
}

void ingresosAlumnos(int *horasMateria, int accesoMarzo[][31])
{
    int legajo, dia, mes, nroMateria, horas;
    std::cout << "Ingrese n�mero de legajo: ";
    std::cin >> legajo;
    while (legajo != 0)
    {
        std::cout << "Ingrese n�mero de  d�a: ";
        std::cin >> dia;
        std::cout << "Ingrese n�mero de mes: ";
        std::cin >> mes;
        std::cout << "Ingrese n�mero de materia: ";
        std::cin >> nroMateria;
        std::cout << "Ingrese cantidad de horas: ";
        std::cin >> horas;

        horasMateria[nroMateria - 1] += horas;

        if (mes == 3)
        {
            accesoMarzo[nroMateria - 1][dia - 1] += 1;
        }

        std::cout << "Ingrese n�mero de legajo: ";
        std::cin >> legajo;
    }
    clearConsole();
}

void MateriasNoAcceso(int *horasMateria, char nombreMateria[][40], const int cantidadMaterias)
{
    std::cout << "Materias que no tuvieron acceso: \n";
    for (int i = 0; i < cantidadMaterias; i++)
    {
        if (horasMateria[i] == 0)
        {
            std::cout << nombreMateria[i] << "\n";
        }
    }
    pause();
    clearConsole();
}

void MayorAcceso(int *horasMateria, char nombreMateria[][40], const int cantidadMaterias)
{
    std::cout << "Materia con m�s horas de acceso: \n";
    int mayor = 0;
    for (int i = 1; i < cantidadMaterias; i++)
    {
        if (horasMateria[mayor] < horasMateria[i])
        {
            mayor = i;
        }
    }
    std::cout << nombreMateria[mayor] << "\n";
    pause();
    clearConsole();
}

void CantidadAccesosMarzo(int accesoMarzo[][31], char nombreMateria[][40], const int cantidadMaterias)
{
    std::cout << "Cantidad de accesos por d�a en Marzo: \n";
    for (int i = 0; i < cantidadMaterias; i++)
    {
        std::cout << nombreMateria[i] << ": \n";
        for (int j = 0; j < 31; j++)
        {
            std::cout << "Dia " << j + 1 << ": " << accesoMarzo[i][j] << "\n";
        }
    }
    pause();
    clearConsole();
}

#endif // FUNCIONES_H_INCLUDED