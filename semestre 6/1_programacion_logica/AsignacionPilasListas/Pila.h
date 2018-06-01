/* 
 * File:   Pila.h
 * Author: luis13711
 *
 * Created on 26 de marzo de 2015, 07:16 PM
 */

#ifndef PILA_H
#define	PILA_H
#include<cstdlib>
#include<cstdio>
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
#endif	/* PILA_H */

