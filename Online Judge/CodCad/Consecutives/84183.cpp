#include <iostream>

using namespace std;

int main(){
	long int n, i, novo, cont=1, ultimo, maior=1;

	cin >> n; // tamanho
	cin >> ultimo; // ultimo elemento lido, por enquanto eh o primeiro
	
	for(i=1; i<=(n-1); i++){ // como ja li o primeiro, so preciso ler os n-1 restante 
		cin >> novo; // novo elemento que vai ser testado
	
		if(novo == ultimo){ 
			cont++;
		}else{
			if(cont > maior){
				maior = cont;
			}
			cont=1;
			ultimo = novo;
		}
	}
	
	if(cont > maior){
		maior = cont;
	}
			   	
	cout << maior << endl;
							   					
	return 0;
}