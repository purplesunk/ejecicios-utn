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

#include "archivoCliente.h"
#include "funciones.h"

int main() {
    ArchivoCliente archivo("cliente.dat");
    int opc;
    while (true) {
        system("cls");
        cout << "MENU PRINCIPAL" << endl;
        cout << "------------------------" << endl;
        cout << "1 - CARGAR REGISTRO DE CLIENTE EN ARCHIVO" << endl;
        cout << "2 - MOSTRAR ARCHIVO CLIENTES" << endl;
        cout << "3 - BUSCAR CLIENTE EN EL ARCHIVO POR DNI" << endl;
        cout << "4 - MOSTRAR CLIENTES POR APELLIDO EMPEZADO EN..." << endl;
        cout << "5 - DAR DE BAJA CLIENTE (BAJA LOGICA)" << endl;
        cout << "6 - Modificar email de cliente." << endl;
        cout << "0 - SALIR DEL PROGRAMA" << endl;
        cout << "------------------------" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        ignoreLine();
        system("cls");
        switch (opc) {
            case 1:
                archivo.agregarRegistro();
                break;
            case 2:
                archivo.mostrarRegistros();
                break;
            case 3:
                archivo.buscarPorDNI();
                break;
            case 4:
                mostrarPorApellido();
                break;
            case 5:
                if (archivo.bajaLogica()) {
                    cout << "CLIENTE DADO DE BAJA CORRECTAMENTE.\n";
                } else {
                    cout << "NO SE PUDO REALIZAR LA BAJA.\n";
                }
                break;
            case 6:
                if (modificarEmail()) {
                    cout << "Email modificado correctamente.\n";
                } else {
                    cout << "No se pudo realizar la modificación.\n";
                }
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
