#include <iostream>
#include <cstring>

using namespace std;

#include "parcial2.h"

class ReparacionesHechas {
private:
    int dniCliente;
    char nombreCliente[30];
    int cantReparaciones;
public:
    int getDNI() {
        return dniCliente;
    }
    int getCantReparaciones() {
        return cantReparaciones;
    }
    const char *getNombreCliente() {
        return nombreCliente;
    }

    void setDNI(int x) {
        dniCliente = x;
    }
    void setNombreCliente(const char *c) {
        strncpy(nombreCliente, c, 29);
    }
    void setCantReparaciones(int x) {
        cantReparaciones = x;
    }

    void Mostrar() {
        cout << dniCliente << ' ' << nombreCliente << ' ' << cantReparaciones << '\n';
    }
};

class ArchivoReparacionesHechas {
private:
    char *nombre;
public:
    ArchivoReparacionesHechas(const char *n) {
        int tam = strlen(n) + 1;

        nombre = new char[tam];
        if (nombre == NULL) {
            std::cout << "Error asignando tamanio para nombre archivo reparaciones hechas.\n";
            system("pause");
            exit(1);
        }

        strcpy(nombre, n);
    }
    ~ArchivoReparacionesHechas() {
        delete nombre;
    }

    ReparacionesHechas leerRegistro(int pos) {
        ReparacionesHechas obj;
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            obj.setDNI(-1);
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

        int cantidad = ftell(archivo) / sizeof(ReparacionesHechas);

        fclose(archivo);

        return cantidad;
    }

        void mostrarRegistros() {
        FILE *archivo = fopen(nombre, "rb");
        if (archivo == NULL) {
            return;
        }

        ReparacionesHechas obj;
        while(fread(&obj, sizeof(obj), 1, archivo)) {
            obj.Mostrar();
        }

        fclose(archivo);
    }

    void agregarRegistro(ReparacionesHechas &obj) {
        FILE *archivo = fopen(nombre, "ab");
        if (archivo == NULL) {
            return;
        }

        fwrite(&obj, sizeof(obj), 1, archivo);

        fclose(archivo);
    }
};

void punto1();
void punto2();

int main() {
    while(true) {
        std::cout << "Menu:\n";
        std::cout << "1. Pregunta 1\n";
        std::cout << "2. Pregunta 2\n";
        std::cout << "0. Salir\n";
        std::cout << "\nOPCION: ";
        int opcion;
        cin >> opcion;
        system("cls");
        switch(opcion) {
            case 1:
                punto1();
            break;
            case 2:
                punto2();
            break;
            case 0:
                return 0;
            break;
            default:
                std::cout << "Opcion no existe\n";
            break;
        }
        system("pause");
        system("cls");
    }
}

// Generar un archivo con las reparaciones hechas a los clientes con el siguiente formato.
// DNI, nombre del cliente y cantidad de reparaciones.
// Listar el archivo generado.
int contarReparaciones(int dni) {
    ArchivoReparaciones reparaciones("reparaciones.dat");
    int cantReparaciones = reparaciones.contarRegistros();

    int cantXcliente = 0;
    Reparacion reparacion;
    for (int i = 0; i < cantReparaciones; ++i) {
        reparacion = reparaciones.leerRegistro(i);
        if (reparacion.getEstado() && (dni == reparacion.getDNI())) {
            ++cantXcliente;
        }
    }
    return cantXcliente;
}

void punto1() {
    ArchivoClientes clientes("clientes.dat");
    ArchivoReparacionesHechas archivo("punto1.dat");

    Cliente cliente;
    ReparacionesHechas obj;

    int cantClientes = clientes.contarRegistros();
    for (int i = 0; i < cantClientes; ++i) {
        cliente = clientes.leerRegistro(i);

        if (cliente.getEstado()) {
            obj.setDNI(cliente.getDNI());
            obj.setNombreCliente(cliente.getNombre());
            obj.setCantReparaciones(contarReparaciones(cliente.getDNI()));

            archivo.agregarRegistro(obj);
        }
    }

    std::cout << "Archivo Generado:\n";
    archivo.mostrarRegistros();
}

// Calcular e informar la categoría con más talleres.
void punto2() {
    ArchivoTalleres talleres("talleres.dat");
    int cantTalleres = talleres.contarRegistros();
    if (cantTalleres <= 0) {
        std::cout << "No hay archivo o talleres para leer.\n";
        return;
    }

    int TalleresXcategoria[10] = {0};

    Taller taller;
    for (int i = 0; i < cantTalleres; ++i) {
        taller = talleres.leerRegistro(i);

        if (taller.getEstado()) {
            ++TalleresXcategoria[taller.getCategoria() - 1];
        }
    }

    int categoriaMasTalleres = 0;
    for (int i = 0; i < 10; ++i) {
        if (TalleresXcategoria[categoriaMasTalleres] < TalleresXcategoria[i]) {
            categoriaMasTalleres = i;
        }
    }

    std::cout << "Categoria con mas talleres: " << categoriaMasTalleres + 1 << '\n';
}

// // Generar un vector dinámico que contenga todos los talleres de la provincia 3.
// void listarVector(Taller *vTalleres, int tam) {
//     std::cout << "Tallers Provincia 3:\n";
//     for (int i = 0; i < tam; ++i) {
//         std::cout << "COD: "<< vTalleres[i].getCodigoTaller() << '\n'
//             << "NOMBRE: "<< vTalleres[i].getNombre() << '\n'
//             << "CAT: " << vTalleres[i].getCategoria() << '\n'
//             << "GERENTE: " << vTalleres[i].getGerente() << "\n\n";
//     }
// }
//
// void punto4() {
//     ArchivoTalleres talleres("talleres.dat");
//     int cantTalleres = talleres.contarRegistros();
//     if (cantTalleres <= 0) {
//         return;
//     }
//
//     Taller *vTalleres = new Taller[cantTalleres];
//     if (vTalleres == NULL) {
//         return;
//     }
//     int cantProv3 = 0;
//     for (int i = 0; i < cantTalleres; ++i) {
//         vTalleres[cantProv3] = talleres.leerRegistro(i);
//         if (vTalleres[cantProv3].getEstado() &&
//             vTalleres[cantProv3].getProvincia() == 3)
//         {
//             ++cantProv3;
//         }
//     }
//
//     listarVector(vTalleres, cantProv3);
//
//     delete[] vTalleres;
// }
