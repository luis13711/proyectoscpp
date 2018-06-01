#include "SobrecargaComplejo.h"


SobrecargaComplejo::SobrecargaComplejo(int real, int imaginaria)
    {
        this->real = real;
        this->imaginaria = imaginaria;
    }

SobrecargaComplejo::~SobrecargaComplejo(void)
    {
        this->real = 0;
        this->imaginaria = 0;
    }

SobrecargaComplejo SobrecargaComplejo::operador(SobrecargaComplejo c1, 
            SobrecargaComplejo c2)
    {
		SobrecargaComplejo a(c1.real + c2.real, c1.imaginaria + c2.imaginaria);
        return a; 
    }

void SobrecargaComplejo::toString()
{
	cout<<real<<" + "<<imaginaria<<"i"<<endl; 
		
}

