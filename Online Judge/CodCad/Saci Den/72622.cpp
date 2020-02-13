#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int matriz[1002][1002];
bool acesso[1002][1002];
int dist[1002][1002];

int menor(int x, int y){

	for(int i=1; i <= 1000; i++){
		for(int j=1; j <= 1000; j++){
			acesso[i][j] = false;
			dist[i][j] = ~(1<<31);
		}
	}
	
	acesso[x][y] = true;
	dist[x][y] = 1;
	
	queue< pair<int,int> > fila;
	fila.push( make_pair(x,y) );

	while(!fila.empty()){
		pair<int, int> f = fila.front();
		fila.pop();
		
		if(matriz[f.first][f.second] == 2){
			return dist[f.first][f.second];			
		}
		
		if(matriz[f.first][f.second-1]){
			if(!acesso[f.first][f.second-1]){
				dist[f.first][f.second-1] = dist[f.first][f.second] + 1;
				acesso[f.first][f.second-1] = true;
				fila.push( make_pair(f.first,f.second-1) );
			}
		}
		
		if(matriz[f.first][f.second+1]){
			if(!acesso[f.first][f.second+1]){
				dist[f.first][f.second+1] = dist[f.first][f.second] + 1;
				acesso[f.first][f.second+1] = true;
				fila.push( make_pair(f.first,f.second+1) );
			}			
		}
		
		if(matriz[f.first-1][f.second]){
			if(!acesso[f.first-1][f.second]){
				dist[f.first-1][f.second] = dist[f.first][f.second] + 1;
				acesso[f.first-1][f.second] = true;
				fila.push( make_pair(f.first-1,f.second) );
			}			
		}
		
		if(matriz[f.first+1][f.second]){
			if(!acesso[f.first+1][f.second]){
				dist[f.first+1][f.second] = dist[f.first][f.second] + 1;
				acesso[f.first+1][f.second] = true;
				
				fila.push( make_pair(f.first+1,f.second) );
			}			
		}
				
	}
	
	return 0;
}

int main(){
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, x, y;
	
	cin >> n >> m;

	for(int i=0; i <= m+1; i++){
		matriz[0][i] = 0;
		matriz[n+1][i] = 0;		
	}
	
	for(int i=0; i <= n+1; i++){
		matriz[i][0] = 0;
		matriz[i][m+1] = 0;		
	}

	for(int i=1; i <=n; i++){
		for(int j=1; j <= m; j++){
			cin >> matriz[i][j];	
			
			if(matriz[i][j] == 3){
				x = i;
				y = j;
			}
			
		}
	}
			
	cout <<  menor(x, y) << endl;
														 			   				
	return 0;
	
}   
   
