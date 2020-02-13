#include <vector>
#include <queue>
#include <iostream>
using namespace std;
//------------------------------
#define MAXN 100100
int n; // numero de vertices
int m; // numero de arestas
vector<int> grafo[MAXN];
int grau[MAXN] = {0};

priority_queue<int, vector<int>, greater<int> > fila;
vector<int> lista; // dos vertices de grau zero
//------------------------------
int main(){
	
	cin >> n >> m;

	for(int i = 1;i <= m;i++){
		int x, y;
		cin >> x >> y;

		// tarefa X tem que ser executada antes da tarefa Y
		grau[y]++;
		grafo[x].push_back(y);
	}
	
	for(int i = 0;i < n;i++) if(grau[i] == 0) fila.push(i);
	
	// o procedimento a ser feito e semelhante a uma BFS
	
	while( !fila.empty()){

		int atual = fila.top();
		fila.pop();
		
		lista.push_back(atual);
		
		for(int i = 0;i < (int)grafo[atual].size();i++){
			int v = grafo[atual][i];
			grau[v]--;
			if(grau[v] == 0) fila.push(v); // se o grau se tornar zero, acrescenta-se a lista
		}
	}

	// agora, se na lista nao houver N vertices,
	// sabemos que e impossivel realizar o procedimento

	if((int)lista.size() < n) cout << "*" << endl;
	else{
		for(int i = 0;i < (int)lista.size();i++) cout << lista[i] << endl;
	}
	
	return 0;
}