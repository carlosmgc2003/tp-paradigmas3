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

Cliente::Cliente(string n,string a,int id, string d, string t){
    setNombre(n);
    setApellido(a);
    setDni(id);
    setDireccion(d);
    setTelefono(t);
}

//Setters
//Funcion set del nombre recibe un string, si es mayor a 20 caracteres lo recorta si no lo pasa como esta
void Cliente::setNombre(string n){
    if(n.size() > 20)
        n.resize(20);
    nombre = n;
}


//Funcion set de l apellido recibe un string, si es mayor a 20 caracteres lo recorta, si no lo pasa como esta.
void Cliente::setApellido(string a){
    if(a.size() > 20)
        a.resize(20);
    apellido = a;
}


//Recibe un entero y solo valida que sea mayor a 0
void Cliente::setDni(int id){
    dni = id >= 0? id : 0;
}

void Cliente::setDireccion(string d){
    if(d.size() > 50)
        d.resize(50);
    direccion = d;
}

void Cliente::setTelefono(string t){
    if(t.size() > 15)
        t.resize(15);
    telefono = t;
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

string Cliente::getDireccion() const{
    return direccion;
}

string Cliente::getTelefono() const{
    return telefono;
}
//Fin de funciones get



/*Metodo candidato a ser eliminado
void Cliente::agregarCuenta(float deposito){
    Cuenta nueva(dni,deposito);
    cartera.push_back(nueva);
}*/

void Cliente::agregarCuenta(Cuenta nueva){
    cartera.push_back(nueva);
}

void Cliente::eliminarCuenta(int id){
    cartera.erase(cartera.begin() + id);
}

ostream & operator << (ostream & salida, Cliente & instanciaCliente){
    salida << instanciaCliente.getDni();
    salida << ",";
    salida << instanciaCliente.getNombre();
    salida << ",";
    salida << instanciaCliente.getApellido();
    salida << ",";
    salida << instanciaCliente.getDireccion();
    salida << ",";
    salida << instanciaCliente.getTelefono();
    return salida;
}

istream & operator >> (istream & entrada, Cliente & instanciaCliente){
    int numero;
    string aux, nombre, apellido, direccion, telefono;
    entrada >> aux;
    size_t pos = aux.find(',');
    numero = stoi(aux.substr(0,pos));
    aux = aux.substr(pos + 1,aux.size() - (pos + 1));
    pos = aux.find(',');
    nombre = aux.substr(0,pos);
    aux = aux.substr(pos + 1,aux.size() - (pos + 1));
    pos = aux.find(',');
    apellido = aux.substr(0,pos);
    aux = aux.substr(pos + 1,aux.size() - (pos + 1));
    pos = aux.find(',');
    direccion = aux.substr(0,pos);
    aux = aux.substr(pos + 1,aux.size() - (pos + 1));
    pos = aux.find(',');
    telefono = aux.substr(0,pos);
    instanciaCliente.setDni(numero);
    instanciaCliente.setNombre(nombre);
    instanciaCliente.setApellido(apellido);
    instanciaCliente.setDireccion(direccion);
    instanciaCliente.setTelefono(telefono);
    return entrada;
}

Cuenta & Cliente::operator [](const int i){
    return cartera[i];
}

int Cliente::contarCuentasCliente() const{
    return cartera.size();
}

float Cliente::contarDinero() const{
    float dineroTotal = 0.0;
    if(contarCuentasCliente() > 0){
        for(int i = 0; i < contarCuentasCliente(); i ++){
            dineroTotal += cartera[i].getSaldo();
        }
    }
    return dineroTotal;
}
