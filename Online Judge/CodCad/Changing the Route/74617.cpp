#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;   // para nao termos que digitar pair<int, int> varias vezes,
// fazemos isso para deixar o codigo mais organizado

//---------------------
#define MAXN 10100
// como nao existe o Infinito no computador, usaremos um numero bem grande
#define INFINITO 9999999

int n, m, c, k;                      // numero de vertices e arestas
long int distancia[MAXN];           // o array de distancias a fonte
bool processado[MAXN];          // o array que guarda se um vertice foi processado
vector<pii> vizinhos[MAXN];    // nossas listas de adjacencia. O primeiro elemento do par representa a distancia e o segundo representa o vertice
//---------------------


void Dijkstra(int S){
	
	for(int i = 0;i < n;i++){ 
		distancia[i] = INFINITO; // definimos todas as distancias como infinito, exceto a de S.
		processado[i] = false;		
	}
	
	distancia[S] = 0;  // Assim, garantimos que o primeiro vertice selecionado sera o proprio S.
	
	priority_queue< pii, vector<pii>, greater<pii> > fila; // Criamos uma fila de prioridade onde o menor fica no topo.
	fila.push( pii(distancia[S], S) );                     // Como se pode ver, colocamos o primeiro elemento como seja a distancia do
	// vertice a S e o segundo como sendo o proprio vertice
	
	while(true){ // rodar "infinitamente"
		
		int davez = -1;
				
		// selecionamos o vertice mais proximo
		while(!fila.empty()){
			
			int atual = fila.top().second;
			fila.pop();
			
			if(!processado[atual]){ // podemos usar esse vertice porque ele ainda nao foi processado
				davez = atual;
				break;
			}
			
			// se nao, continuamos procurando
		}
		
		if(davez == -1) break; // se nao achou ninguem, e o fim do algoritmo
		
		processado[davez] = true; // marcamos para nao voltar para este vertice
		
		// agora, tentamos atualizar as distancias
		for(int i = 0;i < (int)vizinhos[davez].size();i++){
			
			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;
			
			// A nova possivel distancia e distancia[davez] + dist.
			// Comparamos isso com distancia[atual]
			
			if( distancia[atual] > distancia[davez] + dist ){  // vemos que vale a pena usar o vertice davez
				distancia[atual] = distancia[davez] + dist;    // atualizamos a distancia
				fila.push( pii(distancia[atual], atual) );     // inserimos na fila de prioridade
			}
		}
	}
	
}

int main(){
	
	cin >> n >> m >> c >> k; 

	while(n || m || c || k){
		for(int i = 0;i < n;i++){ 
			vizinhos[i].clear();
		}
		
		for(int i = 1;i <= m;i++){
			
			int x, y, tempo;
			cin >> x >> y >> tempo;
			
			// Adicionamos as devidas arestas as devidas listas.
			// Vamos supor o grafo como bidirecional nesse problema, mas o algoritmo funciona tambem para grafos direcionados.
			if( (x < c) && (y < c)){
				if( ((x-y) == -1) || ((x-y) == 1) ){
					vizinhos[min(x,y)].push_back( pii(tempo, max(x,y)) );
				}
			}if( (x>=c) && (y >= c)){
				vizinhos[x].push_back( pii(tempo, y) );
				vizinhos[y].push_back( pii(tempo, x) );	
			}else{
				vizinhos[max(x,y)].push_back( pii(tempo, min(x,y)) );
			}
			
		}
		
		Dijkstra(k); // rodamos o Dijkstra
		cout << distancia[c-1] << endl; // imprimimos a resposta
		
		cin >> n >> m >> c >> k; 
	}
	return 0;
}
