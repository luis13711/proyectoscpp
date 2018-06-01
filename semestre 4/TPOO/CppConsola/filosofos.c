#include<stdio.h>
#include<stdlib.h>

/* programa cena_filósofos */ 
typedef int semaforo;
semaforo palillo[5] = {1}; 
int i; 
void comer(){}
void pensar(){}
void filosofo(int i) 
{ 
 while (cierto) 
 { 
 pensar ( ); 
 wait (palillo [i]); 
 wait (palillo [(i + 1) % 5]; 
 comer ( ); 
 signal (palillo [(i + 1) % 5]); 
 signal (palillo [i]); 
 } 
} 
void main ( ) { 
parbegin(filosofo (0), filosofo (1), filosofo (2), filosofo (3), filosof(4)); 
getchar();
} 
