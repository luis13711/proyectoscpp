#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	
	string stringRef;
	
   cout << "capacidad: " << stringRef.capacity() 
        << "\ntamanio max: " << stringRef.max_size()
        << "\ntamanio: " << stringRef.size()
        << "\nlongitud: " << stringRef.length()
        << "\nvacia: " << stringRef.empty()<<endl;
 
  // fin de imprimirEstadisticas	
	system("PAUSE");
	return 0;
	}

