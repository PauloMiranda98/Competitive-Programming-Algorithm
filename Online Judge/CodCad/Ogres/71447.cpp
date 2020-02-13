#include <iostream>

using namespace std;

int faixa[10001];
int n, m;

int buscab(int x){
	int ini = 0, meio, fim = n-1, r =0;
	meio = (ini + fim)/2;
	
	while(ini <= fim){
		meio = (ini + fim)/2;
		
		if(faixa[meio] == x){
			return (meio);
		}
		
		if(faixa[meio] < x){
			ini = meio + 1;
			r = meio;
		} else{
			fim = meio - 1;
		}
	} 
	
	return r;
}

int main(){
	
	int peso[10001];
	
	cin >> n >> m;

	faixa[0] = 0;
	for(int i=1; i <(n); i++)
		cin >> faixa[i];
	
	for(int i=0; i <(n); i++)
		cin >> peso[i];
	
	int x;
	
	for(int i=0; i < m; i++){
		cin >> x;
		cout << peso[buscab(x)] << " ";
	}
	
	cout << endl;
	
	return 0;
}