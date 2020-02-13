#include <iostream>

using namespace std;

int main(){
	
	string numero;
	
	cin >> numero;
	
	int t = numero.size(); // pegando o tamanho da string
	
	int aux;
	
	aux = numero[t-1] - '0'; // Pegando o ultimo digito
							//  O -'0' serve para converte o caracter para numero
							
	if(aux % 2 == 0)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
	aux = 0;
	
	for(int i=0; i<t; i++) 			// Pegando todos os digitos e somando
		aux += (numero[i] - '0');   // Convertendo cada caracter para inteiro
	
	if(aux % 3 == 0)
		cout << "S" << endl;
	else
		cout << "N" << endl;

	aux = numero[t-1] - '0'; // Pegando o ultimo digito
							//  O -'0' serve para converte o caracter para numero

	if(aux % 5 == 0)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
	return 0;
}
