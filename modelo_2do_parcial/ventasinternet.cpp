#include "sec_api/string_s.h"
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

void cargaCodigo(char *codigo, int tam, char c) {
    for (int i= 0; i < tam; ++i) {
        codigo[i] = c;
    }
    codigo[tam - 1] = '\0';
}

class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(const char *texto) {
        if (strcmp(texto, "actual") == 0) {
            time_t tiempo = time(NULL);
            struct tm *fechaActual = localtime(&tiempo);

            anio = fechaActual->tm_year + 1900;
            mes = fechaActual->tm_mon + 1;
            dia = fechaActual->tm_mday;
        }
    }
    Fecha() {}

    void setDia(int x) { dia = x; }
    void setMes(int x) { mes = x; }
    void setAnio(int x) { anio = x; }
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }
};

class Vendedor {
private:
    char codigo[5];
    char nombre[30];
    int provincia; // 1 a 24
    int clasificacion; // 1 a 10
    bool estado;
public:
    void cargaRandom(char c) {
        cargaCodigo(codigo, 5, c);
        autoCargaCadena(nombre, 15);
        provincia = randomNumBetween(1, 24); // 1 a 24
        clasificacion = randomNumBetween(1, 10); // 1 a 10
        estado = true;
    }
    void setProvincia(int x) { provincia = x; }
    const char *getCodigo() { return codigo; }
    const char *getNombre() { return nombre; }
    bool getEstado() {return estado;}
    int getProvincia() {return provincia;}
};

class Usuario {
private:
    char codigo[5];
    char nombre[30];
    int dni;
    Fecha fechaRegistro;
    bool estado;
public:
    void cargaRandom() {
        autoCargaCadena(codigo, 5);
        autoCargaCadena(nombre, 15);
        fechaRegistro.setDia(randomNumBetween(1, 31));
        fechaRegistro.setMes(randomNumBetween(1, 12));
        fechaRegistro.setAnio(randomNumBetween(2013, 2018));
        dni = randomNum(10000);
        estado = true;
    }
    void setDni(int x) { dni = x; }
    bool getEstado() {return estado;}
    Fecha getFecha() {return fechaRegistro;}
};

class Venta {
private:
    int numCompra;
    char codigoVendedor[5];
    char codigoUsuario[5];
    float importe;
    Fecha fecha;
    int tipoPago;
    bool estado;
public:
    void autoCarga(int x) {
        cargaCodigo(codigoVendedor, 5, randomLetter());
        fecha.setDia(randomNumBetween(1, 31));
        fecha.setMes(randomNumBetween(1, 12));
        fecha.setAnio(randomNumBetween(2013, 2018));
        estado = true;
    }
    void setNumCompra(int x) { numCompra = x; }
    const char *getCodigoVendedor() {return codigoVendedor;}
    bool getEstado() {return estado;}
    Fecha getFecha() {return fecha;}
};

class archivoVenta {
private:
    char *nombre;
public:
    archivoVenta(const char *nombreArchivo) {
        int tam = strlen(nombreArchivo) + 1;
        nombre = new char[tam];
        if (nombre == NULL) {
            exit(1);
        }
        strcpy(nombre, nombreArchivo);
    }
    ~archivoVenta() { delete nombre; }
    Venta leerRegistro(int pos) {
        Venta obj;
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            obj.setNumCompra(-1);
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
        int cantidad = ftell(archivo) / sizeof(Venta);
        fclose(archivo);
        return cantidad;
    }
    void agregarRegistro(Venta &obj) {
        FILE *archivo = fopen(nombre, "ab");
        if (archivo == NULL) {
            return;
        }
        fwrite(&obj, sizeof(obj), 1, archivo);
        fclose(archivo);
    }
};


class archivoUsuario {
private:
    char *nombre;
public:
    archivoUsuario(const char *nombreArchivo) {
        int tam = strlen(nombreArchivo) + 1;
        nombre = new char[tam];
        if (nombre == NULL) {
            exit(1);
        }
        strcpy(nombre, nombreArchivo);
    }
    ~archivoUsuario() { delete nombre; }
    Usuario leerRegistro(int pos) {
        Usuario obj;
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            obj.setDni(-1);
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
        int cantidad = ftell(archivo) / sizeof(Usuario);
        fclose(archivo);
        return cantidad;
    }
    void agregarRegistro(Usuario &obj) {
        FILE *archivo = fopen(nombre, "ab");
        if (archivo == NULL) {
            return;
        }
        fwrite(&obj, sizeof(obj), 1, archivo);
        fclose(archivo);
    }
};

