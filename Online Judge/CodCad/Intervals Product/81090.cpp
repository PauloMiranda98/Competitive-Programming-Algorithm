#include <iostream>
#include <algorithm>

#define MAX 100001

int arvore[100000001];
int acao[MAX];

int consulta(int no, int i, int j, int A, int B){
	
	if(A <= i && j <= B){ // primeiro caso: [i, j] esta contido em [A, B]
		return arvore[no];
	}
	
	if(i > B || A > j){ // segundo caso: [i, j] e [A, B] sao disjuntos (ou i > j, que significa um no invalido)
		return 1;
	}
	
	// terceiro caso: chamaremos a funcao nos dois filhos e retornaremos a melhor resposta
	int esquerda = 2*no;      // indice do filho da esquerda
	int direita  = 2*no + 1;  // indice do filho da direita
	
	int meio = (i + j)/2;
	
	// calculamos a resposta para cada filho
	int resposta_esquerda = consulta(esquerda, i, meio, A, B);
	int resposta_direita  = consulta(direita, meio+1, j, A, B);
	
	// retornamos a melhor resposta
	return resposta_esquerda * resposta_direita;
	
}

void atualiza(int no, int i, int j, int posicao, int novo_valor){ 
	
	if(i == j){ // se tivermos i = j, temos i = posicao = j. Logo, estamos no no mais baixo da avore
	
		// fazemos entao as alteracoes triviais
		if(novo_valor == 0)
			arvore[no] = 0;
		else if(novo_valor > 0)
			arvore[no] = 1;
		else
			arvore[no] = -1;
		
		acao[posicao] = novo_valor;
	}
	
	else{
		
		int esquerda = 2*no;     // indice do filho da esquerda
		int direita  = 2*no + 1; // indice do filho da direita
		
		// chamamos a funcao recursiva no no necessario
		int meio = (i + j)/2;
		
		// se (posicao <= meio), vamos para o no da esquerda (segmento [i, meio])
		if(posicao <= meio) atualiza(esquerda, i, meio, posicao, novo_valor);
		
		// se nao, vamos para o no da direita (segmento [meio+1, j])
		else atualiza(direita, meio+1, j, posicao, novo_valor);
		
		// agora, pegamos o melhor resultado entre os dois nos
		arvore[no] = arvore[esquerda]*arvore[direita];	

	}
	
}

using namespace std;

int main(){
	
	long int n, k;	
	long int x, y, res;
	char op;
	
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	while(cin >> n >> k){		
		for(long int i = 1; i <= n; i++){
			cin >> x;
			atualiza(1, 1, n, i, x);			
		}
		for(long int i = 1; i <= k; i++){
			cin >> op;
			cin >> x >> y;
			if(op == 'P'){
				res = consulta(1, 1, n, x, y);
				
				if(res > 0)
					cout << "+";
				else if(res < 0)
					cout << "-";
				else
					cout << "0";
			}else{
				atualiza(1, 1, n, x, y);
			}
		}
			
		cout << endl;
	}
	
	
		
	return 0;
}