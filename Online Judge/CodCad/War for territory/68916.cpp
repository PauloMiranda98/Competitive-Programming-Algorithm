#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;


int main(){
	
	map<char,int> frequencia;

	int n,i, soma=0, vetor[100001], aux=0;
	
	cin >> n;	
	
	for(i=0; i<n; i++){
		cin >> vetor[i];
		soma += vetor[i];
	}
	
	soma/=2;

	for(i=0; aux != soma; i++){
		aux += vetor[i];
	}
	
	cout << i << endl;	
					   					
	return 0;
}   