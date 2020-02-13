#include <iostream>
#include <algorithm>

using namespace std;

struct Medalha{
	   int o;
	   int p;
	   int b;
	   
	   Medalha(){
		   o = 0;
		   p = 0;
		   b = 0;
	   }	
};


bool compara(pair<Medalha, int> a, pair<Medalha, int> b){
	
	if(a.first.o == b.first.o){
		if(a.first.p == b.first.p){
			if(a.first.b == b.first.b){
				return (a.second < b.second);
			}else{
				return (a.first.b > b.first.b);
			}
		}else{
			return (a.first.p > b.first.p);
		}
	}else{
		return (a.first.o > b.first.o);
	}
}


int main(){
	pair<Medalha, int> vetor[102];

	int n, m;	
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		vetor[i].second = i;
		vetor[i].first.o = 0;	
		vetor[i].first.p = 0;	
		vetor[i].first.b = 0;	
	}
	
	for(int j=1; j<=m; j++){
		int a, b, c;
		cin >> a >> b >> c;
		
		vetor[a].first.o += 1;	
		vetor[b].first.p += 1;	
		vetor[c].first.b += 1;			
	}
	
	sort(vetor+1, vetor+n+1, compara);
	
	cout << vetor[1].second;
	
	for(int i=2; i<=n; i++){
		cout << " " << vetor[i].second;
	}
			
	cout << endl;
	
	return 0;
}