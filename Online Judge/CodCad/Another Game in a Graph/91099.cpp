#include <bits/stdc++.h>
#define MAX 100010

using namespace std;
typedef long int li;

li peso[MAX];
li pai[MAX];

vector<li> grafo[MAX];
li PD[MAX][2];

li VertexCover(li x, bool escolhido){
	
	if(PD[x][escolhido] != -1) 
		return PD[x][escolhido]; // se ja calculamos esse caso, retornamos o valor para evitar recalculo
		                            // nao se esqueca de, nao funcao main, inicializar todos os valores de PD como -1.
	
	li caso1 = peso[x], caso2 = 0;
	
	for(li i = 0;i < (li)grafo[x].size();i++){ // percorremos todos os vizinhos de X
		
		int v = grafo[x][i];
		
		if(v == pai[x]) continue; // checamos se V e o pai de X
		
		// agora, sabemos que V e um filho de X
		pai[v] = x; // definimos o pai de V como sendo X
		caso1 += VertexCover(v, true);  // caso escolhamos colorir X
		caso2 += VertexCover(v, false); // caso escolhamos nao-colorir X
	}
	
	PD[x][false] = max(caso1, caso2);// caso o pai de X esteja colorido, escolhemos o melhor caso
	PD[x][true] = caso2;           // caso o pai de X nao seja colorido, escolhemos o caso1
	
	return PD[x][escolhido]; // retornamos o valor da resposta
}
int main() {
	li n, a, b;
	
	memset(PD, -1, sizeof(PD));
	memset(pai, -1, sizeof(pai));
	
	cin >> n;
	
	for (li i = 1; i < n; i++){
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	for (li i = 1; i <= n; i++){
		cin >> peso[i];
	}
	
	cout << VertexCover(1, false) << endl;
		
	return 0;
	
}
