#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;
	
int main(){
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int i, j, n;
	int ver = 1;
	stack<char> pilha;
	
	cin >> n;
	
	char texto[101];
	while(cin.getline(texto, 101)){
		
		for(j=0; texto[j]; j++){
			
			if(texto[j] == '{'){
				pilha.push(texto[j]);
			}else if(texto[j] == '}'){
				if(!pilha.empty()){
					pilha.pop();
				}else{
					ver = 0;
					break;
				}
			}			
		}
			   		
  	}
	
	if(pilha.size() > 0) 
		ver = 0;
	
	if(ver)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
		 				   				
	return 0;
}   
