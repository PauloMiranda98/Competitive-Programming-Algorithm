#include <iostream>
#include <queue>
#include <map>
#include <stdio.h>
 
using namespace std;

int main() {

	int matriz[10][10];
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> matriz[i][j];
		}
	}
	
	bool magico = true;
	int soma = 0;
	
	for(int j=0; j<n; j++){
		soma += matriz[0][j];
	}
	
	for(int i=1; i<n; i++){
		int s=0;
		for(int j=0; j<n; j++){
			s += matriz[i][j];
		}
		if(s != soma)
			magico = false;
	}

	for(int i=0; i<n; i++){
		int s=0;
		for(int j=0; j<n; j++){
			s += matriz[j][i];
		}
		if(s != soma)
			magico = false;
	}

	int s=0;
	for(int i=0; i<n; i++){
			s += matriz[i][i];
	}
	
	if(s != soma)
		magico = false;
	s = 0;
		
	for(int i=0; i<n; i++){
			s += matriz[i][n-1-i];
	}
	
	if(s != soma)
		magico = false;
	
	if(magico)
		cout << soma << endl;
	else
		cout << "-1" << endl;
	
	    
    return 0;
}