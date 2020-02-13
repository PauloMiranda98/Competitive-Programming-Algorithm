#include <iostream>

using namespace std;

int n;

int matriz[10010];

bool valido(int x){
	if( (x >=1) && (x <= n))
		if(matriz[x] == -1)
			return true;
	
	return false;
}

int main(){
	bool fazer9 = false;
	
	cin >> n;
		
	for(int i=1; i<=n; i++){
		cin >> matriz[i];
	}	
	
	for(int k=1; k <=8; k++){
		int anterior = k - 1;
		
		for(int i=1; i<=n; i++){
			if(matriz[i] == anterior){
				if(valido(i-1))
					matriz[i-1] = k;
				if(valido(i+1))
					matriz[i+1] = k;
			}
		}			
	}
	
	for(int i=1; i<=n; i++){
		if(matriz[i] == 8){
			fazer9 = true;
			break;
		}
	}			
	
	if(fazer9){
		for(int i=1; i<=n; i++){
			if(matriz[i] == -1)
				matriz[i] = 9;
		}			
	}
	
	for(int i=1; i<=n; i++){
		cout << matriz[i] << " ";		
	}
	
	cout << endl;
	
	return 0;
}
