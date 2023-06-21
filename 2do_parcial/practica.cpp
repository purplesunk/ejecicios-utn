#include <iostream>
#include <cstring>
#include <ctime>

int randomNum(int max) {
    return (rand() % max) + 1;
}

int randomNumBetween(int lower, int upper) {
    return (rand() % (upper - lower + 1) + lower);
}

char randomLetter() {
    return (rand() % 26) + 65;
}

void autoCargaCadena(char *cadena, int tam) {
    for (int i = 0; i < tam; ++i) {
        cadena[i] = randomLetter();
    }
    cadena[tam - 1] = '\0';
}

class Empresa {
private:
    int codigo;
    int tipoEmpresa;
    char nombre[30];
    char direccion[30];
    bool estado;
public:
    void setRandom(int i) {
        codigo = i;
        tipoEmpresa = randomNum(4);
        autoCargaCadena(nombre, 15);
        autoCargaCadena(direccion, 15);
        estado = true;
    }
    const char *getNombre() { return nombre; }
    const char *getDireccion() { return direccion; }
    int getCodigo() { return codigo; }
    int getTipo() { return tipoEmpresa; }
    bool getEstado() {return estado;}
    void setCodigo(int x) {
        codigo = x;
    }
};

class Pasaje {
private:
    int numero;
    int codigoEmpresa;
    int cuitCliente;
    int dia;
    int mes;
    int anio;
    float importe;
    char formaPago;
    bool estado;
public:
    void setRandom(){
        numero = randomNum(5);
        codigoEmpresa = randomNum(10);
        cuitCliente = randomNum(100000);
        dia = randomNum(31);
        mes = randomNum(12);
        anio = randomNumBetween(1950, 2023);
        importe = randomNum(5000);
        formaPago = randomLetter();
        estado = true;
    }
    int getCodigoEmpresa() { return codigoEmpresa; }
    int getMes() { return mes; }
    float getImporte() {return importe;}
    bool getEstado() {return estado;}
    void setNumero(int x) {
        numero = x;
    }
};

class archivoEmpresa {
private:
    char *nombre;
public:
    archivoEmpresa(const char *n) {
        int tam = strlen(n) + 1;

        nombre = new char[tam];
        if (nombre == NULL) {
            exit(1);
        }

        strcpy(nombre, n);
    }

    ~archivoEmpresa() {
        delete nombre;
    }

    Empresa leerRegistro(int pos) {
        Empresa obj;
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            obj.setCodigo(-1);
            return obj;
        }

        fseek(archivo, sizeof(obj) * pos, SEEK_SET);

        fread(&obj, sizeof(obj), 1, archivo);

        fclose(archivo);

        return obj;       
    }

    int contarRegistros() {
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            return -1;
        }

        fseek(archivo, 0, SEEK_END);

        int cantidad = ftell(archivo) / sizeof(Empresa);

        fclose(archivo);

        return cantidad;
    }

        void mostrarRegistros() {
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            return;
        }

        Empresa obj;
        while(fread(&obj, sizeof(obj), 1, archivo)) {
            // obj.mostrar();
        }
        
        fclose(archivo);
    }

    void agregarRegistro(Empresa &obj) {
        FILE *archivo = fopen(nombre, "ab");
        if (archivo == NULL) {
            return;
        }
        
        fwrite(&obj, sizeof(obj), 1, archivo);

        fclose(archivo);
    }
};

class archivoPasaje {
private:
    char *nombre;
public:
    archivoPasaje(const char *n) {
        int tam = strlen(n) + 1;

        nombre = new char[tam];
        if (nombre == NULL) {
            exit(1);
        }

        strcpy(nombre, n);
    }

    ~archivoPasaje() {
        delete nombre;
    }

    Pasaje leerRegistro(int pos) {
        Pasaje obj;
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            obj.setNumero(-1);
            return obj;
        }

        fseek(archivo, sizeof(obj) * pos, SEEK_SET);

        fread(&obj, sizeof(obj), 1, archivo);

        fclose(archivo);

        return obj;       
    }

    int contarRegistros() {
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            return -1;
        }

        fseek(archivo, 0, SEEK_END);

        int cantidad = ftell(archivo) / sizeof(Pasaje);

        fclose(archivo);

        return cantidad;
    }

    void mostrarRegistros() {
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            return;
        }

        Pasaje obj;
        while(fread(&obj, sizeof(obj), 1, archivo)) {
            // obj.mostrar();
        }
        
        fclose(archivo);
    }

    void agregarRegistro(Pasaje &obj) {
        FILE *archivo = fopen(nombre, "ab");
        if (archivo == NULL) {
            return;
        }
        
        fwrite(&obj, sizeof(obj), 1, archivo);

        fclose(archivo);
    }
};

class empresaPromedioRecaudacion {
private:
    int codigo;
    char nombre[30];
    float promedioRecaudacion;

public:
    void setCodigo(int x) {codigo = x;}
    void setNombre(const char *c) {strcpy(nombre, c);}
    void setPromedio(float x) {promedioRecaudacion=x;}
    void mostrar() {
        std::cout << codigo << ' ' << nombre << ' ' << promedioRecaudacion << '\n';
    }
};

