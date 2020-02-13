#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
deque<long int> lista;

int main(){
	long int n, k, aux, res = 0;
	cin >> n >> k;
	for(long i=0; i<n; i++){
		cin >> aux;
		lista.push_back(aux);
	}
	
	sort(lista.begin(), lista.end());
	
	while(lista.size() > 1){
		if( (lista.front()+lista.back())<=k){
			res++;
			lista.pop_back();
			lista.pop_front();
		}else{
			res++;
			lista.pop_back();
		}
	}
	res += lista.size();
	
	cout << res << endl;
	return 0;
}
