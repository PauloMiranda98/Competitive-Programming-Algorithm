#include <iostream>
#include <queue>
#include <algorithm>
#define MAXN 90010

using namespace std;

long matriz[310][310];

pair<long, pair<int, int> > vetor[90010];

long maior;

int n, pai[MAXN], peso[MAXN], qtd[MAXN];

int find(int x){
    
    if(pai[x]==x){
        return x;
    }
    return pai[x]=find(pai[x]);
}

void join(int x, int y){
	
    x=find(x);
    y=find(y);
    
    if(x==y){
        return;
    }
    
    if(peso[x]<peso[y]){    
         pai[x]=y;
         qtd[y]+=qtd[x];
    }
    
    if(peso[x]>peso[y]){
        
         pai[y]=x; 
         qtd[x]+=qtd[y]; 
    }
    
    if(peso[x]==peso[y]){
        
        pai[x]=y;
        
        peso[y]++;
        
        qtd[y]+=qtd[x];
    }
}


void juntar(int i, int j){
	if(i-1 >= 0 && j >= 0 && i-1 < n && j < n)
		if(matriz[i-1][j] > 0)
			join(i*n + j, (i-1)*n + j);

	if(i+1 >= 0 && j >= 0 && i+1 < n && j < n)
		if(matriz[i+1][j] > 0)
			join(i*n + j, (i+1)*n + j);

	if(i >= 0 && j-1 >= 0 && i < n && j-1 < n)
		if(matriz[i][j-1] > 0)
			join(i*n + j, i*n + j - 1);

	if(i >= 0 && j+1 >= 0 && i < n && j+1 < n)
		if(matriz[i][j+1] > 0)
			join(i*n + j, i*n + j + 1);
					
}

int menor(int i, int j){
	queue< pair<int, int> > fila;
	queue<long> caminho;
	
	fila.push(make_pair(i, j));
	caminho.push(1);
	
	while(!fila.empty()){
		i = fila.front().first;
		j = fila.front().second;
		long c = caminho.front();
		
		fila.pop();
		caminho.pop();
		
		if(i < 0 || j < 0 || j >=n || i >= n)
			continue;
			
		if(matriz[i][j] <= 0)
			continue;
			
		if(i == n-1 && j == n-1)
			return c;

		matriz[i][j] = 0;
		
		fila.push( make_pair(i, j+1) );
		caminho.push(c + 1);
		
			
		fila.push( make_pair(i+1, j) );
		caminho.push(c + 1);
		
		fila.push( make_pair(i, j-1) );
		caminho.push(c + 1);
		
		fila.push( make_pair(i-1, j) );
		caminho.push(c + 1);
	
	}
	
	return -1;
}

int main(){
	cin >> n;
	long cont = 0, x;
	maior = 0;
	
	for(int i=0; i<n*n; i++){
		pai[i] = i;
	}
		
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> x;
			vetor[cont++] = make_pair( x, make_pair(i, j) );
			
		}
	}
	
	sort(vetor, vetor + n*n);
	
	long p = 0;
	for(; p < 2*n; p++){
		maior = vetor[p].first;
		matriz[vetor[p].second.first][vetor[p].second.second] = maior;
		
		juntar(vetor[p].second.first, vetor[p].second.second);
	}

	for(; find(0) != find(n*n - 1) && p < n*n; p++){
		maior = vetor[p].first;
		matriz[vetor[p].second.first][vetor[p].second.second] = maior;
		juntar(vetor[p].second.first, vetor[p].second.second);
	}
	
	for(; p < n*n && vetor[p].first == maior; p++){
		matriz[vetor[p].second.first][vetor[p].second.second] = maior;	
	}
		
	cout << maior << " " << menor(0, 0) << endl;
	
	return 0;	
}
