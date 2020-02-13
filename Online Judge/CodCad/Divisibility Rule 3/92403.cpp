








#include <iostream>

using namespace std;


int main(){
	string numero;
	cin >> numero;
	
	int tam = numero.size();
	int alternar = 1;
	int soma = 0;
	
	for(int i = tam-1; i >= 0; i--){
		if(alternar == 1)
			soma += (numero[i] - '0');
		else
			soma += (numero[i] - '0') * 10;
		
		alternar *= -1;
	}
	
	if(soma % 11 == 0)
		cout << "S" <<endl;
	else
		cout << "N" <<endl;
			
	return 0;
}