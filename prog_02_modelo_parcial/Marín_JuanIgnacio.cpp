#include <cstring>
#include <iostream>

using namespace std;

#include "parcialm1.h"

class materialElectricidad {
   private:
    int codigo;
    char nombre[30];
    char marca[30];

   public:
    void setCodigo(int cod) {
        codigo = cod;
    }
    void setNombre(const char *m) {
        strcpy(nombre, m);
    }
    void setMarca(const char *m) {
        strcpy(marca, m);
    }

    void mostrar() {
        cout << codigo << " " << nombre << " " << marca << '\n';
    }
};

void generarArchivoElectricidad();
void estadoEjecucionMasObras();
void mostrarArchivoElectricidad();
void adicionalUno();
void adicionalDos();
void adicional3();
void adicional4();
void adicional5();

int main() {
    generarArchivoElectricidad();
    mostrarArchivoElectricidad();
    cout << '\n';
    estadoEjecucionMasObras();
    cout << '\n';
    adicionalUno();
    cout << '\n';
    adicionalDos();
    cout << '\n';
    adicional3();
    cout << '\n';
    adicional4();
    cout << '\n';
    adicional5();
    cout << '\n';
    return 0;
}

void estadoEjecucionMasObras() {
    ArchivoObras archivoObras("obras.dat");

    int estadoEjecucion[5] = {};

    int cantObras = archivoObras.contarRegistros();

    if (cantObras == 0) {
        cout << "No hay obras para leer. Archivo vacío.\n";
        return;
    } else if (cantObras == -1) {
        cout << "Error al abrir el archivo: obras.dat\n";
        return;
    }

    Obra obra;

    for (int i = 0; i < cantObras; ++i) {
        obra = archivoObras.leerRegistro(i);

        ++estadoEjecucion[obra.getEstadoEjecucion() - 1];
    }

    int max = 0;
    for (int i = 0; i < 5; ++i) {
        if (estadoEjecucion[i] > estadoEjecucion[max]) {
            max = i;
        }
    }

    cout << "Estado de ejecución con más obras: " << max + 1 << '\n';
}

void generarArchivoElectricidad() {
    ArchivoMaterial archivoMateriales("materiales.dat");

    int cantMateriales = archivoMateriales.contarRegistros();

    if (cantMateriales == 0) {
        cout << "No hay materiales para leer. Archivo vacío.\n";
        return;
    } else if (cantMateriales == -1) {
        cout << "Error al abrir el archivo: materiales.dat\n";
        return;
    }

    materialElectricidad matElectricidad;

    for (int i = 0; i < cantMateriales; ++i) {
        Material material = archivoMateriales.leerRegistro(i);

        if (material.getActivo() && material.getTipo() == 6) {
            matElectricidad.setCodigo(material.getCodigoMaterial());
            matElectricidad.setNombre(material.getNombre());
            matElectricidad.setMarca(material.getMarca());

            FILE *file = fopen("electricos.dat", "ab");
            if (file == NULL) {
                return;
            }

            fwrite(&matElectricidad, sizeof(matElectricidad), 1, file);

            fclose(file);
        }
    }
}

void mostrarArchivoElectricidad() {
    FILE *file = fopen("electricos.dat", "rb");
    if (file == NULL) {
        return;
    }

    materialElectricidad matElectricidad;

    while (fread(&matElectricidad, sizeof(materialElectricidad), 1, file)) {
        matElectricidad.mostrar();
    }
}

void adicionalUno() {
    ArchivoMaterial materiales("materiales.dat");
    ArchivoCompra compras("compras.dat");

    int cantMateriales = materiales.contarRegistros();
    int cantCompras = compras.contarRegistros();

    if (cantMateriales == 0 || cantCompras == 0) {
        cout << "Archivo/s vacío/s.\n";
        return;
    } else if (cantMateriales == -1 || cantCompras == -1) {
        cout << "Error al abrir los archivos.\n";
        return;
    }

    Compra compra;
    Material material;
    int cantComprasRealizadas = 0;

    for (int i = 0; i < cantMateriales; ++i) {
        cantComprasRealizadas = 0;
        material = materiales.leerRegistro(i);
        for (int j = 0; j < cantCompras; ++j) {
            compra = compras.leerRegistro(j);
            if (material.getCodigoMaterial() == compra.getCodigoMaterial()) {
                ++cantComprasRealizadas;
            }
        }
        cout << "Cantidad de compras de material " << material.getCodigoMaterial();
        cout << ": " << cantComprasRealizadas << '\n';
    }
}

