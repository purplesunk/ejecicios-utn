/// Agregar una opci�n del men� para modificar el email de un cliente. Se debe primero ingresar el DNI del cliente
///  y chequear si existe. Si existe se debe pedir un nuevo valor para el email y escribirlo en el archivo

/// Autor:DEK
/// Fecha:
/// Comentario:

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Fecha {
   private:  /// todo lo que se defina ac� s�lo va a ser accesible dentro de la clase
    int dia, mes, anio;

   public:
    Fecha(int d = 1, int m = 1, int a = 1) {
        dia = d;
        mes = m;
        anio = a;
    }
    void Cargar();
    void Mostrar();
    /// sets
    void setDia(int x) {
        if (x > 0 && x < 32) dia = x;
    }
    void setMes(int x) {
        if (x > 0 && x < 13) mes = x;
    }
    void setAnio(int x) { anio = x; }
    /// gets
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }
};

void Fecha::Cargar() {  /// m�todo o funci�n de la clase
    cout << "DIA: ";
    cin >> dia;
    cout << "MES: ";
    cin >> mes;
    cout << "ANIO: ";
    cin >> anio;
}

void Fecha::Mostrar() {  /// m�todo o funci�n de la clase
    /*cout<<"DIA: "<<dia<<endl;
    cout<<"MES: "<<mes<<endl;
    cout<<"ANIO: "<<anio<<endl<<endl;*/
    cout << dia << "/" << mes << "/" << anio << endl;
}

class Persona {
   protected:
    int DNI;
    Fecha fechaNacimiento;
    char nombre[25];
    char apellido[25];
    char email[25];
    char telefono[20];
    bool estado;

   public:
    Fecha getFechaNacimiento() {
        return fechaNacimiento;
    }

    int getDNI() { return DNI; }
    const char *getNombre() { return nombre; }
    const char *getApellido() { return apellido; }
    const char *getEmail() { return email; }
    const char *getTelefono() { return telefono; }
    bool getEstado() { return estado; }

    void setDNI(const int d) { DNI = d; }
    void setFechaNacimiento(Fecha f) { fechaNacimiento = f; }
    void setNombre(const char *n) { strcpy(nombre, n); }
    void setApellido(const char *a) { strcpy(apellido, a); }
    void setEmail(const char *e) { strcpy(email, e); }
    void setTelefono(const char *t) { strcpy(telefono, t); }
    void setEstado(bool e) { estado = e; }

    void Cargar();
    void Mostrar();
};

void Persona::Cargar() {
    cout << "DNI: ";
    cin >> DNI;
    cout << "Fecha Nacimiento: " << endl;
    fechaNacimiento.Cargar();
    cout << "Nombre: ";
    cin >> nombre;
    cout << "APELLIDO: ";
    cin >> apellido;
    cout << "EMAIL: ";
    cin >> email;
    cout << "TELEFONO: ";
    cin >> telefono;
    setEstado(true);
}

void Persona::Mostrar() {
    cout << "DNI: ";
    cout << DNI << endl;
    cout << "Fecha Nacimiento: " << endl;
    fechaNacimiento.Mostrar();
    cout << "Nombre: ";
    cout << nombre << endl;
    cout << "APELLIDO: ";
    cout << apellido << endl;
    cout << "EMAIL: ";
    cout << email << endl;
    cout << "TELEFONO: ";
    cout << telefono << endl;
}
/// fin de la clase Persona

/// Cliente: Tiene lo de persona. Adem�s tiene CUIT y una fecha de ingreso o de primera compra
class Cliente : public Persona {
   private:
    char CUIT[12];
    Fecha ingreso;

    /*
    int DNI;
    Fecha fechaNacimiento;
    char nombre[25];
    char apellido[25];
    char email[25];
    char telefono[20];
    */
   public:
    const char *getCUIT() { return CUIT; }
    Fecha getFechaIngreso() { return ingreso; }

    void setCUIT(const char *c) { strcpy(CUIT, c); }
    void setFechaIngreso(Fecha i) { ingreso = i; }

    /*int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}

    void setDNI(const int d){DNI=d;}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    */
    void Cargar() {
        cout << "CUIT ";
        cin >> CUIT;
        cout << "FECHA DE LA PRIMERA COMPRA O INGRESO " << endl;
        ingreso.Cargar();
        Persona::Cargar();
    }
    void Mostrar() {
        if (estado == true) {
            Persona::Mostrar();
            cout << "CUIT " << CUIT << endl;
            cout << "FECHA DE LA PRIMERA COMPRA O INGRESO " << endl;
            ingreso.Mostrar();
        }
    }

    void modificarDNI(int d) {
        DNI = d;
    }
};

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

