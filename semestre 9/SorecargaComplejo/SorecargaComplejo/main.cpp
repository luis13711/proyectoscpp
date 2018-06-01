#include "SobrecargaComplejo.h"
/*

*/
int main(void)
{
	SobrecargaComplejo num1(2, 3);
    SobrecargaComplejo num2(3, 4);

    SobrecargaComplejo sum = num1.operador(num1,num2);
    // Imprimir los números y la suma usando el método reemplazado ToString:
   
	cout<<"Primer numero complejo: "; num1.toString();
    cout<<"Segundo numero complejo: "; num2.toString();
    cout<<"Suma de los dos numeros: "; sum.toString();
	system("pause");
	return 0;    
}