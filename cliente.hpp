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
#include <string>
#include <vector>
using namespace std;

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


#endif /* CLIENTE_HPP */

