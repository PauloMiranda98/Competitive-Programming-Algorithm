#include <iostream>
#include <cstdio>

using namespace std;

int notas[6] = {2,5,10,20,50,100};
int n_notas[6];

int vetor[5001];

int main(){

	int troco;
	cin >> troco;
	
	for(int i = 0; i < 6; i++)
		cin >> n_notas[i];
	
	for(int i = 0; i <= troco; i++)
		vetor[i] = 0;
	
	vetor[0] = 1;

	for(int k = 0; k < 6; k++){
		for(int i = troco; i >=0; i--){
			if(vetor[i]){
				for(int j=1; j <= n_notas[k]; j++){
					int v = i + (notas[k]*j);
					
					if(v <= troco)
						vetor[v] += vetor[i];
				}
			}
		}
	}
		
	cout << vetor[troco] << endl;
		
	return 0;
}