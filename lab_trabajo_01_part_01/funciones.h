#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int buscarCliente(int dni) {
    FILE *pCli = fopen("clientes.dat", "rb");
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

Cliente leerCliente(int p) {
    Cliente obj;

    if (p < 0) {
        obj.setDNI(-3);
        return obj;
    }

    FILE *pCli = fopen("clientes.dat", "rb");
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
        if (obj.getEstado()) {
            obj.Mostrar();
            cout << '\n';
        }
    }
    fclose(pCli);
}

void buscarPorDNI() {
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
    ignoreLine();

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

bool modificarRegistro(Cliente obj, int pos) {
    FILE *pCli = fopen("clientes.dat", "rb+");
    if (pCli == NULL) {
        cout << "ERROR AL REABRIR EL ARCHIVO.\n";
        return false;
    }

    fseek(pCli, sizeof(Cliente) * pos, SEEK_SET);

    bool aux = fwrite(&obj, sizeof(Cliente), 1, pCli);
    fclose(pCli);

    return aux;
}

bool bajaLogica() {
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

bool modificarEmail() {
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
        cout << "EL CLIENTE ingresado está DADO DE BAJA\n";
        return false;
    }

    // Modificarmos el campo estado (lo ponemos en false)
    char email[25];
    cout << "Ingrese nuevo email: ";
    cargarCadena(email, 25);

    obj.setEmail(email);

    // Sobreescribir
    return modificarRegistro(obj, pos);
}

#endif  // FUNCIONES_H_INCLUDED
