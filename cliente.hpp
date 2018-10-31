/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cliente.hpp
 * Author: cmaceira
 *
 * Created on 16 de octubre de 2018, 12:39
 */

#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "cuenta.hpp"
using namespace std;


class Cliente{
public:
    Cliente();//Constructor vacio que sirve para el new[]
    Cliente(string,string,int,string,string);//Constructor de cliente
    //Setters
    void setNombre(string);
    void setApellido(string);
    void setDni(int);
    void setDireccion(string);
    void setTelefono(string);
    //getters
    string getNombre() const;
    string getApellido() const;
    int getDni() const;
    string getDireccion() const;
    string getTelefono() const;
    //Metodos propios
    void agregarCuenta(float);//Crea una cuenta nueva
    void agregarCuenta(Cuenta);//Push back una cuenta en el vector cartera
    void eliminarCuenta(int);//Elimina una cuenta y devuelve por pantall el saldo que tenia (extraccion en efectivo)
    friend ostream & operator <<(ostream &, Cliente &);//Sobrecarga de salida para escribir archivos
    friend istream & operator >>(istream &, Cliente &);//Sobrecarga de entrada para leer archivos
    Cuenta & operator [] (const int);//Sobrecarga de los corchetes sirve para acceder a cada cuenta del cliente de forma directa
    int contarCuentas() const;
    
private:
    string nombre;
    string apellido;
    int dni;
    string direccion;
    string telefono;
    vector<Cuenta> cartera;
};


#endif /* CLIENTE_HPP */

