#pragma once

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class SobrecargaComplejo
{
public: 
	int real;
    int imaginaria;
    SobrecargaComplejo(int real, int imaginaria);
	~SobrecargaComplejo(void);
    SobrecargaComplejo operador(SobrecargaComplejo c1, 
            SobrecargaComplejo c2);
	void toString();
    
};

