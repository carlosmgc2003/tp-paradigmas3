/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   banco.h
 * Author: carlos
 *
 * Created on 3 de octubre de 2018, 04:34
 */

#ifndef BANCO_H
#define BANCO_H
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
enum value {FALSE,TRUE};

class Cuenta{
public:
    //Constructores
    Cuenta(string,float);//Constructor con id y saldo, deja nuevaCuenta en False.
    Cuenta(string);/** Constructor solo con id. Deja nuevaCuenta en false, por lo cual
                 * cualquier modificacion futura del saldo debe ser usado creditos y
                 * debitos o los operadores sobrecargados.***/
    Cuenta();/** Constructor sin parametros. Usar con precaucion solo cuando se realice
              * carga de archivos. Esta a prueba**/
    //Destructores
    ~Cuenta();
    //Getters comunes... nada que aclarar
    float getSaldo() const;
    string getIdCuenta() const;
    //Setters
    void setSaldo(float);//Setter del saldo, se puede usar solo cuando nuevaCuenta == TRUE OJO!!!
    void setIdCuenta(string);//Setter de ID se puede usar solo cuando nuevaCuenta == TRUE. Pasa nuevaCuenta a FALSE
    void setCuentaIniciada();//Sirve como gatillo para bajar la cuenta del modo "promiscuo" nuevaCuenta
    //Sobrecarga de operadores
    friend ostream & operator<<(ostream &,Cuenta &);//Sobrecarga de salida; se usara para escribir en archivo.
    friend istream & operator>>(istream &,Cuenta &);//Sobrecarga de entrada; se usara para leer archivo
    //TODO: estos operadores deben escribir ESTOS movimientos en el archivo movimientos.txt
    void operator += (float);//Sobrecarga de incremento se usara para creditos. Todavia con pocas reglas.
    void operator -= (float);//Sobrecarga de desincrementar se usara para dbitos. Todavia solo valida signo del saldo.
    static int numeroDeOrden;
private:
    float saldo;//Saldo en pesos de la cuenta
    string idCuenta;// ENTRA DNI Cliente Se implementara como un numero de cuenta + numero de cliente duenio de la cuent
    bool nuevaCuenta;//Booleano cuanto esta en TRUE la cuenta esta en modo PROMISCUO se puede modificar a gusto.
};

class Cliente{
public:
    Cliente(string,string,int);
    void setNombre(string);
    void setApellido(string);
    void setDni(int);
    string getNombre() const;
    string getApellido() const;
    int getDni() const;
    void agregarCuenta(float);
    friend ostream & operator <<(ostream &, Cliente &);
    friend istream & operator >>(istream &, Cliente &);
private:
    string nombre;
    string apellido;
    int dni;
    vector<Cuenta> cartera;
};

class Banco{
public:
    Banco();//inicia los archivos o append si ya estan creados.
    ~Banco();//solo cierra los archivos
    void leerArchivos();//lee todos los archivos del programa y carga en memoria los clientes y cuentas.
    void escribirCliente(const Cliente );
    void escribirCuenta(const Cuenta );
    void escribirMovimiento(Cliente ,Cuenta ,const float);
private:
    fstream clientes;//puntero a file donde se guardan los clientes.
    fstream cuentas;//puntero a file donde se guardan las cuentas.
    fstream movimientos;//puntero a file donde se llevan los movimientos del banco
};

#endif /* BANCO_H */

