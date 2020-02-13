#include <iostream>
#include <utility>  
#include <algorithm>

using namespace std;


int abs(int a){

	return a<0? -a: a;
}

int vetor[1001];

int main(){
	int n, m;
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for(int i=0; i < n; i++)
		cin >> vetor[i];

	int cont = 0;
	
	for(int i=0; i < (n-1); i++){
		int op = m - vetor[i];
		
		vetor[i+1] += op;
		
		cont += abs(op);				
	}
	
	cout << cont << endl;
	
    return 0;
}