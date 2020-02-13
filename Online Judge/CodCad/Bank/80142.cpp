#include <iostream>
#include <queue>

using namespace std;

priority_queue< int, vector<int>, greater<int> > fila;
	
int main(){
	
	long int i, c, n, t, d, cont = 0;
	
	cin.tie(0);
	cin.sync_with_stdio(0);
			
	cin >> c >> n;
	
	for(i=0; i < c; i++){
		cin >> t >> d;
		
		fila.push(t+d);
	}
	
	for( ; i < n; i++){
		cin >> t >> d;
		
		long int front = fila.top();
		fila.pop();
		
		if( (front - t) > 20 )
			cont++;
			
		fila.push(max(t,front) + d);
	}
		  
	cout << cont << endl;		
				   					
	return 0;
}  	
