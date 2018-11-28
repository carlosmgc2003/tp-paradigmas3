/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cuenta.hpp"
#include <iomanip>
#define TRUE 1
#define FALSE 0

using namespace std;



Cuenta::Cuenta(int id,int tipo,float s)
{
    nuevaCuenta = TRUE;
    tipoCuenta = tipo;
    saldo = s >= 0.0? s : 0.0;
    setdniDuenio(id);
    setCuentaIniciada();
    numeroUnico = generadorNumeros;
    generadorNumeros ++;
}

Cuenta::Cuenta(int id,int tipo)
{
    tipoCuenta = tipo;
    saldo = 0.0;
    nuevaCuenta = TRUE;
    generadorNumeros ++;
}

Cuenta::Cuenta(int id,int NumUni,int tipo)
{
    tipoCuenta = tipo;
    dniDuenio = id;
    numeroUnico = NumUni;
    saldo = 0.0;
    setCuentaIniciada();
    generadorNumeros ++;
}
Cuenta::Cuenta()
{
    nuevaCuenta = TRUE;

}

Cuenta::~Cuenta()
{
    return;
}

//Getters
float Cuenta::getSaldo() const
{
    return saldo;
}

int Cuenta::getdniDuenio() const
{
    return dniDuenio;
}

int Cuenta::gettipoCuenta() const
{
    return tipoCuenta;
}

int Cuenta::getnumeroUnico() const
{
    return numeroUnico;
}
//Fin de Getter

//Sobrecargas de operadores para debito y credito
void Cuenta::operator +=(float credito)
{
    saldo += credito;
}

void Cuenta::acreditar(float credito)
{
    if(credito >= 0.0)
        saldo += credito;
}

void Cuenta::debitar(float debito)
{
    if(debito >= 0.0)
    {
        if(tipoCuenta == CA)
            saldo = (saldo - debito) >= 0? (saldo - debito): saldo;
        else
            saldo -= debito;
    }
}

void Cuenta::operator -=(float debito)
{
    if(debito >= 0.0)
    {
        if(tipoCuenta == CA)
            saldo = (saldo - debito) >= 0? (saldo - debito): saldo;
        else
            saldo -= debito;
    }
}
//Fin de sobrecarga de operadores y credito y debito

//Setters
void Cuenta::setdniDuenio(int id)
{
    if(nuevaCuenta == TRUE)
        dniDuenio = id;
}

void Cuenta::setSaldo(float s)
{
    if(nuevaCuenta == TRUE)
        saldo = s;
}

void Cuenta::setCuentaIniciada()
{
    nuevaCuenta = FALSE;
}

void Cuenta::setnumeroUnico(int num)
{
    numeroUnico = num;
}

void Cuenta::settipoCuenta(int tipo)
{
    if(tipo == CA)
        tipoCuenta = CA;
    else
        tipoCuenta = CC;
}

ostream & operator << (ostream & salida, Cuenta & cuenta)
{
    salida << cuenta.getdniDuenio();
    salida <<",";
    salida << cuenta.getnumeroUnico();
    salida <<",";
    salida << cuenta.gettipoCuenta();
    salida <<",";
    salida << fixed<<setprecision(2)<< cuenta.getSaldo();
    return salida;
}

istream & operator >> (istream & entrada, Cuenta & cuenta)
{
    int numDniDuenio, numUnico;
    int tipo;
    float numeroParaSaldo;
    string aux;
    //Tomo la entrada y la guardo entera en aux
    entrada >> aux;
    //Hallo la primer ,
    size_t pos = aux.find(',');
    //Convierto el primer numero en el DNI
    numDniDuenio = stoi(aux.substr(0,pos));
    //Lo guardo en la instancia de cuenta
    cuenta.setdniDuenio(numDniDuenio);
    //Recorto la subcadena de lo que sigue y lo guardo en aux;
    aux = aux.substr(pos + 1,aux.size() - (pos + 1));
    //Busco la siguiente ,
    pos = aux.find(',');
    //Convierto el segundo numero en numeroUnico de cuenta
    numUnico = stoi(aux.substr(0,pos));
    //Lo guardo en al instancia de cuenta
    cuenta.setnumeroUnico(numUnico);
    //Recorto la subcadena de lo que sigue y lo guardo en aux;
    aux = aux.substr(pos + 1,aux.size() - (pos + 1));
    //Busco la primero ,
    pos = aux.find(',');
    //Encuentro el tipo
    tipo = stoi(aux.substr(0,pos));
    //Lo guardo en la instancia de cliente
    cuenta.settipoCuenta(tipo);
    numeroParaSaldo = stof(aux.substr(pos + 1,aux.size() - (pos + 1)));
    cuenta.setSaldo(numeroParaSaldo);
    cuenta.setCuentaIniciada();
    return entrada;
}

void Cuenta::inicializarGenerador(int mayor)
{
    generadorNumeros = mayor;
}

bool Cuenta::autorizarExtraccion(float cantidad)
{
    if(tipoCuenta == 0)
    {
        if(saldo - cantidad >= 0)
            return TRUE;
        else
            return FALSE;
    }
}
