#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXL    20
#define MAXN 100100
typedef long long int lli;
long n, t;

long pai[MAXN];
long nivel[MAXN];
lli distancia[MAXN];
long ancestral[MAXN][MAXL];

vector<pair<lli, lli>> lista[MAXN];

void dfs(lli u){
	
	for(lli i = 0;i < (lli) lista[u].size();i++){
		pair<lli, lli> v = lista[u][i];
		
		if(nivel[v.first] == -1){
			pai[v.first] = u;
			nivel[v.first] = nivel[u]+ 1;
			distancia[v.first] = distancia[u] + v.second;
			
			dfs(v.first);
		}
	}
	
}

long LCA(lli u, lli v){
	
	if(nivel[u] < nivel[v]) swap(u, v);
	
	for(lli i = MAXL-1;i >= 0;i--)
		if(nivel[u] - (1<<i) >= nivel[v])
			u = ancestral[u][i];
	
	if(u == v) return u;
	
	for(lli i = MAXL-1;i >= 0;i--)
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
			
	return pai[u];
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n;
	while(n != 0){	
		for(lli i = 1;i <= n;i++)
			lista[i].clear();
			
		for(lli i = 2;i <= n;i++){
			lli a, l;
			cin >> a >> l;
			a++;
			// montar a lista
			lista[a].push_back(make_pair(i, l));
			lista[i].push_back(make_pair(a, l));
		}
		
		// inicializacoes
		for(lli i = 0;i < MAXN;i++) pai[i] = distancia[i] = nivel[i] = -1;

		for(lli i = 0;i < MAXN;i++)
			for(lli j = 0;j < MAXL;j++)
				ancestral[i][j] = -1;
		
		// descobrir o pai e o nivel de todo mundo
		nivel[1] = 0;
		distancia[1] = 0;
		dfs(1);
		
		// montar tabela de ancestral
		for(lli i = 1;i <= n;i++) ancestral[i][0] = pai[i];
		
		for(lli j = 1;j < MAXL;j++)
			for(lli i = 1;i <= n;i++)
				ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
		
		cin >> t;
		
		lli resposta;
		for(int i = 1;i <= t;i++){
			lli a, b;
			cin >> a >> b;
			a++;
			b++;
			resposta = (lli)( distancia[a] + distancia[b] - 2*distancia[ LCA(a, b) ]);
			cout << resposta << " ";
		}
		
		cout << endl;
		
		cin >> n;
	}
	
	return 0;
}
