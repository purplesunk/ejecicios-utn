#ifndef PARCIAL2_H_INCLUDED
#define PARCIAL2_H_INCLUDED

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


class Fecha{
private:
    int dia,mes, anio;
public:
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

class Taller{
private:
    int codigoTaller;
    char nombre[30];
    int provincia;
    char gerente[30];
    int categoria;
    bool estado;
public:
    int getCodigoTaller(){return codigoTaller;}
    const char *getNombre(){return nombre;}
    int getProvincia(){return provincia;};
    const char* getGerente(){return gerente;};
    int getCategoria(){return categoria;};
    bool getEstado(){return estado;};
};

class Cliente{
private:
    int DNI;
    char nombre[30];
    int medioPago;
    int tipoCliente;
    int edad;
    bool estado;
public:
    int getDNI(){return DNI;}
    const char *getNombre(){return nombre;}
    int getMedioPago(){return medioPago;}
    int getTipoCliente(){return tipoCliente;}
    int getEdad(){return edad;};
    bool getEstado(){return estado;}
};

class Reparacion{
private:
    int codigoTaller;
    int DNI;
    Fecha fechaReparacion;
    int tipoReparacion;
    float importe;
    bool estado;
public:
    int getCodigoTaller(){return codigoTaller;}
    int getDNI(){return DNI;}
    Fecha getFechaReparacion(){return fechaReparacion;}
    int getTipoReparacion(){return tipoReparacion;}
    float getImporte(){return importe;}
    bool getEstado(){return estado;}
};


class ArchivoTalleres{
private:
    char nombre[30];
public:
    ArchivoTalleres(const char *n){
        strcpy(nombre, n);
    }
    Taller leerRegistro(int pos){
        Taller reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Taller);
    }

};

class ArchivoClientes{
private:
    char nombre[30];
public:
    ArchivoClientes(const char *n){
        strcpy(nombre, n);
    }
    Cliente leerRegistro(int pos){
        Cliente reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Cliente);
    }

};

class ArchivoReparaciones{
private:
    char nombre[30];
public:
    ArchivoReparaciones(const char *n){
        strcpy(nombre, n);
    }
    Reparacion leerRegistro(int pos){
        Reparacion reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Reparacion);
    }
};

#endif // PARCIAL2_H_INCLUDED
