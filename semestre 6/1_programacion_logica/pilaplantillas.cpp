#include<iostream>
using namespace std;
const short unsigned int tamanio=10;
template<class T> class pila{
private:
//const short unsigned int tamanio=10;
int posicion;
T items[tamanio];
public:
pila(){
    this->posicion=-1;
}
~pila(){
}
void push(T dato);
T pop();
T peek();
bool empty();
bool full();
};
template<class T> void pila<T>::push(T dato){
   if(!full()){this->items[++posicion]=dato; }
   else{cout<<"OVERFLOW"<<endl;}
}
template<class T> T pila<T>::pop(){
    if(!empty()){
	return items[this->posicion];
    }
    else{
	cout<<"OVERFLOW"<<endl;
	return 0;
    }
}
   
template<class T> T pila<T>::peek(void){
    if(posicion==0){
	posicion=-1;
        return items[0];
    }
    else{
        if(!empty()){
	return items[posicion--];
        }
        else{
	cout<<"OVERFLOW"<<endl;
	return 0;
        }
    }
}
template<class T> bool pila<T>::empty(){
    if(this->posicion==-1){
	return true;
    }
    else{
        return false;
    }
}
template<class T> bool pila<T>::full(){
    if(this->posicion==tamanio){
	return true;
    }
    else{
	return false;
    }
}
int main(int argc, char** argv) {
    pila<int> p;
/*
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    while(p.empty()==false){
        cout<<"contenido "<<p.peek()<<endl;   
    }
    cout<<"contenido "<<p.peek()<<endl;
*/  int elementos=0,elemento;
    cout<<"ingrese cantidad de elementos a guardar"<<endl;
    cin>>elementos;
    cout<<"ingrese elementos"<<endl;
    for(int i=0;i<elementos;i++){
        cout<<"pila["<<i<<"]=";
	cin>>elemento;
        p.push(elemento);
    }
    while(p.empty()==false){
        cout<<"contenido "<<p.peek()<<endl;   
    }
    cin.get();
    cin.get();
    return 0;
}
 

