#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <cstring>

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
    std::cout << "\nPresione Enter para continuar...";
    std::cin.get();
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int cargarNumero() {
    int num;
    std::cin >> num;
    while (std::cin.fail()) {
        std::cin.clear();
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        std::cout << "Use un entero.\n";
        std::cout << "Ingrese otro numero: ";
        std::cin >> num;
    }
    return num;
}

void cargarCadena(char *pal, int tam) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    std::cin.getline(pal, tam);
    if (std::cin.fail()) {
        std::cin.clear();
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

void cargarMaterias(char materias[][30], const int cantidadMaterias) {
    std::cout << "INGRESO DE MATERIAS\n--------------------\n";
    for (int i = 0; i < cantidadMaterias; i++) {
        std::cout << "Ingrese numero de materia: ";
        int numMateria = cargarNumero();
        while (numMateria > cantidadMaterias || numMateria < 1) {
            std::cout << "Numero de materia invalido.\n";
            std::cout << "Ingrese numero de materia: ";
            numMateria = cargarNumero();
        }
        while (strnlen(materias[numMateria - 1], 30) > 0) {
            std::cout << "Materia ya ingresada.\n";
            std::cout << "Ingrese otro numero: ";
            numMateria = cargarNumero();
        }
        std::cout << "Ingrese nombre de materia: ";
        cargarCadena(materias[numMateria - 1], 30);
    }
}

void cargarAsistencias(int asistencias[][31], const int cantidadMaterias) {
    int numMateria, dia;
    std::cout << "INGRESO DE ASISTENCIAS\n--------------------\n";
    std::cout << "Ingrese numero de legajo: ";
    int numLegajo = cargarNumero();
    while (!(numLegajo < 25000 || numLegajo > 12000)) {
        std::cout << "Ingrese numero de legajo valido: ";
        numLegajo = cargarNumero();
    }
    while (numLegajo != 0) {
        std::cout << "Ingrese numero de materia: ";
        numMateria = cargarNumero();
        while (numMateria > cantidadMaterias || numMateria < 1) {
            std::cout << "Igrese numero de materia valido: ";
            numMateria = cargarNumero();
        }
        std::cout << "Ingrese dia: ";
        dia = cargarNumero();
        while (dia > 31 || dia < 1) {
            std::cout << "Igrese un dia valido: ";
            dia = cargarNumero();
        }

        // The only important thing xd:
        asistencias[numMateria - 1][dia - 1] += 1;

        std::cout << "Ingrese numero de legajo: ";
        numLegajo = cargarNumero();
        while (!(numLegajo < 25000 || numLegajo > 12000) && numLegajo != 0) {
            std::cout << "Ingrese numero de legajo valido: ";
            numLegajo = cargarNumero();
        } 
    }
}


void materiasSinAsistencia(int asistencias[][31], char materias[][30], const int cantidadMaterias) {
    std::cout << "Materias sin asistencias: \n ---------------------\n";
    for (int i = 0; i < cantidadMaterias; i++) {
        int asistencia = 0;
        for (int j = 0; j < 31; j++) {
            asistencia += asistencias[i][j];
        }
        if (asistencia == 0) {
            std::cout << materias[i] << "\n";
        }
    }
    pause();
}

void masConcurrida(int asistencias[][31], char materias[][30], const int cantidadMaterias) {
    std::cout << "Materia más concurrida: \n ----------------------\n"; 
    int dia = 0;
    int materia = 0;
    int maximo = asistencias[0][0];
    for (int i = 0; i < cantidadMaterias; i++) {
        for (int j = 0; j < 31; j++) {
            if (asistencias[i][j] > maximo) {
                maximo = asistencias[i][j];
                materia = i;
                dia = j;
            }
        }
    }
    if (maximo != 0) {
        std::cout << materias[materia] << " el dia " << dia + 1 << " con " << maximo << " asistencias.\n";
    } else {
        std::cout << "No se han cargado datos...\n";
    }
    pause();
}

void cantidadAsistencias(int asistencias[][31], char materias[][30], const int cantidadMaterias) {
    std::cout << "Cantidad de asistencias por dia: \n --------------------------\n"; 
    for (int j = -1; j < 31; j++) {
        for (int i = 0; i < cantidadMaterias; i++) {
            if (j == -1) {
                std::cout << materias[i];
                for (int tamaño = strlen(materias[i]); tamaño < 32; tamaño++) {
                    std::cout << char(32);
                }
            } else {
                std::cout << "DIA " << j << ": " << asistencias[i][j] << "\t\t\t";
            }
        }
        std::cout << "\n";
    }
    pause();
}

#endif // FUNCIONES_H_INCLUDED