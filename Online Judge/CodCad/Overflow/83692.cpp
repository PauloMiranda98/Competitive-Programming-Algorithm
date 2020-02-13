






#include <iostream>

using namespace std;

int main(){   	
	
	int limite, resultado, op1, op2;
	char operacao;
	
	cin >> limite;
	
	cin >> op1;
	cin >> operacao;
	cin >> op2;
	
	if(operacao == '+'){
		resultado = op1 + op2;
	}else{
		resultado = op1 * op2;		
	}
	
	if(resultado <= limite){
		cout << "OK" << endl;
	}else{
		cout << "OVERFLOW" << endl;		
	}
		
	
   	
	return 0;
}


