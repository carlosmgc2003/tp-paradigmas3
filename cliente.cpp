/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cliente.hpp"

//Constructor de cliente recibe un string n y otro a los pasa a los set de apellido y nombre y un entero dni
Cliente::Cliente(){
    return;
}

Cliente::Cliente(string n,string a,int id){
    setNombre(n);
    setApellido(a);
    setDni(id);
}

//Funcion set del nombre recibe un string, si es mayor a 20 caracteres lo recorta si no lo pasa como esta
void Cliente::setNombre(string n){
    if(n.size() > 20)
        n.resize(20);
    else
        nombre = n;
}

//Funcion set de l apellido recibe un string, si es mayor a 20 caracteres lo recorta, si no lo pasa como esta.
void Cliente::setApellido(string a){
    if(a.size() > 20)
        a.resize(20);
    else
        apellido = a;
}


//Recibe un entero y solo valida que sea mayor a 0
void Cliente::setDni(int id){
    dni = id >= 1000000? id : 0;
}

//Funciones get
int Cliente::getDni() const{
    return dni;
}

string Cliente::getNombre() const{
    return nombre;
}

string Cliente::getApellido() const{
    return apellido;
}
//Fin de funciones get




void Cliente::agregarCuenta(float deposito){
    Cuenta nueva(dni,deposito);
    cartera.push_back(nueva);
}

void Cliente::eliminarCuenta(int id){
    if(id < dni)
        cout<<"Dato incorrecto, no se puede buscar cuenta"<<endl;
    for(int i = 0; i < cartera.size(); i ++){
        if(cartera[i].getIdCuenta() == id){
            cartera.erase(cartera.begin() + i);
            cout<<"Cuenta "<<id<<" eliminada."<<endl;
        }
    }
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
    string aux, nombre, apellido;
    entrada >> aux;
    size_t pos1 = aux.find(',');
    numero = stoi(aux.substr(0,pos1));
    size_t pos2 = aux.find_last_of(',');
    nombre = aux.substr(pos1 + 1,(pos2 - pos1) - 1);
    apellido = aux.substr(pos2 + 1,aux.size());
    instanciaCliente.setDni(numero);
    instanciaCliente.setNombre(nombre);
    instanciaCliente.setApellido(apellido);
    return entrada;
}

Cuenta & Cliente::operator [](const int i){
    return cartera[i];
}

int Cliente::contarCuentas() const{
    return cartera.size();
}