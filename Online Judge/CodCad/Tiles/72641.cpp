#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int matriz[202][202];
bool acessado[202][202];

int bfs(int x, int y){
	int cont = 0;
	
	int v = matriz[x][y];
	
	queue< pair<int, int> > fila;
	fila.push( make_pair(x, y) );
	acessado[x][y] = true;

	while(!fila.empty()){
		pair<int, int> f = fila.front();
		fila.pop();		
		cont++;
			
		if((!acessado[f.first][f.second+1]) && (matriz[f.first][f.second+1] == v) ){
			
			fila.push( make_pair(f.first, f.second+1) );
			acessado[f.first][f.second+1] = true;
			
		}
		
		if((!acessado[f.first][f.second-1]) && (matriz[f.first][f.second-1] == v) ){
			
			fila.push( make_pair(f.first, f.second-1) );
			acessado[f.first][f.second-1] = true;
			
		}
		
		if((!acessado[f.first+1][f.second]) && (matriz[f.first+1][f.second] == v) ){
			
			fila.push( make_pair(f.first+1, f.second) );
			acessado[f.first+1][f.second] = true;
			
		}

		if((!acessado[f.first-1][f.second]) && (matriz[f.first-1][f.second] == v) ){
			
			fila.push( make_pair(f.first-1, f.second) );
			acessado[f.first-1][f.second] = true;
			
		}
			
	}

	return cont;
}

int main(){
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	
	cin >> n >> m;
	
	for(int i=0; i <=m+1; i++){
		acessado[0][i] = true;
		acessado[n+1][i] = true;	
	}	
	
	for(int i=0; i <=n+1; i++){
		acessado[i][0] = true;
		acessado[i][m+1] = true;	
	}	
	
	for(int i=1; i <=n; i++){
		for(int j=1; j <=m; j++){
			acessado[i][j] = false;
		}
	}	

	for(int i=1; i <=n; i++){
		for(int j=1; j <=m; j++){
			cin >> matriz[i][j];			
		}
	}	

	int menor = 40001;
	
	for(int i=1; i <=n; i++){
		for(int j=1; j <=m; j++){		
			if(!acessado[i][j]){
				int v = bfs(i, j);
				
				if(v < menor)
					menor = v;
			}
		}		
	}
	
	cout <<  menor << endl;
														 			   				
	return 0;
	
}   
   