class archivoPromedioRecaudacion {
private:
    char *nombre;
public:
    archivoPromedioRecaudacion(const char *n) {
        int tam = strlen(n) + 1;

        nombre = new char[tam];
        if (nombre == NULL) {
            exit(1);
        }

        strcpy(nombre, n);
    }

    ~archivoPromedioRecaudacion() {
        delete nombre;
    }

    empresaPromedioRecaudacion leerRegistro(int pos) {
        empresaPromedioRecaudacion obj;
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            obj.setCodigo(-1);
            return obj;
        }

        fseek(archivo, sizeof(obj) * pos, SEEK_SET);

        fread(&obj, sizeof(obj), 1, archivo);

        fclose(archivo);

        return obj;       
    }

    int contarRegistros() {
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            return -1;
        }

        fseek(archivo, 0, SEEK_END);

        int cantidad = ftell(archivo) / sizeof(empresaPromedioRecaudacion);

        fclose(archivo);

        return cantidad;
    }

    void mostrarRegistros() {
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            return;
        }

        empresaPromedioRecaudacion obj;
        while(fread(&obj, sizeof(obj), 1, archivo)) {
            obj.mostrar();
        }
        
        fclose(archivo);
    }

    void agregarRegistro(empresaPromedioRecaudacion &obj) {
        FILE *archivo = fopen(nombre, "ab");
        if (archivo == NULL) {
            return;
        }
        
        fwrite(&obj, sizeof(obj), 1, archivo);

        fclose(archivo);
    }
};

void puntoA();
void PuntoB();

int main() {
    srand(time(NULL));
    // archivoEmpresa aEmpresas("Empresa.dat");
    // archivoPasaje aPasajes("Pasaje.dat");
    // Empresa empresa;
    // for (int i = 1; i <= 5; ++i) {
    //     empresa.setRandom(i);
    //     aEmpresas.agregarRegistro(empresa);
    // }
    // 
    // Pasaje pasaje;
    // for (int i = 0; i < 50; ++i) {
    //     pasaje.setRandom();
    //     aPasajes.agregarRegistro(pasaje);
    // } 
    
    puntoA();
    PuntoB();
}

float promedioRecaudacion(int codigo, Pasaje *pasajes, int cantPasajes) {
    int cantRecaudos = 0;
    float sumaRecaudacion = 0;
    for (int i = 0; i < cantPasajes; ++i) {
        if (codigo == pasajes[i].getCodigoEmpresa() && pasajes[i].getEstado()) {
            sumaRecaudacion += pasajes[i].getImporte();
            ++cantRecaudos;
        }
    }
    return sumaRecaudacion / (float)cantRecaudos;
}

void puntoA() {
    archivoEmpresa aEmpresas("Empresa.dat");
    archivoPasaje aPasajes("Pasaje.dat");
    archivoPromedioRecaudacion archivo("PuntaA.dat");

    int cantPasajes = aPasajes.contarRegistros();
    if (cantPasajes < 0) {
        return;
    }
    Pasaje *vPasajes = new Pasaje[cantPasajes];
    if (vPasajes == NULL) {
        return;
    }
    for (int i = 0; i < cantPasajes; ++i) {
        vPasajes[i] = aPasajes.leerRegistro(i);
    }

    int cantEmpresas = aEmpresas.contarRegistros();
    Empresa empresa;
    empresaPromedioRecaudacion obj;
    for (int i = 0; i < cantEmpresas; ++i) {
        empresa = aEmpresas.leerRegistro(i);
        int codigo = empresa.getCodigo();
        obj.setCodigo(codigo);
        obj.setNombre(empresa.getNombre());
        obj.setPromedio(promedioRecaudacion(codigo, vPasajes, cantPasajes));

        archivo.agregarRegistro(obj);
    }

    delete[] vPasajes;

    std::cout << "Archivo generado: \n";
    archivo.mostrarRegistros();
}

void PuntoB() {
    int cantPasajesMes[12] = {0};

    archivoPasaje archivo("Pasaje.dat");
    int cantPasajes = archivo.contarRegistros();

    Pasaje pasaje;
    for (int i = 0; i < cantPasajes; ++i) {
        pasaje = archivo.leerRegistro(i);
        if (pasaje.getEstado()) {
            ++cantPasajesMes[pasaje.getMes() - 1];
        }
    }

    int indiceMesMax = 0;
    std::cout << "Cantidad de pasajes: \n";
    for (int i = 0; i < 12; ++i) {
        if (cantPasajesMes[indiceMesMax] < cantPasajesMes[i]) {
            indiceMesMax = i;
        }
        std::cout << cantPasajesMes[i] << '\n';
    }

    std::cout << "Mes con mayor cantidad de pasajes vendidos: " << indiceMesMax + 1 << '\n';
}
