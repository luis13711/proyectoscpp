/* 
 * File:   main.cpp
 * Author: luis13711
 *
 * Created on 26 de marzo de 2015, 07:15 PM
 */
#include<iostream>
#include "Pila.h"
#include "Lista.h"
#include<string>
//#include "ListaNueva.h";
using namespace std;

int main(int argc, char** argv) {
    pila p;
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    while(p.empty()==false){
        cout<<"contenido "<<p.peek()<<endl;   
    }
    cout<<"contenido "<<p.peek()<<endl;
    ListaSimple<string> *lista=new ListaSimple<string>();
    lista->push("20");
    lista->push("30");
    lista->push("40");
    lista->mostrar();
    delete lista;
    return 0;
}