class archivoVendedor {
private:
    char *nombre;
public:
    archivoVendedor(const char *nombreArchivo) {
        int tam = strlen(nombreArchivo) + 1;
        nombre = new char[tam];
        if (nombre == NULL) {
            exit(1);
        }
        strcpy(nombre, nombreArchivo);
    }
    ~archivoVendedor() { delete nombre; }
    Vendedor leerRegistro(int pos) {
        Vendedor obj;
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            obj.setProvincia(-1);
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
        int cantidad = ftell(archivo) / sizeof(Vendedor);
        fclose(archivo);
        return cantidad;
    }
    void agregarRegistro(Vendedor &obj) {
        FILE *archivo = fopen(nombre, "ab");
        if (archivo == NULL) {
            return;
        }
        fwrite(&obj, sizeof(obj), 1, archivo);
        fclose(archivo);
    }
};

class VendedorInactivo {
private:
    char codigo[5];
    char nombre[30];
public:
    void setCodigo(const char *c) { strcpy(codigo, c); }
    void setNombre(const char *c) { strcpy(nombre, c); }
    void mostrar() {
        std::cout << codigo << ' ' << nombre << '\n';
    }
};


class archivoVendedorInactivo {
private:
    char *nombre;
public:
    archivoVendedorInactivo(const char *nombreArchivo) {
        int tam = strlen(nombreArchivo) + 1;
        nombre = new char[tam];
        if (nombre == NULL) {
            exit(1);
        }
        strcpy(nombre, nombreArchivo);
    }
    ~archivoVendedorInactivo() { delete nombre; }
    int contarRegistros() {
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            return -1;
        }
        fseek(archivo, 0, SEEK_END);
        int cantidad = ftell(archivo) / sizeof(VendedorInactivo);
        fclose(archivo);
        return cantidad;
    }
    void agregarRegistro(VendedorInactivo &obj) {
        FILE *archivo = fopen(nombre, "ab");
        if (archivo == NULL) {
            return;
        }
        fwrite(&obj, sizeof(obj), 1, archivo);
        fclose(archivo);
    }
    void mostrarRegistros() {
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            return;
        }
        VendedorInactivo obj;
        while(fread(&obj, sizeof(obj), 1, archivo)) {
            obj.mostrar();
        }
        fclose(archivo);
    }
};

void punto1();
void punto2();
void punto3();

int main() {
    srand(time(NULL));
    archivoVendedor vendedores("Vendedores.dat");
    archivoVenta ventas("Ventas.dat");
    archivoUsuario archivo("Usuarios.dat");

    if ((vendedores.contarRegistros()) <= 0) {
        Vendedor obj;
        for (int i = 0; i < 10; ++i) {
            obj.cargaRandom(char(65 + i));
            vendedores.agregarRegistro(obj);
        }
    }
    if (ventas.contarRegistros() <= 0) {
        Venta obj;
        for (int i = 0; i < 50; ++i) {
            obj.autoCarga(i);
            ventas.agregarRegistro(obj);
        }
    }
    if (archivo.contarRegistros() <= 0) {
        Usuario obj;
        for (int i = 0; i < 50; ++i) {
            obj.cargaRandom();
            archivo.agregarRegistro(obj);
        }
    }


    punto1();
    punto2();
    punto3();
}

bool checkearVentasAnio(const char *codigo, Venta *vVentas, int cantVentas) {
    Fecha fechaActual("actual");
    for (int i = 0; i < cantVentas; ++i) {
        if (vVentas[i].getEstado()) {
            if (strcmp(codigo, vVentas[i].getCodigoVendedor()) == 0) {
                if (vVentas[i].getFecha().getAnio() == fechaActual.getAnio()) {
                    return true;
                }
            }
        }
    }
    return false;
}

