#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXL    20
#define MAXN 50500

int n;
int c[MAXN];
int par[MAXN];

int pai[MAXN];
int nivel[MAXN];
int ancestral[MAXN][MAXL];

vector<int> lista[MAXN];

void dfs(int u){
	
	for(int i = 0;i < (int)lista[u].size();i++){
		int v = lista[u][i];
		
		if(nivel[v] == -1){
			pai[v] = u;
			nivel[v] = nivel[u]+1;
			
			dfs(v);
		}
	}
	
}

int LCA(int u, int v){
	
	if(nivel[u] < nivel[v]) swap(u, v);
	
	for(int i = MAXL-1;i >= 0;i--)
		if(nivel[u] - (1<<i) >= nivel[v])
			u = ancestral[u][i];
	
	if(u == v) return u;
	
	for(int i = MAXL-1;i >= 0;i--)
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
			
	return pai[u];
}

int main(){
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		
		// isto e somente para definir os pares de cartas
		if(c[x]){
			par[i] = c[x];
			par[c[x]] = i;
		}
		c[x] = i;
	}
	
	for(int i = 1;i < n;i++){
		int a, b;
		cin >> a >> b;
		
		// montar a lista
		lista[a].push_back(b);
		lista[b].push_back(a);
	}
	
	// inicializacoes
	for(int i = 0;i < MAXN;i++) pai[i] = nivel[i] = -1;

	for(int i = 0;i < MAXN;i++)
		for(int j = 0;j < MAXL;j++)
			ancestral[i][j] = -1;
	
	// descobrir o pai e o nivel de todo mundo
	nivel[1] = 0;
	dfs(1);
	
	// montar tabela de ancestral
	for(int i = 1;i <= n;i++) ancestral[i][0] = pai[i];
	
	for(int j = 1;j < MAXL;j++)
		for(int i = 1;i <=   n;i++)
			ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
	
	// agora, sim, calcular a resposta
	long long resposta = 0LL;
	for(int i = 1;i <= n;i++)
		resposta += (long long)( nivel[i] + nivel[par[i]] - 2*nivel[ LCA(i, par[i]) ]);
	
	// dividimos por 2 porque calculamos cada distancias duas vezes
	cout << resposta/2 << endl;
	
	return 0;
}
