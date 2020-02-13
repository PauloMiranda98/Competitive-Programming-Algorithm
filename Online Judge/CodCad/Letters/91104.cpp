#include <iostream> // lower_bound
#include <algorithm> // lower_bound
#include <vector> // vector

using namespace std;

#define PB push_back // por simplicidade

long int lis(string &v){
	
	vector<char> pilha; // declaro o vector que guardara o topo de cada pilha
	
	// para cada elemento v[i] da sequencia
	for(long int i=0; i< (long int) v.size(); i++){
		
		// declaro um iterador que guardara o elemento mais a esquerda de pilha
		// que nao e menor que v[i]
		vector<char>::iterator it = upper_bound(pilha.begin(), pilha.end(), v[i]);
		
		// se it for o fim do vector, entao nao ha elemento que nao seja menor que v[i]
		// ou seja, todos os topos de pilha sao menores ou iguais a v[i]
		
		// logo, criamos uma nova pilha e colocamos x no seu topo
		if(it==pilha.end()) pilha.PB(v[i]);
		
		// porem, se it apontar para alguma posicao valida do vector
		// colocamos v[i] no topo desta pilha, substintuindo o valor que it aponta por v[i]
		else *it = v[i];
	}
	
	return pilha.size();
}

int main(){
	string texto;
	cin >> texto;
	
	cout << lis(texto) << endl;
	
}
