#include<iostream>
#include<string>
using namespace std;
class Motor{
protected:
	string bobina;
public:
	Motor(){
		bobina="cobre";
	}
	Motor(string bo){
		bobina=bo;
	}
	void Bobina(string bo);
 };
void Motor::Bobina(string bo){
	bobina=bo;
}

class Aspa{
protected:
	string tamano, niveldeoxidacion;
	string color;
public:
	Aspa(){
		tamano=20;
		niveldeoxidacion=20;
		color="blanco";
	}
	Aspa(string ta,string ox,string co){
		tamano = ta;
		niveldeoxidacion = ox;
		color=co;
	}
	void Lee(string ta, string ox,string co);
};
void Aspa::Lee(string ta,string ox, string co){
	 tamano = ta;
	 niveldeoxidacion = ox;
	 color=co;
 }

class Ventilador: public Motor, public Aspa{
public:
	Ventilador():Motor(),Aspa(){
	}
	Ventilador(string bo,string ta,string ox,string co):Motor(bo),Aspa(ta,ox,co){
	}
	string toString(); 
};
string Ventilador::toString(){
	return "hola como estan todos ustedes clase aspa\nsu tamaño es "+tamano
		+"\nsu nivel de oxidaciones "+niveldeoxidacion
	 +"\nsu color es "+color;
 }
int main(void){
	//stoi("2") para convertir string a entero
	Ventilador *par1=new Ventilador("cobre","20","2","rojo");
	cout<<par1->toString();
	cin.get();
	return 0;
}