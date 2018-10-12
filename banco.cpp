/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "banco.h"
using namespace std;


int Cuenta::numeroDeOrden = 0;

Cuenta::Cuenta(string id,float s){
    nuevaCuenta = TRUE;
    saldo = s >= 0? s : 0.0;
    setIdCuenta(id);
    setCuentaIniciada();
    numeroDeOrden ++;
}

Cuenta::Cuenta(string id){
    setIdCuenta(id);
    saldo = 0.0;
    nuevaCuenta = TRUE;
    numeroDeOrden ++;
}
Cuenta::Cuenta(){
    saldo = 0.0;
    nuevaCuenta = TRUE;
    numeroDeOrden ++;
}

Cuenta::~Cuenta(){
    numeroDeOrden --;
}
float Cuenta::getSaldo() const{
    return saldo;
}

string Cuenta::getIdCuenta() const{
    return idCuenta;
}

void Cuenta::operator +=(float credito){
    if(credito >= 0)
        saldo += credito;
}

void Cuenta::operator -=(float debito){
    if(debito >= 0 && saldo - debito >= 0)//Corregir!!!
        saldo -= debito;
    else
        cout<<"Saldo insuficiente"<<endl;
}

void Cuenta::setIdCuenta(string id){
    if(nuevaCuenta == TRUE){
        idCuenta = to_string(numeroDeOrden);
        idCuenta.append(id);
        setCuentaIniciada();
    }
}

void Cuenta::setSaldo(float s){
    if(nuevaCuenta == TRUE){
        saldo = s;
    }
}

void Cuenta::setCuentaIniciada(){
    nuevaCuenta = FALSE;
}

ostream & operator << (ostream & salida, Cuenta & cuenta){
    salida << cuenta.getIdCuenta() <<","<< cuenta.getSaldo();
    return salida;
}

istream & operator >> (istream & entrada, Cuenta & cuenta){
    string id;
    float s;
    entrada >> id;
    entrada >> s;
    if(cuenta.nuevaCuenta == TRUE){
        cuenta.setIdCuenta(id);
        cuenta.setSaldo(s);
        cuenta.setCuentaIniciada();
    }
    return entrada;
}

Cliente::Cliente(string n,string a,int id){
    setNombre(n);
    setApellido(a);
    setDni(id);
}

void Cliente::setNombre(string n){
    if(n.size() > 20)
        n.resize(20);
    else
        nombre = n;
}

void Cliente::setApellido(string a){
    if(a.size() > 20)
        a.resize(20);
    else
        apellido = a;
}

void Cliente::setDni(int id){
    dni = id >= 1000000? id : 0;
}

int Cliente::getDni() const{
    return dni;
}

string Cliente::getNombre() const{
    return nombre;
}

string Cliente::getApellido() const{
    return apellido;
}

void Cliente::agregarCuenta(float){
    string id = to_string(dni);
    Cuenta nueva(id);
    cartera.push_back(nueva);
}

ostream & operator << (ostream & salida, Cliente & instanciaCliente){
    salida << instanciaCliente.getDni();
    salida << ",";
    salida << instanciaCliente.getNombre();
    salida << ",";
    salida << instanciaCliente.getApellido();
    return salida;
}

istream & operator >> (istream & entrada, Cliente & instanciaCliente){
    int numero;
    string cadena1, cadena2;
    char colon;
    entrada >> numero >> colon >> cadena1 >> colon >> cadena2 >> colon;
    instanciaCliente.setDni(numero);
    instanciaCliente.setApellido(cadena2);
    instanciaCliente.setApellido(cadena1);
    return entrada;
}

Banco::Banco(){
    clientes.open("clientes.txt", fstream::out | fstream::in);
    cuentas.open("cuentas.txt", fstream::out | fstream::in );
    movimientos.open("movimientos.txt", fstream::out | fstream::in);
}

Banco::~Banco(){
    clientes.close();
    cuentas.close();
    movimientos.close();
}



void Banco::escribirCliente(Cliente instanciaCliente){
    clientes << instanciaCliente << endl;
}

void Banco::escribirCuenta(Cuenta instanciaCuenta){
    cuentas << instanciaCuenta << endl;
}

void Banco::leerArchivos(){
    if(clientes){
        clientes.seekg(0,clientes.end);//desplaza el cabezal al final del archivo.
        int largoarchivo = clientes.tellg();//da la posicion del final.
        clientes.seekg(0,clientes.beg);// desplaza el cabezal al principio del archivo nuevamente.
        char * bufferClientes = new char[largoarchivo];//genera un buffer para guardar el contenido "entero" del archivo
        cout<<"Se leeran: "<<largoarchivo<<" bytes."<<endl;
        clientes.read(bufferClientes,largoarchivo);
        if(clientes)
            cout<<"El archivo ha sido leido correctamente"<<endl;
        else
            cout<<"error: solo"<<clientes.gcount()<<" han sido leidos!"<<endl;
        //aca debe agregarse la creacion de las instancias de cliente.
        string contenidoClientes(bufferClientes);
        cout<<"Lo leido fue: "<<contenidoClientes<<endl;
        delete[] bufferClientes;//se libera la memora asignada para el buffer.
        cuentas.seekg(0,cuentas.end);
        largoarchivo = cuentas.tellg();
        cuentas.seekg(0,cuentas.beg);
        char * bufferCuentas = new char[largoarchivo];
        cout<<"Se leeran: "<<largoarchivo<<" bytes."<<endl;
        cuentas.read(bufferCuentas,largoarchivo);
        if(cuentas)
            cout<<"El archivo ha sido leido correctamente"<<endl;
        else
            cout<<"error: solo"<<cuentas.gcount()<<" han sido leidos!"<<endl;
        //aca debe agregarse la creacion de las instancias de cuenta.
        string contenidoCuentas(bufferCuentas);
        cout<<"Lo leido fue: "<<contenidoCuentas<<endl;
        delete[] bufferCuentas;
    }

}
