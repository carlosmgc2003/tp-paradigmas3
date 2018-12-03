/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cliente.hpp"

//Constructor de cliente por defecto.
Cliente::Cliente()
{
    return;
}



//Setters
//Funcion set del nombre recibe un string, si es mayor a 20 caracteres lo recorta si no lo pasa como esta
void Cliente::setNombre(string n)
{
    if(n.size() > 20)
        n.resize(20);
    nombre = n;
}


//Funcion set del apellido recibe un string, si es mayor a 20 caracteres lo recorta, si no lo pasa como esta.
void Cliente::setApellido(string a)
{
    if(a.size() > 20)
        a.resize(20);
    apellido = a;
}


//Recibe un entero y solo valida que sea mayor a 0. Si no lo es guarda 0
void Cliente::setDni(int id)
{
    dni = id >= 0? id : 0;
}

//Set direccion para no mas de 50 caracteres
void Cliente::setDireccion(string d)
{
    if(d.size() > 50)
        d.resize(50);
    direccion = d;
}


//set telefono de tipo cadena para no mas de quince caracteres.
void Cliente::setTelefono(string t)
{
    if(t.size() > 15)
        t.resize(15);
    telefono = t;
}
//Funciones get
int Cliente::getDni() const
{
    return dni;
}

string Cliente::getNombre() const
{
    return nombre;
}

string Cliente::getApellido() const
{
    return apellido;
}

string Cliente::getDireccion() const
{
    return direccion;
}

string Cliente::getTelefono() const
{
    return telefono;
}
//Fin de funciones get


//Agrega una cuenta nueva al vector de cuentas del cliente.
void Cliente::agregarCuenta(Cuenta nueva)
{
    cartera.push_back(nueva);
}

//Elimina la cuenta asociada al cliente medieante su posición en el vector de clientes
void Cliente::eliminarCuenta(int pos)
{
    cartera.erase(cartera.begin() + pos);
}


//Sobrecarga de salida es la que permite escribir los clientes en el archivo de texto.
ostream & operator << (ostream & salida, Cliente & instanciaCliente)
{
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


//Sobrecarga de entrada, permite leer los clientes del archivo de texto.
istream & operator >> (istream & entrada, Cliente & instanciaCliente)
{
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


//Sobrecarga de corchetes permite acceder a una cuenta determinada del cliente con un indice
Cuenta & Cliente::operator [](const int i)
{
    return cartera[i];
}

//Devuelve la cantidad de cuentas activas que tiene el cliente en memoria!
int Cliente::contarCuentasCliente() const
{
    return cartera.size();
}


//Devuelve el dinero total que suerge de la suma de todos los saldos.
float Cliente::contarDinero() const
{
    float dineroTotal = 0.0;
    if(contarCuentasCliente() > 0)
    {
        for(int i = 0; i < contarCuentasCliente(); i ++)
        {
            dineroTotal += cartera[i].getSaldo();
        }
    }
    return dineroTotal;
}
