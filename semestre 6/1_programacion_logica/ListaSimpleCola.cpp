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
            this->sig=NULL;
        }
        ~Nodo();
	Nodo<T>* getSiguiente();
        void setSiguiente(Nodo<T> *sig);
        T getValor();
        void setValor(T valor);
};
template<class T> void Nodo<T>::setSiguiente(Nodo<T> *sig){this->sig=sig;}
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
    Nodo<T>* getIndex();
};
template<class T> Nodo<T>* ListaSimple<T>::getIndex(){return this->index;}
template<class T> void ListaSimple<T>::push(T valor){
    Nodo<T> *NodoNuevo=new Nodo<T>(valor);
    if(posicion==0){
        this->index=NodoNuevo;posicion++;
    }
    else{
        /*
        NodoNuevo->setSiguiente(index);
        index=NodoNuevo;posicion++;
        */
	Nodo<T> *aux=index;
        for(;aux->getSiguiente()!=NULL;aux=aux->getSiguiente());
	aux->setSiguiente(NodoNuevo);
    }
}
template<class T> T ListaSimple<T>::pop(void){
    if(this->index != NULL){return index->getValor();}
}
template<class T> T ListaSimple<T>::peek(void){	
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
    if(posicion==0){return true;}
    return false;
}
int main(void){
    ListaSimple<char> *lista=new ListaSimple<char>();
    int elemento=0;
    char dato;
    cout<<"ingrese elementos en cola "<<endl;    
    for(char caracter='s';caracter=='s';){
        cout<<"elemento["<<elemento<<"]=";
        cin>>dato;
	lista->push(dato);
        cout<<"desea seguir agregando datos s/n"<<endl;
        cin>>caracter;
    }
    for(Nodo<char> *aux=lista->getIndex();aux!=NULL;
                aux=aux->getSiguiente()){
        cout<<"Contenido es: "<<aux->getValor()<<endl;
        
    }
    cin.get();
    cin.get();
    delete lista;
    return 0;
}
