#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

// 1) Dado un nombre de continente que se ingresa por teclado, generar un archivo con los países que pertenezcan a ese continente con el siguiente formato:
// Id país, nombre del país y cantidad de géneros originarios del país.

class generosPorPais {
private:
    int idPais;
    char nombre[30];
    int cantGeneros;
public:
    void setIdPais(int x) { idPais = x; }
    void setNombre(const char * n) { strcpy(nombre, n); }
    void setCantGeneros(int x) { cantGeneros = x; }
    void mostrar() {
        std::cout << idPais << ' ' << nombre << ' ' << cantGeneros << '\n';
    }
};

int contarGenerosPais(int id, GeneroMusical *vGeneros, int cantGeneros) {
    int conteoGeneros = 0;
    for (int i = 0; i < cantGeneros; ++i) {
        if (id == vGeneros[i].getId() && vGeneros[i].getEstado()) {
            ++conteoGeneros;
        }
    }
    return conteoGeneros;
}

void punto1() {
    char continente[30];
    mostrarAviso("INGRESE CONTINENTE: ");
    cargarCadena(continente, 30);

    ArchivoPais paises("paises.dat"); 
    int cantPaises = paises.contarRegistros();

    ArchivoGeneroMusical generos("generos.dat");
    int cantGeneros = generos.contarRegistros();
    GeneroMusical *vGeneros = new GeneroMusical[cantGeneros];
    for (int i = 0; i < cantGeneros; ++i) {
        vGeneros[i] = generos.leerRegistro(i);
    }

    FILE *archivo = fopen("punto1.dat", "wb");
    fclose(archivo);

    Pais pais;
    generosPorPais obj;
    for (int i = 0; i < cantPaises; ++i) {
        pais = paises.leerRegistro(i);
        if (pais.getEstado()) {
            if (strcasecmp(pais.getContinente(), continente) == 0) {
                int id = pais.getId();
                obj.setNombre(pais.getNombre());
                obj.setIdPais(id);
                obj.setCantGeneros(contarGenerosPais(id, vGeneros, cantGeneros));

                FILE *archivo = fopen("punto1.dat", "ab");
                if (archivo == NULL) { return; }
                fwrite(&obj, sizeof(obj), 1, archivo);
                fclose(archivo);
            }
        }
    }
    delete[] vGeneros;

    archivo = fopen("punto1.dat", "rb");
    if (archivo == NULL) { return; }
    std::cout << "Archivo Generado:\n";
    while (fread(&obj, sizeof(obj), 1, archivo)) {
        obj.mostrar();
    }
    fclose(archivo);
}

// 2) Dar de baja a todos los músicos del claustro docente que tengan como instrumento principal el número 3.
void punto2() {
    ArchivoMusico musicos("musicos.dat");
    int cantMusicos = musicos.contarRegistros();
    
    Musico obj;
    for (int i = 0; i < cantMusicos; ++i) {
        obj = musicos.leerRegistro(i);
        if (obj.getEstado()) {
            if (obj.getClaustro() == 1 && obj.getInstrumento() == 3) {
                obj.setEstado(false);
                musicos.modificarRegistro(obj, i);
            }
        }
    }
}

// 3) Listar usando un vector dinámico todos los géneros cuyo año de orígen sea menor a 1900
void punto3() {
    ArchivoGeneroMusical generos("generos.dat");
    int cantGeneros = generos.contarRegistros();

    GeneroMusical *vGeneros = new GeneroMusical[cantGeneros];
    for (int i = 0; i < cantGeneros; ++i) {
        vGeneros[i] = generos.leerRegistro(i);
    }

    std::cout << "Generos con anio de origen menor a 1900:\n";
    for (int i = 0; i < cantGeneros; ++i) {
        if (vGeneros[i].getAnioOrigen() < 1900) {
            vGeneros[i].Mostrar();
            std::cout << '\n';
        }
    }
    delete[] vGeneros;
}

#endif
