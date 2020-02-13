#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

// defino os maiores valores de n e s como 1010
#define MAXN 51
#define MAXS 1010

// declaro as variaveis que a funcao utiliza
long int n, valor[MAXN], peso[MAXN], tab[MAXN][MAXS];

int knapsack(long int obj, long int aguenta){
	
	// se ja calculamos esse estado da dp, retornamos o resultado salvo
	if(tab[obj][aguenta]>=0) return tab[obj][aguenta];
	
	// se nao houver mais objetos ou espaco na mochila, retorno 0, pois nao posso mais botar nada
	if(obj==n or !aguenta) return tab[obj][aguenta]=0;
	
	// nao colocar avanca para o estado em que tentmos o proximo, com o mesmo espaco disponivel
	int nao_coloca=knapsack(obj+1, aguenta);
	
	// se for possivel colocar o objeto
	if(peso[obj]<=aguenta){
		
		// o melhor atingivel e o valor dele mais o melhor entre colocar ou nao os proximos
		// que e o resultado do estado da dp em que olhamos o proximo objeto
		// mas agora a mpchila aguenta o que aguentava antes menos o peso que coloquei nela
		int coloca=valor[obj]+knapsack(obj+1, aguenta-peso[obj]);
		
		// e a funcao deve retornar o melhor entre colocar ou nao colocar
		return tab[obj][aguenta]=max(coloca, nao_coloca);
	}
	
	// se a funcao nao retornou ainda, entao ela nao entrou no if
	// logo nao era possivel colocar o objeto 
	return tab[obj][aguenta]=nao_coloca; // entao retorno o valor de nao coloca-lo
}

int main(){
	
	long int cont = 1;
	long int aguenta;
	
	cin >> aguenta >> n;
	
	while(aguenta || n){	
			
		memset(tab, -1, sizeof(tab));
		
		for(long int i=0; i < n; i++)
			cin >> peso[i] >> valor[i] ;
		 
		cout << "Teste " << (cont++) << endl;
		cout << knapsack(0, aguenta)  << endl << endl;
		
		cin >> aguenta >> n;
	}
		
	return 0;
}