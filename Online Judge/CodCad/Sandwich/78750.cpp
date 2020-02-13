#include <iostream>
#include <map>

using namespace std;

long int vetor[2000001];

int main(){

	long int n, d, cont = 0;
	
	cin >> n >> d;
	
	for(long int i = 0; i < n; i++){		
		cin >> vetor[i];
		vetor[n+i] = vetor[i];
	}
	
	long int i = 0;
	long int k = 0;
	long int soma = 0;
	
	if(n > 2){
		while(i < n){
						
			while((soma < d) && ( (k-i) < n))
				soma += vetor[k++];

			if(soma == d){
				cont++;			
			}
			
			soma -= vetor[i++];			
		}
		
	}else{
		if(vetor[0] == d)
			cont++;
		if(vetor[1] == d)
			cont++;
		if( (vetor[0] + vetor[1]) == d)
			cont++;

    }	
    
	cout << cont << endl;
		
	return 0;
}