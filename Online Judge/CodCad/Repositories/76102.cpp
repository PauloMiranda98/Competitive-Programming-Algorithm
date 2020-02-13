#include <iostream>
#include <map>

using namespace std;

int main(){
	long int c, n;
	
	cin >> c >> n;
	
	map<long long int, long long int> mapa;
	map<long long int, long long int> res;
		
	for(long int i=0; i < c; i++){
		long long int chave;

		cin >> chave;		
		cin >> mapa[chave];
		
	}
	
	for(long int i=0; i < n; i++){
		long long int chave, valor;

		cin >> chave >> valor;		
	
		if(mapa[chave] < valor){
			res[chave] = valor;
			mapa[chave] = valor;
		}
	}	
	
	map<long long int, long long int>::iterator it;
	
	for(it = res.begin(); it != res.end(); it++)
		cout << it->first << " " << it->second << endl;
   
	return 0;
}