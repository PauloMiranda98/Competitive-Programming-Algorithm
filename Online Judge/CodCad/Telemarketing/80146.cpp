#include <iostream>
#include <queue>

using namespace std;

long int vetor[1001];
priority_queue< pair<long int, long int>, vector< pair<long int, long int> >, greater< pair<long int, long int> > > fila;
	
int main(){
	
	long int n, l, t;
	
	cin.tie(0);
	cin.sync_with_stdio(0);
			
	cin >> n >> l;
	
	for(long int i=1; i <= n; i++){
		fila.push(make_pair(0, i));
		vetor[i] = 0;
	}
	
	for(long int i=0; i < l; i++){
		cin >> t;
		
		pair<long int, long int> front = fila.top();
		fila.pop();
		
		front.first += t; 
		vetor[front.second]++;
		
		fila.push(front);
	}
		
	
	for(long int i=1; i <= n; i++){
		  
		cout << i << " " << vetor[i] << endl;		
				   					
	}
	return 0;
}  	
