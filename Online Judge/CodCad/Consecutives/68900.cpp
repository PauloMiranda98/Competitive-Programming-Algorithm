#include <iostream>

using namespace std;

int main(){
	long int c, i, novo, cont=1, ultimo, maior=1;

	cin >> c;
	cin >> ultimo;
	
	for(i=1; i<c; i++){
		cin >> novo;
		if(novo == ultimo){
			cont++;
		}else{
			maior = max(maior, cont);
			cont=1;
			ultimo = novo;
		}
	}
	
	maior = max(maior, cont);
			   	
	cout << maior << endl;
							   					
	return 0;
}