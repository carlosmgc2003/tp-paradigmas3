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
    A.leerArchivos();
    for(int i = 0; i < A.clientesActivos.size(); i ++){
        cout << A.clientesActivos[i] << endl;
    }
    Cliente NUEVO("Cosme","Fulanito",10000000);
    A.clientesActivos.push_back(NUEVO);
    A.escribirClientes();    
    return 0;
}

