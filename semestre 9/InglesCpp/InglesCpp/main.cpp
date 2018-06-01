#include<cstdlib>
#include<ctime>
#include<iostream>
#include<string>

using namespace std;
 
const int nofw = 16;

#define N 8 // numero de pares de palabras en la matriz
 
bool checkrep(int n, int num[])
{
    for(int i=0; i<nofw; i++)
        if(n == num[i])
            return true;
    return false;
}
 
int main(void)
{
    srand(time(NULL));

    string ans, words[N][2] = {{"hi", "hola"}, {"house", "casa"}, {"water", "agua"}, 
      {"roof", "techo"}, {"chair", "silla"}, {"loudspeaker", "bocina"}, 
      {"screen", "pantalla"}, {"money", "dinero"}};

    int n, correct=0, wrong=0;

    //cout << "Numero de palabras?: "; 
	//cin>>nofw;

    // obtener 'nofw' palabras aleatoriamente de nuestra matriz
    int num[nofw];
    for(int i=0; i<nofw; i++)
    {
        do
            n = rand() % N;
        while(checkrep(n, num));
        num[i] = n;
        cout<<words[n][0]<<" -> "<<words[n][1]<<endl;
		//cout<<words[n]<<" -> "<<words[n]<<endl;
    }
    cin.get(); 

    system("cls");
    // preguntar el significado de cada palabra
    for(int i=0; i<nofw; i++)
    {
        cout<<words[num[i]][0]<<" = "; 
		//cout<<words[num[i]]<<" = "; 
		getline(cin,ans);

        if(ans == words[num[i]][1])
        {
            correct++;
            cout << ">> Bien :)\n\n";
        }
        else
        {
            wrong++;
            cout << ">> Mal :(\n\n";
        }
    }
    cout << "Tuviste un " << (float)correct / (float)nofw * 100 << 
                "% de respuestas correctas.";
    cin.get(); 
	return 0;
}