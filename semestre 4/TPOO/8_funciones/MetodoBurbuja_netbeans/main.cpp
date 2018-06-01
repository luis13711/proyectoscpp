/* 
 * File:   main.cpp
 * Author: luis
 *
 * Created on 25 de agosto de 2012, 12:17
 */

#include <cstdlib>
#include <cstdio>
using namespace std;

int main(int argc, char** argv) {

        const int max = 10;

        unsigned short int i, cambio, n;

	int aux, a[max];

	do{

                puts("ingrese tamaño de arreglo unidimensional:");

		scanf("%d", &n);

                }while(n>max&&n<2);

	for(i=0;i<n;i++){

		printf("a[%d]=", i);

		scanf("%d", &a[i]);

		}

	cambio=1;

	while(cambio==1){

		cambio=0;

		for(i=0;i<n-1;i++){

                        if(a[i]>a[i+1]){

                                aux=a[i];

				a[i]=a[i+1];

				a[i+1]=aux;

				cambio=1;

				}

			}

		}

	puts("el arreglo quedo asi:");

	for(i=0;i<n;i++)
                printf("%d, ", a[i]);
             
        return 0;
}


