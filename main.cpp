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

int Cuenta::numeroDeOrden = 1;

int main() {
    Banco A;
    Cliente * CLIENTES = A.leerArchivos();
    for(int i = 0; i < A.contarClientes(); i ++){
        cout << CLIENTES[i] << endl;
        A.escribirCliente(CLIENTES[i]);
    }
    delete [] CLIENTES;
//    Cliente carlos("Carlos","Maceira",32956544);
//    Cliente analia("Analia","Saavedra",27014855);
//    Cliente soraya("Soraya","Garcia Coni",17587002);
//    A.escribirCliente(carlos);
//    A.escribirCliente(analia);
//    A.escribirCliente(soraya);
    
    return 0;
}

