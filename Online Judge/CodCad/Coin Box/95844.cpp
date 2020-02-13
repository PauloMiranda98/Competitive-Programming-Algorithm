#include <iostream>
#define MAX 100010
using namespace std;

long int arvore[4*MAX];
long int lazy[4*MAX];
long int versao[4*MAX];
long int vetor[MAX];

void construir(int no, int i, int j){ 
	
	int esquerda = 2*no;     // indice do filho da esquerda
	int direita  = 2*no + 1; // indice do filho da direita
	int meio = (i + j)/2;
			
	if( i == j){ // se a operacao cobre o no inteiro		
		arvore[no] = vetor[i];
	}else{ // caso a operacao atualize apenas alguns valores do no, chamamos a funcao nos dois filhos
		
		construir(esquerda,      i, meio); // atualizamos o filho da esquerda
		construir( direita, meio+1,    j); // atualizamos o filho da direita
		
		arvore[no] = arvore[esquerda] + arvore[direita]; // atualizamos o no que estamos
	}	
}


void atualiza(int no, int i, int j, int a, int b, int valor){ 
	
	int esquerda = 2*no;     // indice do filho da esquerda
	int direita  = 2*no + 1; // indice do filho da direita
	int meio = (i + j)/2;
	
	if(lazy[no]){ // se existirem operacoes atrasadas a serem feitas, temos que faze-las agora
		
		arvore[no] = lazy[no]*(j - i + 1); // ja que somamos lazy[no] a cada valor de i a j, fazemos isso (j-i+1) vezes
		
		if(i != j){ // se i != j, o no possui descendentes e temos que atualizar o valor de lazy deles
			lazy[direita]  = lazy[no];
			lazy[esquerda] = lazy[no];
		}
		
		lazy[no] = 0; // agora que realizamos as operacoes devidas, zeramos novamente o valor de lazy[no]
	}
	
	if(i > j || i > b || a > j) return; // se a atualizacao que vamos fazer nao afeta esse no, encerramos a funcao
	
	if(a <= i && j <= b){ // se a operacao cobre o no inteiro
		
		arvore[no] = valor*(j-i+1); // atualizamos o valor do no
		
		// se o no possui descendentes, atualizamos o valor de lazy de cada um deles
		// em vez de chamar a funcao recursiva. Isso e o que otimiza nosso tempo de execucao
		if(i != j){
			lazy[direita] = valor;
			lazy[esquerda] = valor;
		}	
	}
	
	else{ // caso a operacao atualize apenas alguns valores do no, chamamos a funcao nos dois filhos
		
		atualiza(esquerda,      i, meio, a, b, valor); // atualizamos o filho da esquerda
		atualiza( direita, meio+1,    j, a, b, valor); // atualizamos o filho da direita
		
		arvore[no] = arvore[esquerda] + arvore[direita]; // atualizamos o no que estamos
	}
	
}


// queremos saber a soma de todos os valores de indice no intervalo [A, B]
int consulta(int no, int i, int j, int a, int b){
	
	int esquerda = 2*no;     // indice do filho da esquerda
	int direita  = 2*no + 1; // indice do filho da direita
	int meio = (i + j)/2;
	
	if(lazy[no]){ // se existirem operacoes atrasadas a serem feitas, temos que faze-las agora
		
		arvore[no] = lazy[no]*(j - i + 1); // ja que somamos lazy[no] a cada valor de i a j, fazemos isso (j-i+1) vezes
		
		if(i != j){ // se i != j, o no possui descendentes e temos que atualizar o valor de lazy deles
			lazy[direita]  = lazy[no];	
			lazy[esquerda] = lazy[no];
		}
		
		lazy[no] = 0; // agora que realizamos as operacoes devidas, zeramos novamente o valor de lazy[no]
	}
	
	if(i > j || i > b || a > j) return 0; // [i, j] e [a, b] sao disjuntos, retornamos 0
	
	if(a <= i && j <= b) // se [i, j] esta contido em [a, b], retornamos o valor do no inteiro
		return arvore[no];
		
	else{ // retornamos entao a soma da funcao chamada nos dois descendentes
		
		int soma_esquerda = consulta(esquerda,      i, meio, a, b);
		int soma_direita  = consulta( direita, meio+1,    j, a, b);
		
		return soma_esquerda + soma_direita;
	}
}

int main(){
	long int n, k;
	cin >> n >> k;
	for(long int i=1; i<=n; i++)
		cin >> vetor[i];
		
	construir(1, 1, n);
	
	for(long int i=1; i<=k; i++){
		long int o, a, b, k;
		
		cin >> o;
		
		if(o == 1){
			cin >> a >> b >> k;
			atualiza(1, 1, n, a, b, k);
		}else{
			cin >> a >> b;
			cout << consulta(1, 1, n, a, b);
		}
		
	}

	return 0;
}
