#include <iostream>
#include <cstdio>
#include <sstream>
#include <map>

using namespace std;

string vetor[1001];

int main(){
	long int t;
	cin >> t;
	
	while(t--){
		long int c, n;
		
		cin >> c >> n;
		
		map<string, string> mapa;
		map<string, string> res;
			
		cin.ignore();
			
		for(long int i=0; i < c; i++){
			string chave, valor;
			char aux[80];
			
			getline(cin, chave);					
			getline(cin, valor);
					
			mapa[chave] = valor;
			
		}
		
		for(long int i=0; i < n; i++){
			string texto;
			stringstream ss;
			
			getline(cin, texto);
			
			ss << texto;
	
			string s;
			
			while( ss >> s){
				if(mapa.find(s) != mapa.end())
					cout << mapa[s] << " ";
				else
					cout << s << " ";
			}
			
			cout << endl;
			
	    }	
	    cout << endl;
	}
	return 0;
}