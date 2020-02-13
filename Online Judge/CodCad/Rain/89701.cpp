#include <bits/stdc++.h>

#define MAX 100001

using namespace std;

long int vetor[MAX];
long int me[MAX];
long int md[MAX];
long int n;

int main() {
	
	long int cont = 0;
	cin >> n;
	
	for(long int i=0; i < n; i++){
		cin >> vetor[i];
	}
	
	me[0] = vetor[0];
	
	for(long int i = 1;i < n; i++){
		me[i] = max(vetor[i], me[i-1]);
	}
	
	md[n-1] = vetor[n-1];
	
	for(long int i = n-2;i >= 0; i--){
		md[i] = max(vetor[i], md[i+1]);
	}
	
	for(long int i = 0;i < n; i++){
		if( (me[i] > vetor[i]) && (md[i] > vetor[i]) )
			cont++;
	}

	cout << cont << endl;
	
	return 0;
	
}
