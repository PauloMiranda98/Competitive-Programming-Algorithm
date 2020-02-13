#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int vetor[50001];

int main(){
	
	int n, m, i, x;
	set<int> casas;
	
	cin >> n;
	
	for(i=0; i < n; i++){
		cin >> vetor[i];
	}
	
	cin >> m;

  	for(i=0; i < m; i++){
		cin >> x;
		casas.insert(x);	   		
	}

	for(i=0; i < n; i++){
		set<int>::iterator a = casas.find(vetor[i]);
		if(a == casas.end()){
			cout << vetor[i];
			break;
        }else{
			casas.erase(a);			
		}		
	}

		
	for(i++; i < n; i++){
		set<int>::iterator a = casas.find(vetor[i]);
		if(casas.find(vetor[i]) == casas.end()){
			cout << " " << vetor[i];		
		}else{
			casas.erase(a);			
		}
	}
	
	cout << endl;
			    			 				   				
	return 0;
}   