int buscarClientePorDNI(int dni) {
    Cliente obj;
    int pos = 0;
    FILE *pCli;
    pCli = fopen("clientes.dat", "rb");
    if (pCli == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return -2;
    }

    while (fread(&obj, sizeof obj, 1, pCli) == 1) {
        if (dni == obj.getDNI()) {
            fclose(pCli);
            return pos;
        }
        pos++;
    }
    fclose(pCli);
    return -1;
}

Cliente leerRegistro(int p) {
    Cliente obj;
    obj.setDNI(-1);
    /// int pos=0;
    FILE *pCli;
    pCli = fopen("clientes.dat", "rb");
    if (pCli == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return obj;
    }
    fseek(pCli, sizeof obj * p, 0);
    fread(&obj, sizeof obj, 1, pCli);
    /*while(fread(&obj, sizeof obj, 1, pCli)==1){
    if(p==pos){
        fclose(pCli);
        return obj;
    }
    pos++;
    }*/
    fclose(pCli);
    return obj;
}

bool sobreEscribirRegistro(const Cliente reg, int p) {
    /// int pos=0;
    FILE *pCli;
    Cliente obj;
    pCli = fopen("clientes.dat", "rb+");  ///+ agrega al modo lo que le falta
    if (pCli == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }
    fseek(pCli, p * sizeof reg, 0);
    fwrite(&reg, sizeof reg, 1, pCli);
    /*
    if(p==0){
        fwrite(&reg, sizeof reg, 1, pCli);
        fclose(pCli);
        return;
    }

        while(fread(&obj, sizeof obj, 1, pCli)==1){
        if(p==pos+1){
            fseek(pCli,0,1);
            fwrite(&reg, sizeof reg, 1, pCli);
            fclose(pCli);
            return;
        }
        pos++;
        }*/

    fclose(pCli);
    return true;
}

bool bajaLogica() {
    Cliente reg;
    int DNI;
    cout << "INGRESE EL DNI DEL CLIENTE A BORRAR: ";
    cin >> DNI;
    /// Buscar el registro que se quiere eliminar.
    int pos = buscarClientePorDNI(DNI);
    if (pos == -1) {
        cout << "NO EXISTE UN REGISTRO CON ESE DNI" << endl;
        system("pause");
        return false;
    }
    if (pos == -2) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CLIENTES" << endl;
        system("pause");
        return false;
    }
    /// Leer el registro (escribirlo en una variable de memoria)
    reg = leerRegistro(pos);
    /// Cambiar el estado del campo que se utiliza como bandera de la variable
    reg.setEstado(false);
    /// Sobrescribir el registro en la misma posici�n del archivo en que se encontraba.
    return sobreEscribirRegistro(reg, pos);
}

bool modificarEmail() {
    cout << "INGRESE DNI DEL CLIENTE:";
    int DNI;
    cin >> DNI;

    int pos = buscarClientePorDNI(DNI);

    if (pos == -1) {
        cout << "NO EXISTE UN REGISTRO CON ESE DNI" << endl;
        system("pause");
        return false;
    }

    if (pos == -2) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CLIENTES" << endl;
        system("pause");
        return false;
    }

    Cliente reg = leerRegistro(pos);

    cout << "INGRESE NUEVO EMAIL: ";
    char email[25];
    cin >> email;

    reg.setEmail(email);

    return sobreEscribirRegistro(reg, pos);
}

int main() {
    int opc;
    while (true) {
        system("cls");
        cout << "MENU PRINCIPAL" << endl;
        cout << "------------------------" << endl;
        cout << "1 - CARGAR REGISTRO DE CLIENTE EN ARCHIVO" << endl;
        cout << "2 - MOSTRAR ARCHIVO CLIENTES" << endl;
        cout << "3 - BUSCAR CLIENTE EN EL ARCHIVO POR DNI" << endl;
        cout << "4 - ELIMINAR REGISTRO DE CLIENTE EN EL ARCHIVO (BAJA LOGICA)" << endl;
        cout << "5 - MODIFICAR EMAIL DE CLIENTE\n";
        cout << "0 - SALIR DEL PROGRAMA" << endl;
        cout << "------------------------" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                cargaCliente();
                break;
            case 2:
                mostrarClientes();
                break;
            case 3:
                buscarPorDNI();
                break;
            case 4:
                if (bajaLogica())
                    cout << "BAJA REALIZADA" << endl;
                else
                    cout << "NO SE PUDO REALIZAR LA BAJA" << endl;
                break;
            case 5:
                if (modificarEmail())
                    cout << "EMAIL MODIFICADO.\n";
                else
                    cout << "NO SE PUDO MODIFICAR EL EMAIL.\n";
                break;
            case 0:
                return 0;
                break;
        }
        cout << endl;
        system("pause");
    }
    return 0;
}
