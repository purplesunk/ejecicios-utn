///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;
///CLASES NECESARIAS

class Ciudad{
/*Código de ciudad
nombre
código de provincia
estado*/

};

class Medicion{
/*Código de ciudad
 visibilidad,
 temperatura,
 fecha (día, mes y año).
 estado*/

};

class MedicionPromedio{
/*
Código de ciudad
nombre
promedio
estado
*/
};


class ArchivoCiudades{
private:
    char nombre[30];
public:
    ArchivoCiudades(){}
    int contarRegistros(){}
    Ciudad leerRegistro(int pos){}

};

class ArchivoMediciones{
private:
    char nombre[30];
public:
    ArchivoMediciones(){}
    int contarRegistros(){}
    Medicion leerRegistro(int pos){}

};

class ArchivoMedicionesPromedio{
private:
    char nombre[30];
public:
    ArchivoMedicionesPromedio(){}
    int contarRegistros(){}
    MedicionPromedio leerRegistro(int pos){}
    bool agregarRegistro(MedicionPromedio reg){};

};

void puntoA();
void puntoB();

int main(){
    puntoA();
    puntoB();
	cout<<endl;
	system("pause");
	return 0;
}

///hacer función para el promedio!!!!
float promedioMedicionCiudad(int cod){
    Medicion obj;
    ArchivoMediciones archiMedicion("mediciones.dat");
    int cantR=archiMedicion.contarRegistros();
    float promedio;
    int cantMediciones=0, sumaMediciones=0;
    for(int i=0;i<cantR;i++){
        obj=archiMedicion.leerRegistro(i);
        if(obj.getEstado()==true && obj.getCodigoCiudad()==cod){
            cantMediciones++;
            sumaMediciones+=obj.getVisibilidad();
        }
    }
    if(cantMediones!=0){
        promedio=(float)sumaMediciones/cantMediciones;
    }
    else{
        promedio=-1;///se pone -1 para los casos que no hubo mediciones
    }
    return promedio;
}

void puntoA(){
    Ciudad obj;
    MedicionPromedio aux;

    ArchivoCiudad archiCiudad("ciudades.dat");
    ArchivoMedicionesPromedio archiNuevo("promedios.dat");


    int cant=archiCiudad.contarRegistros();
    for(int i=0;i<cant;i++){
        obj=archiCiudad.leerRegistro(i);
        if(obj.getEstado()==true){
            aux.setCodigoCiudad(obj.getCodigoCiudad());
            aux.setNombre(obj.getNombre());
            aux.setPromedio(promedioMedicionCiudad(obj.getCodigoCiudad()));
            aux.setEstado(true);
            archiNuevo.agregarRegistro(aux);
        }
    }
}

void mostrarResultado(int mat[6][31], int filas, int columnas){
    int i, j;
    for(i=0;i<filas;i++){
        cout<<"PARA EL GRADO DE VISIBILIDAD "<<i<<" "<<" SE REGISTRARON LAS SIGUIENTES CANTIDAD DE MEDICIONES "<<endl;
        for(j=0;j<columnas;j++){
            cout<<"DIA "<<j+1<<"\t"<<mat[i][j]<<endl;
        }
        system("pause");
        system("cls");
    }

}


void puntoB(){
    int matMediciones[6][31]={0};
    Medicion obj;
    ArchivoMediciones archiMedicion("mediciones.dat");
    int cantR=archiMedicion.contarRegistros();

    for(int i=0;i<cantR;i++){
        obj=archiMedicion.leerRegistro(i);
        if(obj.getEstado()==true && obj.getFecha().getMes()==5){
            matMediciones[obj.getVisibilidad()][obj.getFecha().getDia()-1]++;
        }
    }
    mostrarResultado(matMediciones, 6, 31);
}
