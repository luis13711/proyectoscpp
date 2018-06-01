#include "PrincipalBurbuja.h"

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

bool PrincipalBurbuja::verificar(){
	if(n>max&&n<2)
		return true;
	else
		return false;
	}

int PrincipalBurbuja::leerElemento(string cadena){

	int elemento;

	cout<<cadena<<" ";

	cin>>elemento;

	return elemento;

	}

int PrincipalBurbuja::leerElemento(string cadena,int n){

	int elemento;

	string caracter;

	caracter = char(n);

	cadena.replace(2,0,caracter); 

	cout<<cadena<<" ";

	cin>>elemento;

	return elemento;

	}

Valor PrincipalBurbuja::metodoBurbuja(Valor valor, int n){
	int aux, cambio=1;

	while( cambio == 1 ){

		cambio = 0;

		for(int i = 0 ; i < n - 1 ; i++ )

			if( valor.a[i] < valor.a[i+1]){

				aux = valor.a[i];

				valor.a[i] = valor.a[i+1];

				valor.a[i+1] = aux;

				cambio = 1;
								
				}

		}

	return valor;

	}
PrincipalBurbuja::PrincipalBurbuja(void)
{
}

void PrincipalBurbuja::Main() {

	do{
		n = leerElemento("ingrese tamaño de arreglo unidimensional:");

        }while(verificar());

	for(int i=0;i<n;i++)

		valor.a[i] = leerElemento("a[]=",48+i);
		
	valor = metodoBurbuja(valor,n);

	cout<<"el arreglo quedo asi:"<<endl;

	for(int i=0;i<n;i++)
		cout<<valor.a[i]<<endl;
        
	system("pause");
    return;
	}
