#include <iostream>
#include <string.h>

using namespace std;

int main(){
	
	char numero[1000000];
	
	cin >> numero;
	
	int t = strlen(numero);
	
	int aux = 0;
		
	for(int i=0; i<t; i++)
		if(i % 2 == 0)
			aux += (numero[i] - '0')*10;
		else	
			aux += (numero[i] - '0');
		
	if(aux % 11 == 0)
		cout << "S" << endl;
	else
		cout << "N" << endl;		
	
	return 0;
}
