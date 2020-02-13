#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

//------------------------

#define MAXN 10001

struct Resultado{
	int veio;
	int nao;
	
	Resultado(){
		veio = 0;
		nao = 0;
	}
};

int maior = 0;

int componente[MAXN];
bool ver[MAXN];
Resultado veio[MAXN];
vector<int> lista[MAXN];

//------------------------

void bfs(int x){
	
	queue<int> fila;
	fila.push(x); // fila da nossa BFS
	
	componente[x] = 0;
		
	while(!fila.empty()){ // Enquanto a fila nao for vazia
		
		// vamos trabalhar com o primeiro da fila
		int v = fila.front();
		fila.pop(); // para movermos o elemento da fila
		
		for(int i = 0;i < (int)lista[v].size();i++){
			
			int u = lista[v][i];
			
			if(componente[u] == -1){
				componente[u] = componente[v] + 1;

				if(maior < componente[u])
					maior = componente[u];
					
				if(ver[u]){
					veio[componente[u]].veio++;
				}else{
					veio[componente[u]].nao++;				
				}
				
				fila.push(u);
			}
		}
	}
}


int main(){
	
	int n, m;
	
	cin>>n>>m;

	for(int i = 1;i <= n;i++){
		componente[i] = -1;
		ver[i] = false;
	}
	
	for(int i = 1;i <= n;i++){

		int a;		
		cin >> a;

		lista[a].push_back(i);
	}
	
	for(int i = 1;i <= m;i++){
		int a;		
		cin >> a;
		
		ver[a] = true;
	}
	
	cout.precision(2);
	cout << fixed;
	
	bfs(0);
	
	for(int i=1; i<=maior; i++){
		cout << (100.0 * veio[i].veio)/(veio[i].veio + veio[i].nao) << " ";
	}
	
	cout<<"\n";
	
	return 0;
}
