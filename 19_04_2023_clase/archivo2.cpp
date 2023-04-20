/// Ejercicio: modificar el programa con un men� con 2 funciones: 1 para agregar 1 registro, y otra para mostrar todos los registros
/// Agregar la opci�n de men� Mostrar por DNI, que llame a una funci�n y muestre el cliente con el DNI que se ingres� por teclado.
///  Si no hay un cliente con ese DNI informarlo.
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

   public:
    Fecha getFechaNacimiento() {
        return fechaNacimiento;
    }

    int getDNI() { return DNI; }
    const char *getNombre() { return nombre; }
    const char *getApellido() { return apellido; }
    const char *getEmail() { return email; }
    const char *getTelefono() { return telefono; }

    void setDNI(const int d) { DNI = d; }
    void setFechaNacimiento(Fecha f) { fechaNacimiento = f; }
    void setNombre(const char *n) { strcpy(nombre, n); }
    void setApellido(const char *a) { strcpy(apellido, a); }
    void setEmail(const char *e) { strcpy(email, e); }
    void setTelefono(const char *t) { strcpy(telefono, t); }

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
        cout << "CUIT " << CUIT << endl;
        cout << "FECHA DE LA PRIMERA COMPRA O INGRESO " << endl;
        ingreso.Mostrar();
        Persona::Mostrar();
    }

    void modificarDNI(int d) {
        DNI = d;
    }

    int getDNI() {
        return Persona::getDNI();
    }
};

int mostrarRegistros() {
    FILE *archivo = fopen("clientes.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo crear el archivo.\n";
        return -1;
    }

    Cliente obj;
    while (fread(&obj, sizeof(obj), 1, archivo) == 1) {
        obj.Mostrar();
        cout << '\n';
    }

    fclose(archivo);
    return 0;
}

int buscarDNI() {
    cout << "Ingrese número de dni a buscar: ";

    int dni;
    cin >> dni;

    FILE *archivo = fopen("clientes.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo crear el archivo.\n";
        return -1;
    }

    Cliente obj;
    while (fread(&obj, sizeof(obj), 1, archivo) == 1) {
        if (obj.getDNI() == dni) {
            obj.Mostrar();
            cout << '\n';
            break;
        }
    }

    fclose(archivo);
    return 0;
}

int agregarRegistro() {
    FILE *archivo = fopen("clientes.dat", "ab");
    if (archivo == NULL) {
        cout << "No se pudo crear el archivo.\n";
        return -1;
    }

    Cliente obj;
    obj.Cargar();

    if (fwrite(&obj, sizeof(obj), 1, archivo) == 0) {
        cout << "No se pudo registrar al cliente.\n";
    }
    fclose(archivo);
    return 0;
}

int main() {
    int opcion = 0;
    while (true) {
        cout << "1. Mostrar registros\n";
        cout << "2. Cargar registro\n";
        cout << "3. Buscar por DNI\n";
        cout << "0. Salir\n";

        cin >> opcion;

        switch (opcion) {
            case 1:
                if (mostrarRegistros() == -1) {
                    return -1;
                }
                break;
            case 2:
                if (agregarRegistro() == -1) {
                    return -1;
                }
                break;
            case 3:
                if (buscarDNI() == -1) {
                    return -1;
                }
                break;
            case 0:
                return 0;
                break;
            default:
                cout << "Opción no existe.\n";
                break;
        }
    }
}
