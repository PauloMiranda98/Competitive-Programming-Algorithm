#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

	int n, cont = 0;	
	int vetor[3];
	
	cin >> n;
	
	for(int i=0; i<3; i++){
		cin >> vetor[i];
	}
	
	sort(vetor, vetor+3);
	
	for(int i=0; i<3; i++){
		if(n >= vetor[i]){
			n -= vetor[i];
			cont++;
		}
	}
	
	cout << cont << endl;
	
	return 0;
}