void adicionalDos() {
    ArchivoProveedor proveedores("proveedores.dat");
    ArchivoCompra compras("compras.dat");

    int cantProveedores = proveedores.contarRegistros();
    int cantCompras = compras.contarRegistros();

    if (cantProveedores == 0 || cantCompras == 0) {
        cout << "Archivo/s vacío/s.\n";
        return;
    } else if (cantProveedores == -1 || cantCompras == -1) {
        cout << "Error al abrir los archivos.\n";
        return;
    }

    Compra compra;
    Proveedor proveedor;

    float importeMax = 0;
    float proveedorMax = 0;

    float importe = 0;

    for (int i = 0; i < cantProveedores; ++i) {
        proveedor = proveedores.leerRegistro(i);

        for (int j = 0; j < cantCompras; ++j) {
            compra = compras.leerRegistro(j);
            if (proveedor.getNumeroProveedor() == compra.getNumeroproveedor()) {
                importe += compra.getImporte();
            }
        }

        if (importe > importeMax) {
            importeMax = importe;
            proveedorMax = proveedor.getNumeroProveedor();
        }
    }

    cout << "El proveedor con mayor importe recaudado es el " << proveedorMax << '\n';
}

void adicional3() {
    ArchivoProveedor proveedores("proveedores.dat");
    ArchivoCompra compras("compras.dat");

    int cantProveedores = proveedores.contarRegistros();
    int cantCompras = compras.contarRegistros();

    if (cantProveedores == 0 || cantCompras == 0) {
        cout << "Archivo/s vacío/s.\n";
        return;
    } else if (cantProveedores == -1 || cantCompras == -1) {
        cout << "Error al abrir los archivos.\n";
        return;
    }

    Compra compra;
    Proveedor proveedor;

    int cantVentas = 0;
    int anioCompra = 0;

    cout << "Proveedores que no realizaron ventas el año pasado: \n";
    for (int i = 0; i < cantProveedores; ++i) {
        proveedor = proveedores.leerRegistro(i);

        cantVentas = 0;

        for (int j = 0; j < cantCompras; ++j) {
            compra = compras.leerRegistro(j);
            anioCompra = compra.getFechaCompra().getAnio();
            if (proveedor.getNumeroProveedor() == compra.getNumeroproveedor() && anioCompra == 2022) {
                ++cantVentas;
                break;
            }
        }

        if (cantVentas == 0) {
            cout << proveedor.getNumeroProveedor() << '\n';
        }
    }
}

void adicional4() {
    ArchivoCompra compras("compras.dat");
    ArchivoMaterial materiales("materiales.dat");
    ArchivoObras obras("obras.dat");

    int cantCompras = compras.contarRegistros();
    int cantMateriales = materiales.contarRegistros();
    int cantObras = obras.contarRegistros();

    if (cantObras == 0 || cantCompras == 0) {
        cout << "Archivo/s vacío/s.\n";
        return;
    } else if (cantObras == -1 || cantCompras == -1) {
        cout << "Error al abrir los archivos.\n";
        return;
    }

    Compra compra;
    Obra obra;
    Material material;

    float gastoObraGruesa = 0;

    cout << "Gasto en obra gruesa por obra: \n";
    for (int i = 0; i < cantObras; ++i) {
        gastoObraGruesa = 0;
        obra = obras.leerRegistro(i);

        for (int j = 0; j < cantCompras; ++j) {
            compra = compras.leerRegistro(j);

            if (strcmp(obra.getCodigoObra(), compra.getCodigoObra()) == 0) {
                for (int x = 0; x < cantMateriales; ++x) {
                    material = materiales.leerRegistro(x);

                    if (compra.getCodigoMaterial() == material.getCodigoMaterial() && material.getTipo() == 1) {
                        gastoObraGruesa += compra.getImporte();
                    }
                }
            }
        }

        cout << "Obra " << obra.getCodigoObra() << ": " << gastoObraGruesa << '\n';
    }
}

void adicional5() {
    ArchivoProveedor proveedores("proveedores.dat");

    int cantProveedores = proveedores.contarRegistros();

    if (cantProveedores == 0 || cantProveedores == -1) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    int cantProvincias[24] = {};
    Proveedor proveedor;

    for (int i = 0; i < cantProveedores; ++i) {
        proveedor = proveedores.leerRegistro(i);
        ++cantProvincias[proveedor.getProvincia() - 1];
    }

    cout << "Provincias con más de 22 proveedores: \n";
    for (int i = 0; i < 24; ++i) {
        if (cantProvincias[i] > 22) {
            cout << i + 1 << '\n';
        }
    }
}