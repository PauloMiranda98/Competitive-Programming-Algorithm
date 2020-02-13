#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long int primos[42];
vector<pair<long int, int>> atual;
int main(){
	long int n, k, sentido = 1;
	long int res = 0;
	cin >> n >> k;
	
	for(int i=1; i<=k; i++){
		cin >> primos[i];
		atual.push_back(make_pair(primos[i], i));
		res += (n/primos[i]);		
	}
	
	atual.pop_back();
	
	sentido = -1;
		
	while(!atual.empty()){
		vector<pair<long int, int>> aux;
		
		for(int a=0; a < (int)atual.size(); a++){
			pair<long int, int> m = atual[a];
			
			for(int i = m.second+1; i <= k; i++){
				long int r = m.first * primos[i];
				if(r <= n){
					aux.push_back(make_pair(r, i));
					res += sentido*(n/r);		
				}
			}
		}
		sentido *= -1; 	
		atual.clear();
		atual = aux;
	}
		
	cout << n - res << endl;
	return 0;
}
