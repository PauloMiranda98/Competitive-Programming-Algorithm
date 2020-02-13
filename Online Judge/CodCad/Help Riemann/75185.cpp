#include <iostream>

using namespace std;
bool eh_primo[16000001];

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
	long int n, cont = 0;
	cin >> n; 

	for(long int i=0; i <=16000000; i++){
		eh_primo[i] = true;
	}

	crivo(16000000);
	
	for(long int i=2; cont != n; i++){
		if(eh_primo[i]){
			cont++;
			
			if(cont == n){
				cout << i << endl;
			}
		}
		
	}

	return 0;
}

