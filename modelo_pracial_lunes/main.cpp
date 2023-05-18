#include <cstring>
#include <iostream>

using namespace std;

#include "parcialm1.h"

class ObraEnEjecucion {
   private:
    char codigoObra[5];
    char direccion[30];
    int provincia;

   public:
    void setCodigoObra(const char *o) {
        strncpy(codigoObra, o, 5);
    }
    void setDireccion(const char *d) {
        strncpy(direccion, d, 30);
    }
    void setProvincia(int p) {
        provincia = p;
    }
    void Mostrar() {
        std::cout << codigoObra << " " << direccion << " " << provincia << '\n';
    }
};

void pregunta1();
void pregunta2();
void mostrarPregunta1();

int main() {
    pregunta1();
    mostrarPregunta1();
    std::cout << '\n';
    pregunta2();
}

void pregunta1() {
    ArchivoObras obras("obras.dat");

    int cantidadObras = obras.contarRegistros();

    Obra obra;
    ObraEnEjecucion obraEjecucion;
    for (int i = 0; i < cantidadObras; ++i) {
        obra = obras.leerRegistro(i);

        if (obra.getEstadoEjecucion() == 3) {
            obraEjecucion.setCodigoObra(obra.getCodigoObra());
            obraEjecucion.setDireccion(obra.getDireccion());
            obraEjecucion.setProvincia(obra.getProvincia());

            FILE *nuevoArchivo = fopen("obrasEnEjecucion.dat", "ab");
            if (nuevoArchivo == NULL) {
                std::cout << "No se pudo abrir el archivo\n";
                return;
            }

            fwrite(&obraEjecucion, sizeof(ObraEnEjecucion), 1, nuevoArchivo);

            fclose(nuevoArchivo);
        }
    }
}

void mostrarPregunta1() {
    FILE *nuevoArchivo = fopen("obrasEnEjecucion.dat", "rb");
    if (nuevoArchivo == NULL) {
        std::cout << "No se pudo abrir el archivo\n";
        return;
    }

    ObraEnEjecucion obra_en_ejecucion;

    while (fread(&obra_en_ejecucion, sizeof(ObraEnEjecucion), 1, nuevoArchivo)) {
        obra_en_ejecucion.Mostrar();
    }

    fclose(nuevoArchivo);
}

void pregunta2() {
    ArchivoProveedor proveedores("proveedores.dat");

    int cantRegistros = proveedores.contarRegistros();

    int proveedoresXprovincia[24] = {};

    Proveedor proveedor;
    for (int i = 0; i < cantRegistros; ++i) {
        proveedor = proveedores.leerRegistro(i);

        ++proveedoresXprovincia[proveedor.getProvincia() - 1];
    }

    int indiceProvinciaMenor = -1;

    for (int i = 0; i < 24; ++i) {
        if (indiceProvinciaMenor == -1 && proveedoresXprovincia[i] != 0) {
            indiceProvinciaMenor = i;

        } else if (proveedoresXprovincia != 0 && proveedoresXprovincia[i] < proveedoresXprovincia[indiceProvinciaMenor]) {
            indiceProvinciaMenor = i;
        }
    }

    std::cout << "Provincia menor cantidad de Proveedores es la provincia: " << indiceProvinciaMenor + 1 << '\n';
}