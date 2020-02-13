#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> matriz[100001];
bool acessado[100001];

void bfs(int x){
		
	queue< int > fila;
	fila.push( x );

	while(!fila.empty()){
		int f = fila.front();
		fila.pop();		
					
		for(int i=0; i< ((int)matriz[f].size()); i++){
			
			if(!acessado[ matriz[f][i] ]){
				
				fila.push(matriz[f][i]);
				acessado[ matriz[f][i] ] = true;
				
			}
			
		}
		
			
	}
	
}

int main(){
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, x, y;
	
	cin >> n >> m;
	
	for(int i=1; i <=n; i++){
		acessado[i] = false;
	}	
	
	for(int i=1; i <=m; i++){
		cin >> x >> y;
		
		matriz[x].push_back(y);
		matriz[y].push_back(x);
	}
	
	int cont = 0;
	
	for(int i=1; i <=n; i++){
		
		if(!acessado[i]){
			bfs(i);
			cont++;
		}
		
	}
	
	cout <<  cont << endl;
														 			   				
	return 0;
	
}   
   
