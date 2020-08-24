#include <cstdlib>
#include <iostream>

using namespace std;

int main(){

	float f = 2;
	float d = 2.6;

	if(((int)f&(int)d)==d)
		cout<<"son iguales"<<endl;
	else
		cout<<"no son iguales"<<endl;
	system("pause");
	return 0;
}