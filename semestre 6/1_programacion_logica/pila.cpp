#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const short unsigned int tamanio=10;
class pila{
private:
//const short unsigned int tamanio=10;
int posicion;
int items[tamanio];
public:
pila(){
    this->posicion=-1;
}
~pila(){
}
void push(int dato);
int pop();
int peek();
bool empty();
bool full();
};
void pila::push(int dato){
   if(!full()){
      this->items[++posicion]=dato; 
   }
   else{
      printf("\nOVERFLOW");
}
}
int pila::pop(){
    if(!empty()){
	return items[this->posicion];
    }
    else{
	printf("\nOVERFLOW");
	return 0;
    }
}
   
int pila::peek(void){
    if(posicion==0){
	posicion=-1;
        return items[0];
    }
    else{
        if(!empty()){
	return items[posicion--];
        }
        else{
	printf("\nOVERFLOW");
	return 0;
        }
    }
}
bool pila::empty(){
    if(this->posicion==-1){
	return true;
    }
    else{
        return false;
    }
}
bool pila::full(){
    if(this->posicion==tamanio){
	return true;
    }
    else{
	return false;
    }
}
int main(int argc, char** argv) {
    pila p;
    int elemento,elementos=10;
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
 

