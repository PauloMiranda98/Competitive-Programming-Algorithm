#include <bits/stdc++.h>
#define MAX 99999999

using namespace std;

set<string> conteiner;
long int fatorial(long int x){
	if(x == 1){
		return 1;
	}
	
	return x * fatorial(x-1);
}

int main() {

	long int n;
	
	cin >> n;

	string aux;
	
	for(long int i=1; i <= n; i++){
		aux += '0' + i;		
	}
	
	long int lim = fatorial(n);
	
	for(long int i=1; i < lim; i++){
		string e;
		for(long int j=0; j<n; j++){
			char x;
			cin >> x;
			e += x;
		}
		conteiner.insert(e);		
	}
	
	while(conteiner.find(aux) != conteiner.end()){
		next_permutation(aux.begin(), aux.end());
	}
	
	
	for(long int j=0; j<n; j++){
		cout << aux[j] << " " ;
	}
	cout << endl;
	
	return 0;
	
}
