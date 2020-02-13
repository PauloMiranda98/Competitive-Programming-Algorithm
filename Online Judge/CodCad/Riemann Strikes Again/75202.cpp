#include <iostream>

using namespace std;
bool eh_primo[2000001];
long int pos_primo[2000001];

void crivo(long int n){
	eh_primo[0] = false;
	eh_primo[1] = false;
	long int cont = 0;
	
	for(long int i = 2; i <= n; i++){
		if(eh_primo[i]){

			cont++;			
			pos_primo[i] = cont;
			
			for(long int j = i*2; j <= n; j += i){
				eh_primo[j] = false;
			}
		}
	}
	
}

int main(){
	long int n;
	cin >> n; 

	for(long int i=0; i <=2000000; i++){
		eh_primo[i] = true;
	}

	crivo(2000000);
	
	for(long int i=0; i < n; i++){
		long int x;
		cin >> x;
		
		cout << pos_primo[x] << endl;
	}

	return 0;
}
