/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on 3 de octubre de 2018, 04:34
 */

#include <cstdlib>
#include <iostream>
#include "banco.hpp"

using namespace std;

int Cuenta::generadorNumeros = 1;

void mostrarClientesBanco(Banco &);

int main() {
    Banco A;
    A.leerArchivos();
    cout << "Clientes antes"<< endl;
    mostrarClientesBanco(A);
    //Aqui hacer las operaciones de ABM de clientes
    
    //A.clientesActivos.pop_back();
    
    
    
    
    //Fin de las operaciones de ABM de clientes
    cout << "Clientes despues:"<< endl;
    mostrarClientesBanco(A);
    A.escribirEstadoAArchivos();    
    return 0;
}

void mostrarClientesBanco (Banco & banco){
    for(int i = 0; i < banco.clientesActivos.size(); i++)
        cout << i + 1 <<". "<< banco.clientesActivos[i] << endl;
}
