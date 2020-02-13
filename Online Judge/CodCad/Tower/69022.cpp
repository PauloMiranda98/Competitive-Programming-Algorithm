#include <iostream>
#include <string.h>
#include <stdio.h>
 
int matriz[1000][1000];
int linha[1000];
int coluna[1000];

using namespace std;

int main() {

	int n;
	cin >> n;
	
	int maior = 0;
	memset(linha, 0, sizeof(linha));
	memset(coluna, 0, sizeof(coluna));
	
	for(int i=0; i<n; i++){		
		for(int j=0; j<n; j++){
			cin >> matriz[i][j];
			
			linha[i] += matriz[i][j];
			coluna[j] += matriz[i][j];			
		}
	}
	
	for(int x=0; x<n; x++)
		maior += matriz[0][x] + matriz[x][0];
	maior -= 2*matriz[0][0];
	   	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int s= linha[i] + coluna[j] - 2* matriz[i][j];
						
			if(s > maior)
				maior = s;
		}
	}
		
		
	cout << maior << endl;
	    
    return 0;
}