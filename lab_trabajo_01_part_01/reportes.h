#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void listarMusicosAlumnos() {
    ArchivoMusico archivo("musicos.dat");

    int cantMusicos = archivo.contarRegistros();

    if (cantMusicos == -1 || cantMusicos == 0) {
        std::cout << "Error leyendo el archivo.\n";
        return;
    }

    Musico musico;
    for (int i = 0; i < cantMusicos; ++i) {
        musico = archivo.leerMusico(i);
        if (musico.getClaustro() == 2) {
            musico.Mostrar();
            std::cout << '\n';
        }
    }
}

void tipoMusicaXorigen() {
    ArchivoGeneroMusical archivo("generos.dat");

    int cantGeneros = archivo.contarRegistros();

    if (cantGeneros == -1 || cantGeneros == 0) {
        std::cout << "Error al leer el archivo.\n";
        return;
    }

    int cantGenerosXpais[100] = {};

    GeneroMusical genero;
    for (int i = 0; i < cantGeneros; ++i) {
        genero = archivo.leerGeneroMusical(i);

        ++cantGenerosXpais[genero.getPaisOrigen() - 1];
    }

    std::cout << "Cantidad de Generos por pais de Origen: \n";
    for (int i = 0; i < 100; ++i) {
        std::cout << "Pais de origen ";
        std::cout << i + 1 << ": ";
        std::cout << cantGenerosXpais[i];
        std::cout << '\n';
    }
}

class Musico2023 {
   private:
    int dni;
    char nombre[30];
    int claustro;

   public:
    void Mostrar() {
        std::cout << dni << " " << claustro << " " << nombre << '\n';
    }

    void setDni(int d) { dni = d; }
    void setClaustro(int c) { claustro = c; }
    void setNombre(const char *n) { strncpy(nombre, n, 30); }
};

void generarMusicos2023() {
    ArchivoMusico musicos("musicos.dat");

    int cantMusicos = musicos.contarRegistros();

    Musico musico;
    Musico2023 musico2023;
    for (int i = 0; i < cantMusicos; ++i) {
        musico = musicos.leerMusico(i);

        musico2023.setDni(musico.getDni());
        musico2023.setNombre(musico.getNombre());
        musico2023.setClaustro(musico.getClaustro());

        FILE *archivo = fopen("musicos2023.dat", "ab");
        if (archivo == NULL) {
            return;
        }

        fwrite(&musico2023, sizeof(Musico2023), 1, archivo);

        fclose(archivo);
    }

    FILE *archivo = fopen("musicos2023.dat", "rb");
    if (archivo == NULL) {
        return;
    }

    while (fread(&musico2023, sizeof(Musico2023), 1, archivo)) {
        musico2023.Mostrar();
    }

    fclose(archivo);
}

void reportesMenu() {
    while (true) {
        std::cout << "REPORTES\n";
        std::cout << "---------------------------------------\n";
        std::cout << "1)\n";
        std::cout << "2)\n";
        std::cout << "3)\n";
        std::cout << "---------------------------------------\n";
        std::cout << "0) VOLVER AL MENÚ PRINCIPAL\n";

        int opcion = cargarInt("SELECCIONAR OPCION: ");

        system("cls");

        switch (opcion) {
            case 1:
                listarMusicosAlumnos();
                break;
            case 2:
                tipoMusicaXorigen();
                break;
            case 3:
                generarMusicos2023();
                break;
            case 0:
                return;
                break;
        }
        system("pause");
        system("cls");
    }
}

#endif