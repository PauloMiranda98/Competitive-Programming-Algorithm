#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
int n, m;

bool compara(long long int a, long long int b){
	if(a%m == b%m){
		return (a > b);
	}
	
	return (a%m > b%m);
}


int main(){
	
	long long int vetor[100001];
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		cin >> vetor[i];
	}
	
	sort(vetor, vetor+n, compara);
	
	for(int i=0; i<n; i++){
		cout << vetor[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}