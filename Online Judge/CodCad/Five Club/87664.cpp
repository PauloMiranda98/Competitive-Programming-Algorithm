#include <bits/stdc++.h>

using namespace std;

int main() {
	
	long int vetor[7], n;
	
	cin >> n;
	
	for(int i=0; i<7; i++){
		cin >> vetor[i];
	}
	
	n -= vetor[0];
	n -= vetor[1];
	n -= vetor[2];
	n += vetor[3];
	n += vetor[4];
	n += vetor[5];	
	n -= vetor[6];
	
	if(n == 0)
		cout << "N" << endl;
	else	
		cout << "S" << endl;
	
	return 0;
	
}
