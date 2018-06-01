#include <iostream>
#include <cstdlib>

using namespace std;

class IntNode
{
public:
	int head;
	IntNode *tail;
	IntNode(int head,IntNode *tail)
	{
		this->head = head;
		this->tail = tail;
	}
	~IntNode(void)
	{
		this->tail = NULL;
	}
};

void mostrar(IntNode *nodo)
{
	if(nodo!=NULL)
	{
		cout<<"nodo numero "<<nodo->head<<endl;
		mostrar(nodo->tail);
	}
}

void eliminar(IntNode *nodo)
{
    if(nodo!=NULL)
	{
        cout<<"eliminado numero "<<nodo->head<<endl;
        eliminar(nodo->tail);
        delete nodo;
	}
}
IntNode *odds,*primes;

int main(void)
{
	odds = new IntNode(3,new IntNode(5,new IntNode(7,NULL)));
	primes = new IntNode(2,odds);
	mostrar(primes);
	eliminar(primes);
	system("pause");
	return 0;
}