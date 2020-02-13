#include <iostream>
#include <set>

long int vetor[100001];

using namespace std;

int main(){
	set<long int> c1, c2;
	
	long int cont = 0, cont2 = 0;
	long int n, m;			
	cin >> n >> m;

	for(long int i=0; i < n; i++){
		long int x;
		cin >> x;
		c1.insert(x);
	}
	
	for(long int i=0; i < m; i++){
		long int x;
		cin >> x;
		c2.insert(x);
	}
		
	for(set<long int>::iterator it = c1.begin(); it != c1.end(); it++){
		if(c2.find(*it) == c2.end()){
			cont++;
		}
	}
	
	for(set<long int>::iterator it = c2.begin(); it != c2.end(); it++){
		if(c1.find(*it) == c1.end()){
			cont2++;
		}
	}
	
	cout << min(cont, cont2)<< endl;
		
	return 0;
}