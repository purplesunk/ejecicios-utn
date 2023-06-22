#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

// A partir de un nombre de país que se ingresa por teclado, generar un archivo con todos los géneros que tengan ese país como país de origen. Listar el archivo nuevo.
int getPaisId(const char *nombrePais) {
    ArchivoPais aPaises("paises.dat");
    int cantPaises = aPaises.contarRegistros();
    int idPais = -1;
    Pais pais;
    for (int i = 0; i < cantPaises; ++i) {
        pais = aPaises.leerRegistro(i);
        if (pais.getEstado() && strcasecmp(nombrePais, pais.getNombre()) == 0) {
            idPais = pais.getId();
        }
    }
    return idPais;
}

void punto1() {
    char nombrePais[30];
    mostrarAviso("INGRESE NOMBRE DE PAIS: ");
    cargarCadena(nombrePais, 30);

    int idPais = getPaisId(nombrePais);
    if (idPais == -1) {
        mostrarAviso("NO HAY PAIS CON ESE NOMBRE.\n");
        return;
    }

    char nombreArchivo[35];
    strncpy(nombreArchivo, nombrePais, 29);
    strcat(nombreArchivo, ".dat");

    ArchivoGeneroMusical aGeneros("generos.dat");
    int cantGeneros = aGeneros.contarRegistros();
    ArchivoGeneroMusical generosPais(nombreArchivo);

    GeneroMusical genero;
    for (int i = 0; i < cantGeneros; ++i) {
        genero = aGeneros.leerRegistro(i);   
        if (genero.getPaisOrigen() == idPais && genero.getEstado()) {
            generosPais.escribirRegistro(genero);
        }
    }

    rlutil::cls();
    std::cout << "  Archivo con generos de " << nombrePais << ":\n";
    generosPais.mostrarRegistros();
}

// Informar el/los instrumento/s principal/es que no tengan músicos del claustro de no docentes
bool checkearNoDocente(int idInstrumento, Musico *vMusicos, int cantMusicos) {
    for (int i = 0; i < cantMusicos; ++i) {
        if (vMusicos[i].getEstado() && vMusicos[i].getInstrumento() == idInstrumento) {
            if(vMusicos[i].getClaustro() == 3) {
                return true;
            }
        }
    }
    return false;
}

void punto2() {
    ArchivoMusico aMusicos("musicos.dat");
    int cantMusicos = aMusicos.contarRegistros();
    Musico *vMusicos = new Musico[cantMusicos];
    if (vMusicos == NULL) {
        mostrarAviso("No se pudo asginar memoria.");
        return;
    }
    for (int i = 0; i < cantMusicos; ++i) {
        vMusicos[i] = aMusicos.leerRegistro(i);
    } 

    mostrarAviso("Instrumentos que no tienen musicos no docentes:\n");
    ArchivoInstrumento aInstrumentos("instrumentos.dat");
    int cantInstrumentos = aInstrumentos.contarRegistros();
    Instrumento instrumento;
    for (int i = 0; i < cantInstrumentos; ++i) {
        instrumento = aInstrumentos.leerRegistro(i);
        if (!checkearNoDocente(instrumento.getId(), vMusicos, cantMusicos)) {
            instrumento.Mostrar();
            std::cout << '\n';
        }
    }

    delete[] vMusicos;
}

// Dado un número de instrumento que se ingresa por teclado hacer un listado de los músicos que tocan ese instrumento con asignación dinámica de memoria.
void mostrarVectorMusicos(Musico *vMusicos, int cantMusicos) {
    rlutil::cls();
    mostrarAviso("Musicos con ese instrumento:\n");
    for (int i = 0; i < cantMusicos; ++i) {
        vMusicos[i].Mostrar();
        std::cout << '\n';
    }
}

void punto3() {
    ArchivoInstrumento instrumentos("instrumentos.dat");
    int idInstrumento = cargarInt("INGRESE ID INSTRUMENTO: ");
    if (instrumentos.buscarRegistro(idInstrumento) < 0) {
        mostrarAviso("Instrumento invalido.\n");
        return;
    }

    ArchivoMusico aMusicos("musicos.dat");
    int cantMusicos = aMusicos.contarRegistros();
    Musico *vMusicos = new Musico[cantMusicos];
    if (vMusicos == NULL) {
        mostrarAviso("No se pudo asginar memoria.");
        return;
    }

    int cantMusicosInstrumento = 0;
    for (int i = 0; i < cantMusicos; ++i) {
        vMusicos[cantMusicosInstrumento] = aMusicos.leerRegistro(i);
        if (vMusicos[cantMusicosInstrumento].getEstado()) {
            if (vMusicos[cantMusicosInstrumento].getInstrumento() == idInstrumento) {
                ++cantMusicosInstrumento;
            }
        }
    }

    mostrarVectorMusicos(vMusicos, cantMusicosInstrumento);
    delete[] vMusicos;
}

#endif
