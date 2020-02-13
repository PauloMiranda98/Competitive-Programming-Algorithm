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
		
		total[x] += total[y];
		
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
	
	long int n, k;
	
	cin >> n >> k;
	
	for(long int i = 1; i <= n; i++){
		pai[i] = i;
		dist[i] = 1;
		total[i] = 1;
	}
	
	for(long int i = 1; i <= k; i++){
		char op;
		long int x, y;
		
		cin >> op;
		cin >> x >> y;
		
		switch(op){
			case 'C':
				
				if(find(x) == find(y))
					cout << "S" << endl;
				else
					cout << "N" << endl;
				
				break;
				
			case 'F':
			
				join(x, y);			
				
				break;
		}
		
	}	
	
	return 0;
}
