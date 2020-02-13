#include <vector>
#include <set>
#include <iostream>
#define MAXN 100100

using namespace std;

long int n;
long int m;

vector<long int> grafo[MAXN];
set< pair<long int, long int> > memo[MAXN];
long int soma[MAXN];

long int grau[MAXN];
vector<long int> lista;

int main(){
	
	long int minimo = 99999999;
	
	cin >> n;
	
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;

		grau[x]++;
		grau[y]++;
		
		grafo[x].push_back(y);
		grafo[y].push_back(x);
	}
		
	for(int i = 1;i <= n;i++){ 
		if(grau[i] == 1){
			lista.push_back(i);
			memo[i].insert(make_pair(0, i));
		}
	}
	
	int ini = 0;
	
	while(ini < (int)lista.size()){

		int atual = lista[ini];
		
		ini++;
		
		for(long v : grafo[atual]){
			
			if(grau[v] > 0){
				long int i=0;
				for(auto it = memo[atual].begin(); it != memo[atual].end(); it++){
					memo[v].insert( make_pair(it->first + 1, atual) );	
					i++;
					if(i == 3)
						break;
				}
			}
			
			grau[v]--;
			if(grau[v] == 1) 
				lista.push_back(v);
		}
		
		grau[atual] = 0;
	}
	
	for(int i = 1;i <= n;i++){ 
		
		if(memo[i].size() >= 2){
			auto it = memo[i].begin();
			it++;
			 
			minimo = min(minimo, (memo[i].begin())->first + it->first);
		}
		
	}	
	
	cout << minimo << endl;
	
	
	return 0;
}
