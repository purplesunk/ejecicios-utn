#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

bool copiarArchivo(const char *fuente, const char *destino, void *obj, size_t tam) {
    FILE *archivo = fopen(fuente, "rb");
    if (archivo == NULL) {
        std::cout << "No se pudo abrir el archivo.\n";
        return false;
    }

    FILE *copia = fopen(destino, "wb");
    if (copia == NULL) {
        std::cout << "No se pudo crear el archivo para copiar.\n";
        fclose(archivo);
        return false;
    }

    while (fread(obj, tam, 1, archivo)) {
        fwrite(obj, tam, 1, copia);
    }

    fclose(archivo);
    fclose(copia);

    return true;
}

bool copiaSeguridadMusicos() {
    Musico obj;
    return copiarArchivo("musicos.dat", "musicos.bkp", &obj, sizeof(obj));
}

bool copiaSeguridadGeneros() {
    GeneroMusical obj;
    return copiarArchivo("generos.dat", "generos.bkp", &obj, sizeof(obj));
}

bool restaurarMusicos() {
    Musico obj;
    return copiarArchivo("musicos.bkp", "musicos.dat", &obj, sizeof(obj));
}

bool restaurarGeneros() {
    GeneroMusical obj;
    return copiarArchivo("generos.bkp", "generos.dat", &obj, sizeof(obj));
}

bool restablecerInicio() {
    GeneroMusical obj;
    bool generos = copiarArchivo("datosInicialesGeneros.dat", "generos.dat", &obj, sizeof(obj));

    Musico obj2;
    bool musicos = copiarArchivo("datosInicialesMusicos.dat", "musicos.dat", &obj2, sizeof(obj2));

    return (generos && musicos)
}

#endif
