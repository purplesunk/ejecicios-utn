///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
///Modificar la clase Fecha para que en la carga se utilicen los m�todos set() definidos.
///Hacer en los sets las siguientes validaciones:
///el d�a debe contener valores enteros entre 1 y 31.
///el mes debe contener valores enteros entre 1 y 12.
///el anio debe contener valores positivos mayores a 1900.

///En caso que se ingrese un valor fuera de esos rangos, la propiedad debe recibir como valor el 0;

///para representar una fecha necesito dia, mes y anio

using namespace std;

class Fecha{
    private:///s�lo permite que sean accesibles dentro de la propia clase. Desde fuera no se van a poder manipular.
        int dia, mes, anio;///propiedades, atributos o variables de la clase
    public:///comportamiento. Se establece mediante el desarrollo de los m�todos, que son las funciones de la clase
        void Cargar(){
            int x{};
            cout<<"DIA: ";
            cin>>x;
            setDia(x);
            cout<<"MES: ";
            cin>>x;
            setMes(x);
            cout<<"ANIO: ";
            cin>>x;
            setAnio(x);
        }
        void Mostrar();

        ///set: para asignar valores a cada propiedad
        void setDia(int x) {
            if (x < 1 || x > 31) {
                dia = 0;
            } else {
                dia = x;
            }
        }
        void setMes(int x) {
            if (x < 1 || x > 12) {
                mes = 0;
            } else {
                mes=x;
            }
        }
        void setAnio(int x) {
            if (x < 1901) {
                anio = 0;
            } else {
                anio=x;
            }
        }


        ///get: para que el exterior se entere de los valores de cada propiedad
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

};


void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main(){
    Fecha diaActual;
    int x;


    diaActual.Cargar();


	cout<<endl;
	diaActual.Mostrar();

    std::cin.get();
	return 0;
}
