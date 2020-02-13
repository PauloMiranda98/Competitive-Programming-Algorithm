#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	long long int vetor[100001];
	long int n;	
	cin >> n;

	for(int i=0; i < n; i++){
		cin >> vetor[i];
	}
	
	sort(vetor, vetor+n);
	
	cout << vetor[n-1];
	
	for(int i = n-2; i >=0 ; i--)
		cout << " " << vetor[i];

	cout << endl;
		
	return 0;
}