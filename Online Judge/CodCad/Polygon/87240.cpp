#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

long int vetor[MAX];

using namespace std;

int main() {
	long int n, ultima;
	long int soma = 0;
		
	cin >> n;
	
	
	for(int i=0; i<n; i++){
		cin >> vetor[i];
		soma += vetor[i];
	}
	
	ultima = n - 1;
	
	sort(vetor, vetor + n);
	
	soma -= vetor[ultima];	
		
	while((n>0) && (soma <= vetor[ultima]) ){		
		ultima--;
		soma -= vetor[ultima];	
		n--;
	}

	cout << n << endl;
	
	return 0;
	
}
