#include <iostream>
#include <vector>

using namespace std;

//------------------------
#define MAXN 501

int n, m, o;
int atual[MAXN];
int idade[MAXN];
bool componente[MAXN];
bool matriz[MAXN][MAXN];

int menor = 101;

//------------------------

void dfs(int x){
	
	for(int i = 1;i <= n;i++){
		if(matriz[x][i]){			
			if(componente[i]){
				componente[i] = false;
								
				menor = min(idade[atual[i]], menor);
				
				dfs(i);
			}
		}
	}
	
}

int main(){
		
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	while(cin >> n >> m >> o){
		
		for(int i = 1;i <= n;i++){	 
			for(int j = 1;j <= n;j++){	 
				matriz[i][j] = false;
			}
		}
		
		for(int i = 1;i <= n;i++){
			int a;
			cin >> a;
			
			idade[i] = a;
			atual[i] = i;
		}	
		
		for(int i = 1;i <= m;i++){

			int a, b;
			cin >> a >> b;

			matriz[b][a] = true;
		}
			
		for(int i=1; i<=o; i++){
			char c;
			int a, b;
			
			cin >> c;
			
			if(c == 'P'){
				cin >> a;
				
				menor = 101;
				
				for(int j = 1;j <= n;j++){	 
					componente[j] = true;
				}
				int a1;
				
				a1 = a;
				while(atual[a1] != a){
					a1 = atual[a1];
				}
				
				dfs(a1);
				
				if(menor == 101)
					cout << "*" << endl;
				else	
					cout << menor << endl;
					
			}else{
				cin >> a >> b;
				
				int a1,a2;
				
				a1 = a;
				while(atual[a1] != a){
					a1 = atual[a1];
				}
				
				a2 = b;
				while(atual[a2] != b){
					a2 = atual[a2];
				}
				
				int d = atual[a1];
				atual[a1] = atual[a2];
				atual[a2] = d;
			}
		}
	}
	
	return 0;
}
