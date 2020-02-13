#include <iostream> 

using namespace std;

int main(){
	
	int a, saldo,soma = 0, x, menor;
	
	cin >> a >> saldo;
	
	menor = saldo;
	soma = saldo;
		
	while(a--){
		cin >> x;
		soma += x;
		
		if(soma < menor)
			menor = soma;	
	}
	
	cout << menor <<endl;
	
	return 0;  
}
