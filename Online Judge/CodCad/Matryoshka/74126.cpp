#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
	
	stringstream ss;
	
	int n, cont = 0;
	long long int vetor[100001];
	long long int vetor2[100001];
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> vetor[i];
		vetor2[i] = vetor[i];
	}
	
	sort(vetor2, vetor2+n);
	
	for(int i=0; i<n; i++){
		if(vetor[i] != vetor2[i]){
			ss << vetor2[i] << " ";
			cont++;
	   }
	}
	
	cout << cont << endl;
	
	if(cont > 0){
		
		cout << ss.str() <<endl;
	}
	
	
	return 0;
}