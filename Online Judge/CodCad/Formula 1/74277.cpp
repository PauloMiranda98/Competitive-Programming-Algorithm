#include <iostream>
#include <algorithm>

using namespace std;

struct Carro{
	int first;
	int second;	
};

int comparar(Carro a, Carro b){
	
	if(a.first == b.first){
		return (a.second < b.second);
	}else{
		return (a.first > b.first);
	}
	
}

int main(){
	Carro vetor[102];
	int vetorK[102];
	int matriz[102][102];

	int n, m, k, x, aux;	
	cin >> n >> m;
	
	while(n || m){

		for(int i=1; i<=n; i++){		
			for(int j=1; j<=m; j++){
				cin >> aux;			
				matriz[i][aux] = j; 
			}	
		}
			
		cin >> x;
		
		for(int i=1; i<=x; i++){		
			cin >> k;
			
			for(int a=1; a<=m; a++){		
				vetor[a].second = a;
				vetor[a].first = 0;	
			}
		
			for(int j=1; j<=k; j++){
				cin >> vetorK[j];
			}			
			
			for(int a=1; a<=n; a++){		
				for(int j=1; j<=k; j++){
					vetor[matriz[a][j]].first += vetorK[j];
				}
			}
			
			sort(vetor+1, vetor+m+1, comparar);
			
			int maior = vetor[1].first;
		
			cout << vetor[1].second;
			
			for(int a=2; (a<=m) && (vetor[a].first == maior); a++){
				cout << " " << vetor[a].second;
			}
			
			cout << endl;
					
		}
		
		cin >> n >> m;
		
	}	
	
	return 0;
}