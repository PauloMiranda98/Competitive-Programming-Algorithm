#include <bits/stdc++.h>
#define MAX 99999999

using namespace std;

map< long int, pair <char, long int> > conteiner;

int main() {

	long int n;
	long int a, b;
	char c;
	
	cin >> n;
	
	for(long int i=0; i < n; i++){
		cin >> a >> c >> b;
		
		conteiner[a] = make_pair(c, b) ;
		
	}
	
	map< long int, pair <char, long int> >::iterator it;
	
	pair <char, long int> aux;

	string res;
	
	aux = conteiner[0];	
	res += aux.first;
	
	while(aux.second != 1){
		aux = conteiner[aux.second];		
		res += aux.first;
	}
	
	cout << res << endl;
	
	return 0;
	
}
