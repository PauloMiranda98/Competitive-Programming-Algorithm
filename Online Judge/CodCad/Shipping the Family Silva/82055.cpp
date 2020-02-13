#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;   // para nao termos que digitar pair<int, int> varias vezes,
                              // fazemos isso para deixar o codigo mais organizado

//---------------------
#define MAXN 1010
// como nao existe o Infinito no computador, usaremos um numero bem grande
#define INFINITO 999999999

int n, m;                      // numero de vertices e arestas
int distancia[MAXN];           // o array de distancias a fonte
int processado[MAXN];          // o array que guarda se um vertice foi processado
vector<pii> vizinhos[MAXN];    // nossas listas de adjacencia. O primeiro elemento do par representa a distancia e o segundo representa o vertice
//---------------------

int Prim(){
	
	for(int i = 1;i < n;i++) distancia[i] = INFINITO; // definimos todas as distancias como infinito, exceto a de S = 1.
	distancia[0] = 0;                                  // Assim, garantimos que o primeiro vertice selecionado sera o proprio 1.
	
	priority_queue< pii, vector<pii>, greater<pii> > fila; // Criamos uma fila de prioridade onde o menor fica no topo.
	fila.push( pii(distancia[0], 0) );                     // Como se pode ver, colocamos o primeiro elemento como seja a distancia do
	                                                       // vertice a Arvore Geradora Minima e o segundo como sendo o proprio vertice
	
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
			
			// A nova possivel distancia e dist.
			// Comparamos isso com distancia[atual].
			// Porem, e importante checar se o vertice atual nao foi processado ainda
			
			if( distancia[atual] > dist && !processado[atual]){  // vemos que vale a pena usar o vertice davez
				distancia[atual] = dist;                         // atualizamos a distancia
				fila.push( pii(distancia[atual], atual) );       // inserimos na fila de prioridade
			}
		}
	}
	
	int custo_arvore = 0;
	
	for(int i = 0;i < n;i++) custo_arvore += distancia[i];
	
	return custo_arvore;
}

int main(){
	
	cin >> n >> m;
	
	for(int i = 1;i <= m;i++){
		
		int x, y, tempo;
		cin >> x >> y >> tempo;
		
		vizinhos[x].push_back( pii(tempo, y) );
		vizinhos[y].push_back( pii(tempo, x) );
	}
	
	cout << Prim() << endl; // imprimimos a resposta
	
	return 0;
}