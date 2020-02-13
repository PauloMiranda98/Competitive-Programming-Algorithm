#include <iostream> 
#include <string.h> 

using namespace std;

int main(){

	bool vetor[91];
	
	int b, n;
	cin >> b >> n;

	while(b || n){
		for(int i=0; i<=b; i++)
			vetor[i] = 0;
		
		for(int i=1; i<=n; i++){
			int x;
			cin >> x;
			vetor[x] = 1;
		}
		
		bool r = true;
		
		for(int i=1; (i<=b) && r; i++){
			r = false; 
			for(int j = i; j<=b; j++){
				if( (vetor[j] == 1) && (vetor[j-i]==1) ){
					r = true;
					break;
				}
			}
		}
			
		if(r)
			cout << "Y" << endl;
		else	
			cout << "N" << endl;
		
		cin >> b >> n;
	}
	
	return 0;  
}
