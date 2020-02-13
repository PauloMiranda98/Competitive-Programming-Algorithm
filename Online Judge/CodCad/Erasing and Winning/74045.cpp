#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
	
int main(){
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	
	cin >> n >> m;

	while(n || m){	
		vector<char> pilha;
		
		char x;
		string r;
		
		while(n--){
			cin >> x;
			
			while( (!pilha.empty()) && ( x > pilha.back()) && (m > 0) ){
				pilha.pop_back();
				m--;
			}
			
			pilha.push_back(x);
						
		}
		while(m>0){
			pilha.pop_back();
			m--;
		}
			
		for(int i=0; i < (int)pilha.size(); i++){
			cout << pilha[i];			
		}
			
		cout << endl;
		
		cin >> n >> m;
	}
		   				
	return 0;
}   
