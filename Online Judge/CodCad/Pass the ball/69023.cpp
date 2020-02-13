#include <iostream>
#include <string.h>
#include <stdio.h>
 
struct P{
	int valor;
	bool visitado;	
	
	P(){
		visitado = false;
	}
};
 
P matriz[100][100];
int n;
using namespace std;

int funcao(int i, int j, int v){
	
	if( (i == n) || (j == n) ||(i == -1) || (j == -1))
		return 0;
	if(matriz[i][j].visitado)
		return 0;
	if(v > matriz[i][j].valor)
		return 0;
	
	matriz[i][j].visitado = true;
		
	return 1 + funcao(i, j+1, matriz[i][j].valor) + funcao(i+1, j, matriz[i][j].valor) + funcao(i, j-1, matriz[i][j].valor) + funcao(i-1, j, matriz[i][j].valor);
}

int main() {

	int l, c;
	cin >> n;
	cin >> l >> c;
		
	for(int i=0; i<n; i++){		
		for(int j=0; j<n; j++){
			cin >> matriz[i][j].valor;
		}
	}
				
	cout << funcao(l-1, c-1, 0) << endl;
	    
    return 0;
}