void punto1() {
    archivoVendedor vendedores("Vendedores.dat");
    archivoVenta ventas("Ventas.dat");

    int cantVentas = ventas.contarRegistros();
    int cantVendedores = vendedores.contarRegistros();
    if (cantVentas <= 0 || cantVendedores <= 0) {
        std::cout << cantVendedores << ' ' << cantVentas << ' ' << "cant de chiches fallo. \n";
        return;
    }

    Venta *vVentas = new Venta[cantVentas];
    if (vVentas == NULL) { 
        std::cout << "vventas fallo.\n";
        return; 
    }
    for (int i = 0; i < cantVentas; ++i) {
        vVentas[i] = ventas.leerRegistro(i);
    }

    Vendedor vendedor;
    VendedorInactivo obj;
    archivoVendedorInactivo archivo("VendedoresInactivos2023.dat");
    for (int i = 0; i < cantVendedores; ++i) {
        vendedor = vendedores.leerRegistro(i);
        if (vendedor.getEstado()) {
            if (!checkearVentasAnio(vendedor.getCodigo(), vVentas, cantVentas)) {
                obj.setCodigo(vendedor.getCodigo());     
                obj.setNombre(vendedor.getNombre());
                archivo.agregarRegistro(obj);
            }
        }
    }

    delete[] vVentas;

    std::cout << "Archivo generado:\n";
    archivo.mostrarRegistros();
}

void punto2() {
    archivoUsuario archivo("Usuarios.dat");

    int cantUsuarios = archivo.contarRegistros();

    int cantUsuarios2015[12] = {0};
    
    Usuario obj;
    for (int i = 0; i < cantUsuarios; ++i) {
        obj = archivo.leerRegistro(i);
        if (obj.getEstado()) {
            Fecha fechaObj = obj.getFecha();
            if (fechaObj.getAnio() == 2015) {
                ++cantUsuarios2015[fechaObj.getMes() - 1];
            }
        }
    }

    std::cout << "Cantidad de usuarios por mes en 2015: \n";
    for (int i = 0; i < 12; ++i) {
        std::cout << cantUsuarios2015[i] << '\n';
    }
}

int cantVentasVendedor(const char *codigo, Venta *ventas, int cantVentas) {
    int ventasVendedor = 0;
    for (int i = 0; i < cantVentas; ++i) {
        if (ventas[i].getEstado()) {
            if (strcmp(codigo, ventas[i].getCodigoVendedor())) {
                ++ventasVendedor;
            }
        }
    }
    return ventasVendedor;
}

void punto3() {
    archivoVendedor vendedores("Vendedores.dat");
    archivoVenta ventas("Ventas.dat");

    int cantVentas = ventas.contarRegistros();
    int cantVendedores = vendedores.contarRegistros();
    if (cantVentas <= 0 || cantVendedores <= 0) {
        std::cout << "cant fallo\n";
        return;
    }

    Venta *vVentas = new Venta[cantVentas];
    if (vVentas == NULL) { 
        std::cout << "fallo vventas\n";
        return; 
    }
    for (int i = 0; i < cantVentas; ++i) {
        vVentas[i] = ventas.leerRegistro(i);
    }

    int *cantVentasLitoral = new int[cantVendedores];
    if (cantVentasLitoral == NULL) {
        std::cout << "fallo cantventaslitoral\n";
        return;
    }

    Vendedor vendedor;
    int cantActivosLitoral = 0;
    for (int i = 0; i < cantVendedores; ++i) {
        vendedor = vendedores.leerRegistro(i);
        if (vendedor.getEstado() && vendedor.getProvincia() >= 8 && vendedor.getProvincia() <= 10) {
            cantVentasLitoral[cantActivosLitoral] = cantVentasVendedor(vendedor.getCodigo(), vVentas, cantVentas);
            ++cantActivosLitoral;
        }
    }

    std::cout << "ventas en el litoral por vendedor:\n";
    for (int i = 0; i < cantActivosLitoral; ++i) {
        std::cout << cantVentasLitoral[i] << '\n';
    }

    delete[] vVentas;
    delete[] cantVentasLitoral;
}
