/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   cuenta.hpp
 * Author: cmaceira
 *
 * Created on 16 de octubre de 2018, 12:41
 */

#ifndef CUENTA_HPP
#define CUENTA_HPP
#include <string>
#include <iostream>

using namespace std;
enum TIPO {CA,CC};

class Cuenta{
public:
    //Constructores
    Cuenta(int,int,int);
    Cuenta(int,int,float);//Constructor con id y saldo, deja nuevaCuenta en False.
    Cuenta(int,int);/** Constructor solo con id. Deja nuevaCuenta en false, por lo cual
                 * cualquier modificacion futura del saldo debe ser usado creditos y
                 * debitos o los operadores sobrecargados.***/
    Cuenta();/** Constructor sin parametros. Usar con precaucion solo cuando se realice
              * carga de archivos. Esta a prueba**/
    //
    ~Cuenta();
    //Getters comunes... nada que aclarar
    float getSaldo() const;
    int getdniDuenio() const;
    int gettipoCuenta() const;
    int getnumeroUnico() const;
    //Setters
    void setSaldo(float);//Setter del saldo, se puede usar solo cuando nuevaCuenta == TRUE OJO!!!
    void setdniDuenio(int);//Setter de ID se puede usar solo cuando nuevaCuenta == TRUE. Pasa nuevaCuenta a FALSE
    void setCuentaIniciada();//Sirve como gatillo para bajar la cuenta del modo "promiscuo" nuevaCuenta
    void setnumeroUnico(int);
    void settipoCuenta(int);
    //Sobrecarga de operadores
    friend ostream & operator<<(ostream &,Cuenta &);//Sobrecarga de salida; se usara para escribir en archivo.
    friend istream & operator>>(istream &,Cuenta &);//Sobrecarga de entrada; se usara para leer archivo
    //TODO: estos operadores deben escribir ESTOS movimientos en el archivo movimientos.txt
    void operator += (float);//Sobrecarga de incremento se usara para creditos. Todavia con pocas reglas.
    void operator -= (float);//Sobrecarga de desincrementar se usara para dbitos. Todavia solo valida signo del saldo.
    void acreditar(float);//El saldo ingresado se suma al existente.
    void debitar(float);//El saldo ingresado se resta al existente.
    static int generadorNumeros;
    static void inicializarGenerador(int);

private:
    float saldo;//Saldo en pesos de la cuenta
    int dniDuenio;//DNI del dueño de la cuenta
    bool nuevaCuenta;//Booleano cuanto esta en TRUE la cuenta esta en modo PROMISCUO se puede modificar a gusto.
    int tipoCuenta;// Si es CA (False) o CC (True)
    int numeroUnico;



};


#endif /* CUENTA_HPP */

