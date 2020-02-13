#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef unsigned long int uli;

#define PB push_back // por simplicidade

unordered_map<long int, long int> conteiner;
vector<long int> s[1000010];

long int lis(vector<long int> &v){
	
	vector<long int> pilha; // declaro o vector que guardara o topo de cada pilha
	
	// para cada elemento v[i] da sequencia
	for(long int i=0; i<(long int)v.size(); i++){
		
		// declaro um iterador que guardara o elemento mais a esquerda de pilha
		// que nao e menor que v[i]
		vector<long int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);
		
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

int main() {
	long int m, n;
	cin >> n >> m;
		
	for (long int i = 0; i < n; i++){
		long int x;
		cin >> x;
		
		conteiner[x] = i;
	}
	
	unordered_map<long int, long int>::const_iterator it;
	
	for (long int i = 0; i < m; i++){
		long int x;
		cin >> x;
		
		it = conteiner.find(x);
		
		if(it != conteiner.end())
			s[it->second].push_back(i);
	}
	
	vector<long int> res;
	
	for (long int i = 0; i < n; i++){
		for(long int j = s[i].size() - 1; j >= 0; j--){
			res.push_back(s[i][j]);
		}
	}
	
	cout << lis(res) << endl;
	
	return 0;
	
}
