#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargaCliente() {
    Cliente obj;
    FILE *pCli;
    pCli = fopen("clientes.dat", "ab");
    if (pCli == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        return;
    }
    obj.Cargar();
    fwrite(&obj, sizeof obj, 1, pCli);
    fclose(pCli);
}

void mostrarClientes() {
    Cliente obj;
    FILE *pCli;
    pCli = fopen("clientes.dat", "rb");
    if (pCli == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        return;
    }

    while (fread(&obj, sizeof obj, 1, pCli) == 1) {
        obj.Mostrar();
        cout << endl;
    }
    fclose(pCli);
}

void buscarPorDNI() {
    Cliente obj;
    bool encontro = false;
    FILE *pCli;
    pCli = fopen("clientes.dat", "rb");
    if (pCli == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        return;
    }
    int DNI;
    cout << "INGRESE EL DNI A BUSCAR ";
    cin >> DNI;

    while (fread(&obj, sizeof obj, 1, pCli) == 1) {
        if (DNI == obj.getDNI()) {
            obj.Mostrar();
            cout << endl;
            encontro = true;
        }
    }
    if (encontro == false) {
        cout << "NO SE ENCONTRO CLIENTE CON ESE DNI" << endl;
    }
    fclose(pCli);
}

void mostrarPorApellido() {
    Cliente obj;
    bool encontro = false;
    FILE *pCli;
    pCli = fopen("clientes.dat", "rb");
    if (pCli == NULL) {
        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl;
        return;
    }
    char letra;
    cout << "INGRESE EL DNI A BUSCAR ";
    cin >> letra;

    while (fread(&obj, sizeof obj, 1, pCli) == 1) {
        if (tolower(letra) == tolower(obj.getApellido()[0])) {
            obj.Mostrar();
            cout << endl;
            encontro = true;
        }
    }
    if (encontro == false) {
        cout << "NO SE ENCONTRO CLIENTE CON APELLIDO EMPEZADO EN " << letra << endl;
    }
    fclose(pCli);
}

#endif  // FUNCIONES_H_INCLUDED
