#include <iostream>
#include <vector>
#include <cstring>

#define MAXN 100100

using namespace std;

long int n;
long int m;

long int grau[MAXN];
long int grafo[MAXN];
long int grupo[MAXN];
long int dis[MAXN];
long int pai[MAXN];
long int p;
long int tam;

long gerarCiclo(long v){
	long atual = 0;
	
	while(pai[v] == -1){
		atual++;
		pai[v] = atual;
		grupo[v] = -1;
		dis[v] = 0;
		v = grafo[v];
	}
	
	return atual;
}

long gerarGrupo(long v, long g){
	if(grupo[v] == -1){
		p = pai[v];
		return 1;
	 }

	dis[v] = gerarGrupo(grafo[v], g);	
	pai[v] = p;
	grupo[v] = g;
	
	return dis[v] + 1;
}

long distancia(long a, long b){

	if(a < b)
		return tam + a - b;
		
	return a - b;
}

int main(){
	long int gru = 0;
	
	memset(pai, -1, sizeof(pai));
	
	cin >> n;
	
	for(long i = 1; i <= n; i++){
		cin >> grafo[i];

		grau[grafo[i]]++;		
	}
	
	for(long i=1; i<=n; i++){
		if(grau[i] >= 2){
			tam = gerarCiclo(i);
			break;
		}
		
	}
	
	for(int i = 1;i <= n;i++){ 
		if(grau[i] == 0){
			gerarGrupo(i, gru++);
		}
	}
	
	cin >> m;
		
	for(long i = 1; i <= m; i++){
		long x, y;
		cin >> x >> y;
		
		if(grupo[x] == grupo[y] && grupo[x] != -1){
			cout << abs(dis[x] - dis[y]) << endl;
		}else{
			
			if( dis[x] > dis[y] + distancia(pai[x], pai[y]) ){
				cout << dis[x] << endl;
			}else if( dis[y] > dis[x] + distancia(pai[y], pai[x]) ){
				cout << dis[y] << endl;				
			}else{
				cout << min( dis[y] + distancia(pai[x], pai[y]), dis[x] + distancia(pai[y], pai[x]) ) << endl;
			}
			
		}

	}
	
	
	return 0;
}

/*
 * 
12
2 3 4 5 6 1 5 7 4 2 2 11


6
2 6 1 6 2 5
5
4 3
1 3
6 3
5 2
2 2

*/
