#include <iostream>

using namespace std;
bool eh_primo[10000001];

void crivo(long int n){
	eh_primo[0] = false;
	eh_primo[1] = false;
	
	for(long int i = 2; i <= n; i++){
		if(eh_primo[i]){
			for(long int j = i*2; j <= n; j += i){
				eh_primo[j] = false;
			}
		}
	}
	
}

int main(){
	int n;
	cin >> n; 

	for(long int i=0; i <=n; i++){
		eh_primo[i] = true;
	}

	crivo(n);
	
	for(long int i=2; i <=n; i++){
		if(eh_primo[i]){
			cout << i << ' ';
		}
	}

	cout << endl;
	return 0;
}
