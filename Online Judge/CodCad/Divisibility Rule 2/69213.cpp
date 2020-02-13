#include <iostream>
#include <string.h>

using namespace std;

int main(){
	
	char numero[1000000];
	
	cin >> numero;
	
	int t = strlen(numero);
	
	int aux = 0;
	
	if(t > 1)
		aux += (numero[t-2] - '0')*10;
		
	aux += (numero[t-1] - '0'); 
	
	if(aux % 4 == 0)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
	aux = 0;
	
	for(int i=0; i<t; i++)
		aux += (numero[i] - '0');
	
	if(aux % 9 == 0)
		cout << "S" << endl;
	else
		cout << "N" << endl;

	aux = 0;
	
	if(t > 1)
		aux += (numero[t-2] - '0')*10;
		
	aux += (numero[t-1] - '0'); 

	if(aux % 25 == 0)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
	return 0;
}
