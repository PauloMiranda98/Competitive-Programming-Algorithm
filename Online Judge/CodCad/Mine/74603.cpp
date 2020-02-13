#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> Cord;   // para nao termos que digitar pair<int, int> varias vezes,
typedef pair<int, Cord> pii;   // para nao termos que digitar pair<int, int> varias vezes,

// fazemos isso para deixar o codigo mais organizado

//---------------------
#define MAXN 101
// como nao existe o Infinito no computador, usaremos um numero bem grande
#define INFINITO 999

int n;                      // numero de vertices e arestas
int cidade_noic;               // cidade onde esta o Noic
int cidade_succa;              // cidade onde esta o Succa
int distancia[MAXN][MAXN];           // o array de distancias a fonte
int processado[MAXN][MAXN];          // o array que guarda se um vertice foi processado
int matriz[MAXN][MAXN];          // o array que guarda se um vertice foi processado
//---------------------

void Dijkstra(int a, int b){
	
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			distancia[i][j] = INFINITO; // definimos todas as distancias como infinito, exceto a de S.

	distancia[a][b] = 0;                                  // Assim, garantimos que o primeiro vertice selecionado sera o proprio S.
	
	priority_queue< pii, vector<pii>, greater<pii> > fila; // Criamos uma fila de prioridade onde o menor fica no topo.
	fila.push( pii(0, Cord(a,b)));                     // Como se pode ver, colocamos o primeiro elemento como seja a distancia do
	
	// vertice a S e o segundo como sendo o proprio vertice
	
	while(true){ // rodar "infinitamente"
		
		Cord davez(-1, -1);
				
		// selecionamos o vertice mais proximo
		while(!fila.empty()){
			
			Cord atual = fila.top().second;
			fila.pop();
			
			if(!processado[atual.first][atual.second]){ // podemos usar esse vertice porque ele ainda nao foi processado
				davez = atual;
				break;
			}
			
			// se nao, continuamos procurando
		}
		
		if(davez.first == -1) break; // se nao achou ninguem, e o fim do algoritmo
		
		processado[davez.first][davez.second] = true; // marcamos para nao voltar para este vertice
		
		
		Cord atual;
		int dist;
		
		atual = davez;
		atual.first -= 1;
		
		if( (atual.first >= 0) && (atual.first < n) && (atual.second >= 0) && (atual.second < n)){
			dist = matriz[atual.first][atual.second];
			
			if(!processado[atual.first][atual.second]){
				if( distancia[atual.first][atual.second] > distancia[davez.first][davez.second] + dist){  // vemos que vale a pena usar o vertice davez
					distancia[atual.first][atual.second] = distancia[davez.first][davez.second] + dist;    // atualizamos a distancia
					fila.push( pii(distancia[atual.first][atual.second], atual) );     // inserimos na fila de prioridade
				}
			}
		}
		
		atual = davez;
		atual.first += 1;
		
		if( (atual.first >= 0) && (atual.first < n) && (atual.second >= 0) && (atual.second < n)){
			dist = matriz[atual.first][atual.second];
			
			if(!processado[atual.first][atual.second]){
				if( distancia[atual.first][atual.second] > distancia[davez.first][davez.second] + dist){  // vemos que vale a pena usar o vertice davez
					distancia[atual.first][atual.second] = distancia[davez.first][davez.second] + dist;    // atualizamos a distancia
					fila.push( pii(distancia[atual.first][atual.second], atual) );     // inserimos na fila de prioridade
				}
			}
		}
		
		atual = davez;
		atual.second -= 1;
		
		if( (atual.first >= 0) && (atual.first < n) && (atual.second >= 0) && (atual.second < n)){
			dist = matriz[atual.first][atual.second];
			
			if(!processado[atual.first][atual.second]){
				if( distancia[atual.first][atual.second] > distancia[davez.first][davez.second] + dist){  // vemos que vale a pena usar o vertice davez
					distancia[atual.first][atual.second] = distancia[davez.first][davez.second] + dist;    // atualizamos a distancia
					fila.push( pii(distancia[atual.first][atual.second], atual) );     // inserimos na fila de prioridade
				}
			}
		}
		
		atual = davez;
		atual.second += 1;
		
		if( (atual.first >= 0) && (atual.first < n) && (atual.second >= 0) && (atual.second < n)){
			dist = matriz[atual.first][atual.second];
			
			if(!processado[atual.first][atual.second]){
				if( distancia[atual.first][atual.second] > distancia[davez.first][davez.second] + dist){  // vemos que vale a pena usar o vertice davez
					distancia[atual.first][atual.second] = distancia[davez.first][davez.second] + dist;    // atualizamos a distancia
					fila.push( pii(distancia[atual.first][atual.second], atual) );     // inserimos na fila de prioridade
				}
			}
		}
					
	}
	
}

int main(){
	
	cin >> n;
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> matriz[i][j];
		}		
	}
	
	Dijkstra(0,0); // rodamos o Dijkstra
	cout << distancia[n-1][n-1] << endl; // imprimimos a resposta
	
	return 0;
}
