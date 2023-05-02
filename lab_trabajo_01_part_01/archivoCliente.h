#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED

#include "cliente.h"

class ArchivoCliente {
   private:
    char nombre[30];

   public:
    ArchivoCliente(const char *nombreArchivo) {
        strncpy(nombre, nombreArchivo, 30);
    }
    // ALTA
    void agregarRegistro();
    void mostrarRegistros();

    // BAJA
    Cliente leerCliente(int p);
    int buscarCliente(int dni);
    bool bajaLogica();

    // MODIFICACION
    bool modificarRegistro(Cliente obj, int pos);

    // LISTADOS
    void buscarPorDNI();
};

void
ArchivoCliente::agregarRegistro() {
    FILE *pCli = fopen(nombre, "ab");
    if (pCli == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        return;
    }

    Cliente obj;
    obj.Cargar();
    fwrite(&obj, sizeof obj, 1, pCli);
    fclose(pCli);
}

bool ArchivoCliente::bajaLogica() {
    // Solicitar que registro se quiere dar de baja
    int DNI;
    cout << "INGRESE EL DNI A BUSCAR ";
    cin >> DNI;
    ignoreLine();

    // Buscar el registro en el archivo
    int pos = buscarCliente(DNI);
    if (pos == -1) {
        cout << "NO EXISTE CLIENTE CON ESE DNI\n";
        return false;
    }
    if (pos == -2) {
        cout << "NO SE PUDO ABRIR ARCHIVO\n";
        return false;
    }

    Cliente obj = leerCliente(pos);

    if (obj.getEstado() == false) {
        cout << "EL CLIENTE INGRESADO YA ESTA DADO DE BAJA\n";
        return false;
    }

    // Modificarmos el campo estado (lo ponemos en false)
    obj.setEstado(false);

    // Sobreescribir
    return modificarRegistro(obj, pos);
}

Cliente ArchivoCliente::leerCliente(int p) {
    Cliente obj;

    if (p < 0) {
        obj.setDNI(-3);
        return obj;
    }

    FILE *pCli = fopen(nombre, "rb");
    if (pCli == NULL) {
        obj.setDNI(-2);
        return obj;
    }

    fseek(pCli, (sizeof(Cliente) * p), SEEK_SET);

    if (!fread(&obj, sizeof(Cliente), 1, pCli)) {
        obj.setDNI(-1);
    }

    return obj;
}

int ArchivoCliente::buscarCliente(int dni) {
    FILE *pCli = fopen(nombre, "rb");
    if (pCli == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        return -2;
    }

    int pos = 0;
    Cliente obj;

    while (fread(&obj, sizeof(obj), 1, pCli) == 1) {
        if (dni == obj.getDNI()) {
            fclose(pCli);
            return pos;
        }
        ++pos;
    }

    fclose(pCli);

    cout << "NO SE ENCONTRO CLIENTE CON ESE DNI\n";
    return -1;
}

bool ArchivoCliente::modificarRegistro(Cliente obj, int pos) {
    FILE *pCli = fopen(nombre, "rb+");
    if (pCli == NULL) {
        cout << "ERROR AL REABRIR EL ARCHIVO.\n";
        return false;
    }

    fseek(pCli, sizeof(Cliente) * pos, SEEK_SET);

    bool aux = fwrite(&obj, sizeof(Cliente), 1, pCli);
    fclose(pCli);

    return aux;
}

void ArchivoCliente::mostrarRegistros() {
    FILE *pCli = fopen(nombre, "rb");
    if (pCli == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        return;
    }

    Cliente obj;
    while (fread(&obj, sizeof obj, 1, pCli) == 1) {
        if (obj.getEstado()) {
            obj.Mostrar();
            cout << '\n';
        }
    }
    fclose(pCli);
}

void ArchivoCliente::buscarPorDNI() {
    int DNI;
    cout << "INGRESE EL DNI A BUSCAR ";
    cin >> DNI;
    ignoreLine();

    int pos = buscarCliente(DNI);
    Cliente obj = leerCliente(pos);
    if (obj.getDNI() > 0) {
        obj.Mostrar();
    } else if (obj.getDNI() == -3 || obj.getDNI() == -1) {
        cout << "SE PUSO UNA POSICIÓN EQUIVOCADA\n";
    } else {
        cout << "ERROR DE ARCHIVO.\n";
    }
}

#endif  // ARCHIVOCLIENTE_H_INCLUDED
