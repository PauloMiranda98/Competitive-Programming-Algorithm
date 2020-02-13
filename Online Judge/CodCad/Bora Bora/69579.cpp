#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, char> vetor[300];

int main(){
	
	int p, m, n;
	
	cin >> p >> m >> n;
	
	while((p!=0) || (m!=0)|| (n!=0)){
		vector< pair<int, char> > jogador[12];
	
		for(int i=0; i < n; i++)
			cin >> vetor[i].first >> vetor[i].second; 

		int x = 0;
		for(int i=1; i <= p; i++){
			for(int j=0; j < m; j++){
				jogador[i].push_back(vetor[x]);
				x++;
			}
		}
			
		int vencedor = -1;

		int sentido = 1;
		int atual = 1;
		pair<int, char> topo;
		topo = vetor[x];
		x++;
			
		if(topo.first == 1){
			jogador[atual].push_back(vetor[x]);
			x++;
			atual = atual%p + 1;
		}else if(topo.first == 7){
			jogador[atual].push_back(vetor[x]);
			x++;
			jogador[atual].push_back(vetor[x]);
			x++;		
			atual = atual%p + 1;
		}else if(topo.first == 12){
			sentido = -1;
		}else if(topo.first == 11){
			atual = atual%p + 1;
		}
			
		while(vencedor == -1){
			
			int pos = -1;
			pair<int, char> maior(0, 'C');
			
			for(int i=0; i < (int) jogador[atual].size(); i++){
				if( (jogador[atual][i].first == topo.first) || (jogador[atual][i].second == topo.second)){
					if(jogador[atual][i].first > maior.first){
						maior = jogador[atual][i];
						pos = i;
					}else if( (jogador[atual][i].first == maior.first) && (jogador[atual][i].second > maior.second)){
						maior = jogador[atual][i];
						pos = i;					
					}
				}
			}
			
			if(pos == -1){
				if( (vetor[x].first == topo.first) || (vetor[x].second == topo.second)){
					topo = vetor[x];
					x++;
					
					atual = (atual%p) + sentido;
					
					if(atual == 0)
						atual = p;
					if(atual == -1)				
						atual = p-1;
					
					if(topo.first == 1){
						jogador[atual].push_back(vetor[x]);
						x++;
						atual = (atual%p) + sentido;
							
						if(atual == 0)
							atual = p;
						if(atual == -1)				
							atual = p-1;
					}else if(topo.first == 7){
						jogador[atual].push_back(vetor[x]);
						x++;
						jogador[atual].push_back(vetor[x]);
						x++;		
						atual = (atual%p) + sentido;
						
						if(atual == 0)
							atual = p;
						if(atual == -1)				
							atual = p-1;
					}else if(topo.first == 12){
						sentido *= -1;
						atual = (atual%p) + sentido;
						
						if(atual == 0)
							atual = p;
						if(atual == -1)				
							atual = p-1;
						atual = (atual%p) + sentido;
						
						if(atual == 0)
							atual = p;
						if(atual == -1)				
							atual = p-1;
					}else if(topo.first == 11){
						atual = (atual%p) + sentido;
						
						if(atual == 0)
							atual = p;
						if(atual == -1)				
							atual = p-1;
					}

				}else{
					jogador[atual].push_back(vetor[x]);
					x++;
									
					atual = atual%p + sentido;
					
					if(atual == 0)
						atual = p;
					if(atual == -1)				
						atual = p-1;
				}			
			}else{
				topo = maior;
				jogador[atual].erase(jogador[atual].begin()+pos);
				
				for(int i=1; i <= p; i++){
					if(jogador[i].size() == 0){
						vencedor = i;
						break; 
					}
				}
				
				if(vencedor != -1)
					break;

				atual = (atual%p) + sentido;
				
				if(atual == 0)
					atual = p;
				if(atual == -1)				
					atual = p-1;
				
				if(topo.first == 1){
					jogador[atual].push_back(vetor[x]);
					x++;
					atual = (atual%p) + sentido;
					
					if(atual == 0)
						atual = p;						
					if(atual == -1)				
						atual = p-1;
				}else if(topo.first == 7){
					jogador[atual].push_back(vetor[x]);
					x++;
					jogador[atual].push_back(vetor[x]);
					x++;		
					atual = (atual%p) + sentido;
					
					if(atual == 0)
						atual = p;
					if(atual == -1)				
						atual = p-1;
				}else if(topo.first == 12){
					sentido *= -1;
					atual = (atual%p) + sentido;
					
					if(atual == 0)
						atual = p;
					if(atual == -1)				
						atual = p-1;
					atual = (atual%p) + sentido;
					
					if(atual == 0)
						atual = p;
					if(atual == -1)				
						atual = p-1;
				}else if(topo.first == 11){
					atual = (atual%p) + sentido;
					
					if(atual == 0)
						atual = p;
					if(atual == -1)				
						atual = p-1;
				}			
			}
						
		}
		
		cout << vencedor << endl;
		cin >> p >> m >> n;
	}
	
	return 0;
}   

