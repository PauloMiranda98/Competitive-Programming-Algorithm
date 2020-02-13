#include <iostream>
#include <algorithm>

using namespace std;

int vetor[1000001];


int main(){
	
	int n, m, ultimo=0;
	long long int cont=0;
	
	cin >> n >> m;
	
	for(int i=0; i < n; i++){
		cin >> vetor[i];
	}

	ultimo = 0;
	
	for(int i=0; i < n; i++){
		int minimo = min(vetor[i], m-vetor[i]);
		int maximo = max(vetor[i], m-vetor[i]);

		if( maximo < ultimo){
			cont = -1;
			break;
		}
		
		if(minimo >= ultimo){
			ultimo = minimo;
			cont += minimo;
		}else{
			ultimo = maximo;
			cont += maximo;		
		}
	}
	
	cout << (cont) << endl;	    			 	
													 			   				
	return 0;	
}   
   
