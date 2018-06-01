#pragma once

#include <string>
#include <iostream>
#define max 10

using namespace std;

struct Valor{
	int a[max];
	};

class PrincipalBurbuja{
private:
	int n;
	Valor valor;
	bool verificar();
	int leerElemento(string cadena);
	int leerElemento(string cadena,int n);
	Valor metodoBurbuja(Valor valor, int n);

public:
	PrincipalBurbuja(void);
	void Main(void);
	};

