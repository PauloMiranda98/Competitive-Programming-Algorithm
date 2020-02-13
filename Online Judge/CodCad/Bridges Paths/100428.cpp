#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAXN 10100
#define INFINITO 999999999

using namespace std;

typedef pair<int, int> pii;

int n, m;
int distancia[MAXN];
int processado[MAXN];
vector<pii> vizinhos[MAXN];

void Dijkstra(int S){
	
	for(int i = 0;i <= n;i++) 
		distancia[i] = INFINITO; 
	
	distancia[S] = 0;                                  
	
	priority_queue< pii, vector<pii>, greater<pii> > fila; 
	fila.push( pii(distancia[S], S) );                     
		
	while(!fila.empty()){
		pii atual = fila.top();
		fila.pop();
		
		int dist_v = atual.first;
		int v = atual.second;
		
		for(int i = 0; i < (int)vizinhos[v].size(); i++){
			
			int dist_u  = vizinhos[v][i].first;
			int u = vizinhos[v][i].second;
			
			if( distancia[u] > dist_v + dist_u ){  
				distancia[u] =  dist_v + dist_u;    
				fila.push( pii(distancia[u], u) );     
			}
		}
		
	}
	
}

int main(){
	
	cin >> n >> m;

	n++;
	
	for(int i = 1;i <= m;i++){
		
		int x, y, tempo;
		cin >> x >> y >> tempo;
		
		vizinhos[x].push_back( pii(tempo, y) );
		vizinhos[y].push_back( pii(tempo, x) );
	}
	
	Dijkstra(0); 
	cout << distancia[n] << endl; 
	
	return 0;
}
