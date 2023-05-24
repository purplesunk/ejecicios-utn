#include <cstring>
#include <iostream>

using namespace std;

class Cadena {
   private:
    char *cad;
    int tam;

   public:
    Cadena(const char *cadena) {
        tam = strlen(cadena) + 1;
        cad = new char[tam];
        if (cad == NULL) exit(-1);
        strcpy(cad, cadena);
        cad[tam - 1] = '\0';
    }

    void setCadena(const char *cadena) {
        delete cad;
        tam = strlen(cadena) + 1;
        cad = new char[tam];
        if (cad == NULL) exit(-1);
        strcpy(cad, cadena);
        cad[tam - 1] = '\0';
    }

    void Concatenar(const char *cadena) {
        tam += strlen(cadena);

        char *nuevaCadena = new char[tam];
        if (nuevaCadena == NULL) {
            exit(-1);
        }

        strcpy(nuevaCadena, cad);

        delete cad;

        strcat(nuevaCadena, cadena);

        cad = nuevaCadena;

        cad[tam - 1] = '\0';
    }

    int getTam() { return tam; }
    const char *getCad() { return cad; }

    ~Cadena() {
        delete cad;
    }

    void Mostrar() {
        cout << cad;
    }
};

int main() {
    Cadena obj("ESTO ES UNA CADENA");
    obj.Mostrar();
    cout << endl
         << obj.getTam();
    obj.Concatenar(" OTRA CADENA");
    cout << endl;
    cout << obj.getCad();
    cout << endl
         << obj.getTam() << endl;
    system("pause");
    return 0;
}
