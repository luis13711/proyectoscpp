#include<iostream>
#include<cstdlib>

using namespace std;

enum ShapeType {
  circle = 10, square = 20, rectangle = 50
};

/*
enum ShapeType {
  circle = "circulo", square = "no se", rectangle = "rectangulo"
};
*/
int main(void)
{
	  ShapeType shape = circle;

  switch(shape) 
  {
    case circle:  
		cout<<"eligio el circulo"<<endl;
		break;
    case square:  
		break;
    case rectangle: 
		break;
  }
	system("pause");
	return 0;
}