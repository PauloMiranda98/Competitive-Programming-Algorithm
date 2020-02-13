#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	double notas[5], soma=0, aux;
	int  i,j;
	
	for(i=0; i<5; i++){
		cin >> notas[i];
	}		
	for(i=0; i<4; i++){
		for(j=i+1; j<5; j++){
			if(notas[j] < notas[i]){
				aux = notas[j];
				notas[j] = notas[i];
				notas[i] = aux;
			}
		}		
	}		
	
	soma = notas[1] + notas[2] + notas[3];
	
	printf("%.1f\n", soma);
							   					
	return 0;
}   