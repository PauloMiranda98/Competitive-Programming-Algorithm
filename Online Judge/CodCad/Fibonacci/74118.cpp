#include <iostream>

using namespace std;

int main(){
	int n;
	unsigned long long int vetor[31];
	
	cin >> n;
	vetor[0] = 1;
	vetor[1] = 1;
	
	for(int i=2; i<=n; i++){
		vetor[i] = vetor[i-1] + vetor[i-2];
	}
	
	
	cout << vetor[n] << endl;
	
	return 0;
}