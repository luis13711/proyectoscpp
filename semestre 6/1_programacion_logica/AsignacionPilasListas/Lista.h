/* 
 * File:   Lista.h
 * Author: luis13711
 *
 * Created on 26 de marzo de 2015, 07:37 PM
 */

#ifndef LISTA_H
#define	LISTA_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
template<class T>
class Nodo{
    private:
	T valor;
        Nodo<T> *sig;
    public:
        Nodo(T valor){
            this->valor=valor;
        }
        ~Nodo();
	Nodo<T>* getSiguiente();
        void setSiguiente(Nodo<T> *sig);
        T getValor();
        void setValor(T valor);
};
template<class T> void Nodo<T>::setSiguiente(Nodo<T> sig){this->sig=sig;}
template<class T> Nodo<T>* Nodo<T>::getSiguiente(){return sig;}
template<class T> void Nodo<T>::setValor(T valor){this->valor=valor;}
template<class T> T Nodo<T>::getValor(){return this->valor;}

template<class T>
class ListaSimple{
private:
    Nodo<T> *index;
    int posicion;
public:
    ListaSimple(){
        this->posicion=0;
	this->index=NULL;
    }
    ~ListaSimple(){
    }
    void push(T valor);
    T pop();
    T peek();
    T getValor();
    bool empty();
    int length();
    void mostrar();
};
template<T> void ListaSimple<T>::mostrar(){
    if(!this->empty()){
        for(Nodo<T> *apuntadorAuxiliar=index;
                apuntadorAuxiliar->getSiguiente()!=NULL;
                apuntadorAuxiliar=apuntadorAuxiliar->getSiguiente()){
            cout<<"Contenido es: "<<apuntadorAuxiliar->getValor()<<endl;
        }
    }
    cin.get();
}
template<class T> void ListaSimple<T>::push(T valor){
    Nodo<T> *NodoNuevo=new Nodo<T>(valor);
    if(posicion==0){
        this->index=NodoNuevo;posicion++;
    }
    else{
        NodoNuevo->setSiguiente(index);
        index=NodoNuevo;posicion++;
    }
}
template<class T> T ListaSimple<T>::pop(void){
    if(this->index != NULL){
	return index->getValor();
    }
}
template<class T> T ListaSimple<T>::peek(void){	
    Nodo<T> *apuntadorAuxiliar;
    if(this->index!= NULL){
        T valor = index->getValor();
        Nodo<T> *aux=index;
        index=index->getSiguiente();
        delete aux;
        posicion--;
        return valor;
    }
}
template<class T> int ListaSimple<T>::length(){ return this->posicion; }
template<class T> bool ListaSimple<T>::empty(){ 
    if(posicion==0){
        return true;
    }
    else{
        return false;
    } 
}

#endif	/* LISTA_H */

