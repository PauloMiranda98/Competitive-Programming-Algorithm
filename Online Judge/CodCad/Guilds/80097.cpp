#include <iostream>
#define MAX 100001

using namespace std;

long int pai[MAX], dist[MAX], total[MAX];

long int find(long x){
	
	if(pai[x] == x)
		return x;
		
	return pai[x] = find(pai[x]);	
}

void join(long int x, long int y){

	x = find(x);
	y = find(y);
	
	if(x == y)
		return;
			
	if(dist[x] < dist[y]){
		pai[x] = y;
		
		total[y] += total[x];
		
	}else if(dist[x] > dist[y]){
		pai[y] = x;
		
		total[x] += total[y];	
	}else{
		pai[y] = x;
		total[x] += total[y];
		
		dist[x]++;	
	}
}

int main(){
	
	long int n, m;
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	cin >> n >> m;
	
	while(n || m){
		int cont = 0;
				
		for(long int i = 1; i <= n; i++){
			pai[i] = i;
			dist[i] = 1;
			
			cin >> total[i];
		}
		
		for(long int i = 1; i <= m; i++){
			int op;
			long int x, y, p;
			
			cin >> op;
			cin >> x >> y;
			
			switch(op){
				case 1:
					
					join(x, y);			
					
					break;
					
				case 2:
					p = find(1);
					x = find(x);
					y = find(y);
					
					if(p == x){
						
						if(total[x] > total[y])
							cont++;
							
					}else if(p == y){
						
						if(total[y] > total[x])
							cont++;					
					}
					
					break;
			}
			
		}	
		
		cout << cont << endl;
		
		cin >> n >> m;

	}	
	
	return 0;
}
