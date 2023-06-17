#include <iostream>
#include <cstring>

class Empresa {
private:
    int codigo;
    int tipoEmpresa;
    char nombre[30];
    char direccion[30];
    bool estado;
public:
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

    void agregarRegistro(empresaPromedioRecaudacion &obj) {
        FILE *archivo = fopen(nombre, "wb");
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
    puntoA();
    PuntoB();
}

float promedioRecaudacion(int codigo, Pasaje *pasajes, int cantPasajes) {
    int cantRecaudos = 0;
    float sumaRecaudacion = 0;
    for (int i = 0; i < cantPasajes; ++i) {
        if (codigo == pasajes->getCodigoEmpresa() && pasajes->getEstado()) {
            sumaRecaudacion += pasajes->getImporte();
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
}

void PuntoB() {
    int cantPasajesMes[12];

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
    for (int i = 0; i < 12; ++i) {
        if (cantPasajesMes[indiceMesMax] < cantPasajesMes[i]) {
            indiceMesMax = i;
        }
    }

    std::cout << "Mes con mayor cantidad de pasajes vendidos: " << indiceMesMax + 1 << '\n';
}
