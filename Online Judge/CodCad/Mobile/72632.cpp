#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> matriz[100001];
int memo_peso[100001];

int peso(int x){

	if(matriz[x].size() == 0){
		return memo_peso[x] = 1;
	}
	
	int p = 1;
	
	for(int i=0; i< ((int)matriz[x].size()); i++){
		p += peso(matriz[x][i]);
	}
	
	return memo_peso[x] = p;
}

string menor(int x){
		
	queue< int > fila;
	fila.push( x );

	while(!fila.empty()){
		int f = fila.front();
		fila.pop();
		
		if(matriz[f].size() > 0){
			
			fila.push(matriz[f][0]);
			
			int v = memo_peso[ matriz[f][0] ];
						
			for(int i=1; i< ((int)matriz[f].size()); i++){
				
				if(v != memo_peso[ matriz[f][i] ] ){
					return "mal";
				}
				
				fila.push(matriz[f][i]);
			}
		
		}
				
	}
	
	return "bem";
}

int main(){
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, y;
	
	cin >> n;
	
	memo_peso[0] = 0;
	
	for(int i=1; i <=n; i++){
		cin >> x >> y;
		
		matriz[y].push_back(x);
		memo_peso[i] = 0;
	}
	
	peso(0);
			
	cout <<  menor(0) << endl;
														 			   				
	return 0;
	
}   
   
