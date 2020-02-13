#include <iostream>

using namespace std;

int faixa[100001];
int n, k;

int buscab(int x){
	int ini = 0, meio, fim = n-1, r =0;
	meio = (ini + fim)/2;
	
	while(ini <= fim){
		meio = (ini + fim)/2;
		
		if(faixa[meio] == x){
			return true;
		}
		
		if(faixa[meio] < x){
			ini = meio + 1;
		} else{
			fim = meio - 1;
		}
	} 
	
	return false;
}

int main(){
	
	cin >> n;
	
	for(int i=0; i <(n); i++)
		cin >> faixa[i];

	cin >> k;
	
	int pivor=0;

	while(true){		
		if(buscab(k - faixa[pivor])){
			cout << faixa[pivor] << " " << (k - faixa[pivor]) << endl;
			break;
		}
		
		pivor++;
	}
	
	return 0;
}