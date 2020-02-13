#include <iostream> // lower_bound
#include <algorithm> // lower_bound
#include <vector> // vector

using namespace std;

#define PB push_back // por simplicidade

vector<long int> lis(vector<long int> &v){
	
	vector<long int> pilha, res(v.size()); // declaro o vector que guardara o topo de cada pilha
	
	// para cada elemento v[i] da sequencia
	for(long int i=0; i< (long int) v.size(); i++){
		
		// declaro um iterador que guardara o elemento mais a esquerda de pilha
		// que nao e menor que v[i]
		vector<long int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);
		
		// se it for o fim do vector, entao nao ha elemento que nao seja menor que v[i]
		// ou seja, todos os topos de pilha sao menores ou iguais a v[i]
		
		// logo, criamos uma nova pilha e colocamos x no seu topo
		if(it==pilha.end()){ 
			pilha.PB(v[i]);
			
			res[i] = pilha.size();
		}else{
			 *it = v[i];
			res[i] = (it - pilha.begin() + 1);
		}
	}
	
	return res;
	
}

vector<long int> lis2(vector<long int> &v){
	
	vector<long int> pilha, res(v.size()); // declaro o vector que guardara o topo de cada pilha
	
	// para cada elemento v[i] da sequencia
	for(long int i= (long int)v.size() - 1; i >= 0; i--){
		
		// declaro um iterador que guardara o elemento mais a esquerda de pilha
		// que nao e menor que v[i]
		vector<long int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);
		
		// se it for o fim do vector, entao nao ha elemento que nao seja menor que v[i]
		// ou seja, todos os topos de pilha sao menores ou iguais a v[i]
		
		// logo, criamos uma nova pilha e colocamos x no seu topo
		if(it==pilha.end()){ 
			pilha.PB(v[i]);
			
			res[i] = pilha.size();
		}else{
			 *it = v[i];
			res[i] = (it - pilha.begin() + 1);
		}
	}
	
	return res;
	
}

int main(){
	long int m = 0; 
	long int n;
	cin >> n;
	
	vector<long int> v(n);
	
	for(long int i=0; i<n; i++)
		cin >> v[i];
		
	vector<long int> res1, res2;
	res1 = lis(v);
	res2 = lis2(v);
	
	for(long int i = 0; i < n; i++){
		m = max(m, 2*min(res1[i],res2[i]) - 1);
	}
	
	
	cout << m << endl;
	
}
