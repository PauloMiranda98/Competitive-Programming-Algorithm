#include <iostream>

using namespace std;

double media_vetor(int n, int v[]){
	double soma = 0;
	for(int i=0; i< n; i++){
		soma += v[i];
	}
	
	return soma/n;
}

int main(){
	
	int n, v[100100];
	cin >> n;
	
	for(int i=0;i<n;i++)
		cin >> v[i];
	
	cout << fixed;
	cout.precision(2);
	
	cout << media_vetor(n,v) << "\n";
	
	return 0;
}