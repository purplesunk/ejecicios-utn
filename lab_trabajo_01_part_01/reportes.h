#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void listarBateristas() {
    ArchivoMusico musicos("musicos.dat");

    int cantMusicos = musicos.contarRegistros();
    if (cantMusicos == -1) {
        std::cout << "No se pudo leer el archivo.\n";
        return;
    } else if (cantMusicos == 0) {
        std::cout << "No hay músicos registrados en el archivo.\n";
        return;
    }

    int cantBateristas = 0;
    Musico musico;
    for (int i = 0; i < cantMusicos; ++i) {
        musico = musicos.leerMusico(i);

        if (musico.getInstrumentro() == 5) {
            ++cantBateristas;
            std::cout << " Baterista " << cantBateristas << ": \n";
            std::cout << "----------------------\n";
            std::cout << "DNI: " << musico.getDni() << '\n';
            std::cout << "Nombre: " << musico.getNombre() << '\n';
            std::cout << "Apellido: " << musico.getApellido() << '\n';
            std::cout << "Tipo de música: " << musico.getTipoMusica() << '\n';
            std::cout << '\n';
        }
    }
}

void instrumentoMenosMusicos() {
    ArchivoMusico musicos("musicos.dat");

    int cantMusicos = musicos.contarRegistros();
    if (cantMusicos == -1) {
        std::cout << "No se pudo leer el archivo.\n";
        return;
    } else if (cantMusicos == 0) {
        std::cout << "No hay músicos registrados en el archivo.\n";
        return;
    }

    int cantMusicosXInstrumento[15] = {};

    Musico musico;
    for (int i = 0; i < cantMusicos; ++i) {
        musico = musicos.leerMusico(i);

        ++cantMusicosXInstrumento[musico.getInstrumentro() - 1];
    }

    /*
        int instrumentoMenosMusicos = -1;
        for (int i = 0; i < 15; ++i) {
            if (instrumentoMenosMusicos == -1 && cantMusicosXInstrumento[i] != 0) {
                instrumentoMenosMusicos = i;

            } else if (cantMusicosXInstrumento[i] != 0 &&
                       cantMusicosXInstrumento[i] < cantMusicosXInstrumento[instrumentoMenosMusicos]) {
                instrumentoMenosMusicos = i;
            }
        }
    */

    int instrumentoMenosMusicos = 0;
    for (int i = 0; i < 15; ++i) {
        if (cantMusicosXInstrumento[i] < cantMusicosXInstrumento[instrumentoMenosMusicos]) {
            instrumentoMenosMusicos = i;
        }
    }

    std::cout << "El intrumento con menos músicos es: " << instrumentoMenosMusicos + 1 << '\n';
}

// Generar un archivo de nombre instrumentos.dat con los músicos que no tocan guitarra (instrumento principal 1).
// Cada registro debe tener el siguiente formato:
// DNI, nombre, apellido y tipo de música
struct NoGuitarristas {
   private:
    int dni;
    char nombre[30];
    char apellido[30];
    int tipoMusica;

   public:
    void setDni(int i) {
        dni = i;
    }
    void setTipoMusica(int i) {
        tipoMusica = i;
    }
    void setNombre(const char *n) {
        strcpy(nombre, n);
    }
    void setApellido(const char *n) {
        strcpy(apellido, n);
    }

    void Mostrar() {
        std::cout << dni << " " << nombre << " " << apellido << " " << tipoMusica << '\n';
    }
};

void generarNoGuitarristas() {
    ArchivoMusico musicos("musicos.dat");

    int cantMusicos = musicos.contarRegistros();
    if (cantMusicos == -1) {
        std::cout << "No se pudo leer el archivo.\n";
        return;
    } else if (cantMusicos == 0) {
        std::cout << "No hay músicos registrados en el archivo.\n";
        return;
    }

    Musico musico;
    NoGuitarristas musicoNoGuitarra;
    for (int i = 0; i < cantMusicos; ++i) {
        musico = musicos.leerMusico(i);

        if (musico.getInstrumentro() != 1) {
            FILE *nuevoArchivo = fopen("instrumentos.dat", "ab");
            if (nuevoArchivo == NULL) {
                std::cout << "Error al abrir el archivo. \n";
                return;
            }

            musicoNoGuitarra.setDni(musico.getDni());
            musicoNoGuitarra.setTipoMusica(musico.getTipoMusica());
            musicoNoGuitarra.setNombre(musico.getNombre());
            musicoNoGuitarra.setApellido(musico.getApellido());

            fwrite(&musicoNoGuitarra, sizeof(musicoNoGuitarra), 1, nuevoArchivo);

            fclose(nuevoArchivo);
        }
    }

    std::cout << "Archivo generado.\n";
}

#endif