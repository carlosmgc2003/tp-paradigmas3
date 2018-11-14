/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "banco.hpp"
#include "wx/msgdlg.h"

/* Constructor de la Clase BANCO su funcion basicamente es inicializar los archivos
del programa si es que estos no existe. Para ello utiliza los atributos fstream (clientes
cuentas y movimientos) del objeto Banco*/
Banco::Banco(){
    // Probamos si podemos abrir el archivo clientes.txt
    clientes.open("clientes.txt", fstream::in);
    // Si el archivo clientes.txt se abre
    if(!clientes.is_open()){
        //Creamos el archivo clientes, cuentas y movimientos (por la combinacion out y trunc) 
        clientes.open("clientes.txt",fstream::out | fstream::trunc);
        cuentas.open("cuentas.txt",fstream::out | fstream::trunc);
        movimientos.open("movimientos.txt",fstream::out | fstream::trunc);
        // Cerramos los archivos creados para pasar a ...
        clientes.close();
        cuentas.close();
        movimientos.close();
        //... el modo de lectura
        clientes.open("clientes.txt", fstream::in);
        cuentas.open("cuentas.txt", fstream::in);
        // el fstream movimientos pasa al modo append
        movimientos.open("movimientos.txt", fstream::out | fstream::app);
        // Si ocurrio todo esto es la primera vez que abrimos banco por lo tanto mostramos un bonito cartel.
        wxMessageBox(_("Ejecutando por primera vez Banco CrisNaMa\nEmpiece creando un cliente."),_("Atenci�n"));
    }
    // Ahora veamos que cuando los archivos EXISTEN, simplemente los abro.
    else{
        cuentas.open("cuentas.txt", fstream::in);
        movimientos.open("movimientos.txt", fstream::out | fstream::app);
    }

}

/* Destructor de Banco. Basicamente cierra los archivos abiertos */
Banco::~Banco(){
    clientes.close();
    cuentas.close();
    movimientos.close();
}


/* Es el mmetodo de guardado principal, al que se invoca cada vez que se quiere guaradar cambios en
el disco. Es realmente la manera en la que persiste el estado del Banco invocado al cerrar la ventana,
pero tambien de forma arbitraria cuando lo desee el cliente. */
void Banco::escribirEstadoAArchivos(){
    //Escribimos todos los clientes, para ello primero cerramos el archivo clientes que habia quedado en modo lectura
    clientes.close();
    // Lo abrimos en modo truncar o sea, pisamos lo que sea que este en el archivo. Total vamos a guardar lo que esta en memoria
    clientes.open("clientes.txt", fstream::out | fstream::trunc);
    // Por cada cliente en clientesActivos
    for(int i = 0; i < clientesActivos.size(); i ++){
        // escribo el cliente i del vector al archivo
        clientes << clientesActivos[i];
        // Si el cliente NO es el ultimo
        if(i < clientesActivos.size() - 1)
            // Pongo un enter al final del cliente (esto se hace para evitar un ultimo enter que me arruina el contar clientes)
            clientes << endl;
    }
    // Cierro el archivo clientes
    clientes.close();
    // Lo vuelvo a abrir en modo lectura asi el sistema vuelve al estado inicial
    clientes.open("clientes.txt",fstream::in);

    //Ahora vamos a escribir las cuentas, cerrarmos el filestream cuentas que esta en modo lectura
    cuentas.close();
    // Lo abrimos en modo truncar o sea, pisamos lo que sea que este en el archivo. Total vamos a guardar lo que esta en memoria
    cuentas.open("cuentas.txt", fstream::out | fstream::trunc);
    // Contamos la cantidad total de cuentasTotalesEnMemoria enmemoria, lo necesitamos para saber cuando va a terminar este algoritmo
    int cuentasTotales = cuentasTotalesEnMemoria();
    //Para cada cliente:
    for(int i = 0; i < clientesActivos.size(); i ++){
        //Si el cliente tiene cuentas:
        if(clientesActivos[i].contarCuentasCliente() != 0){
            //cout << "Escribiendo cuentas para: " << clientesActivos[i] << endl;
            //Recorremos cada cuenta
            //cout << "Tiene cuentas activas: " << clientesActivos[i].contarCuentas() << endl;
            for(int j = 0;j < clientesActivos[i].contarCuentasCliente(); j++){
                //La escribimos en el disco
                cuentas << clientesActivos[i][j];
                // Decrementamos el contador de cuentasTotales
                cuentasTotales --;
                // Si la cuenta no es la ultima y todavia quedan cuentas en memoria (de cualquier cliente)
                if(j < clientesActivos[i].contarCuentasCliente() && cuentasTotales > 0)
                    // Coloco un salto de linea (Enter) al final :P
                    cuentas << endl;
            }
        }
    }
    //Cierro el archivo de cuentas
    cuentas.close();
    // Lo vuelvo a abrir en modo lectura para volver el sistema al estado inicial.
    cuentas.open("cuentas.txt", fstream::in);
}


void Banco::leerArchivos(){
    int cantClientes = contarClientesDeArchivos();
    if(cantClientes > 0){
        Cliente auxCliente;
        clientes.seekg(clientes.beg);
        while(!clientes.eof()){
            clientes >> auxCliente;
            clientesActivos.push_back(auxCliente);
            if(clientes.eof())
                break;
        }
        int cantCuentas = contarCuentasDeArchivos();
        if(cantCuentas > 0){
            cuentas.seekg(cuentas.beg);
            int mayorId = 1;
            while(!cuentas.eof()){
                Cuenta auxCuenta;
                cuentas >> auxCuenta;
                if(auxCuenta.getnumeroUnico() > mayorId)
                    mayorId = auxCuenta.getnumeroUnico();
                //cout << "Leida la cuenta: " << auxCuenta << " en posicion: " << cuentas.tellg() <<endl;
                for(int i = 0; i < clientesActivos.size();i ++){
                    if(clientesActivos[i].getDni() == auxCuenta.getdniDuenio()){
                        clientesActivos[i].agregarCuenta(auxCuenta);
                        //cout <<"Se agrego cuenta: " << auxCuenta << " a " << clientesActivos[i] << " en posicion " << i << endl;
                        break;
                    }
                }
                if(cuentas.eof())
                    break;
            }
            Cuenta::inicializarGenerador(mayorId + 1);
        }
    }

}

int Banco::contarClientesDeArchivos(){
    int i = 0;
    string aux;
    clientes.seekg(clientes.beg);
    while(!clientes.eof()){
        clientes >> aux;
        if(aux.size() > 1){
            i ++;
        }
        if(clientes.eof())
            break;
    }
    return i;
}


int Banco::contarCuentasDeArchivos(){
    int i = 0;
    string aux;
    cuentas.seekg(cuentas.beg);
    while(!cuentas.eof()){
        cuentas >> aux;
        if(aux.size() > 1){
            i++;
        }
        if(cuentas.eof())
            break;
    }
    return i;
}

int Banco::cuentasTotalesEnMemoria(){
    int contador = 0;
    for(int i = 0; i < clientesActivos.size();i ++){
        contador += clientesActivos[i].contarCuentasCliente();
    }
    return contador;
}
