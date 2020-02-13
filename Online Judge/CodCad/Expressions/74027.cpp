#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int diferenca(char c1, char c2){
	switch(c1){
		case '(':
			if(c2 == ')') return 0;
			else return 1;
		case '{':
			if(c2 == '}') return 0;
			else return 1;
		case '[':
			if(c2 == ']') return 0;
			else return 1;
        default:
        	return 0;
	}
}
	
int main(){
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int i, j, n;
	
	cin >> n;
	
	for(i=0; i < n; i++){
		
		int ver = 1;
		
		stack<char> pilha;
		char texto[100001];
		
		cin >> texto;
		
		for(j=0; texto[j]; j++){
			ver = 1;
			if(texto[j]== '{' || texto[j]== '(' || texto[j]== '['){
				pilha.push(texto[j]);
			}else{
				if((!pilha.empty()) && (!diferenca(pilha.top() , texto[j])) ){
					pilha.pop();
				}else{
					ver = 0;
					break;
				}
			}			
		}
		
		if(pilha.size() > 0 ) ver = 0;
		
		if(ver)
			cout << "S" << endl;
		else
			cout << "N" << endl;
	   		
  	}
		 				   				
	return 0;
}   
