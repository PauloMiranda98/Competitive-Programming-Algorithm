#include <iostream> 

using namespace std;

int main(){
	
	int a, saldo, x;
	
	cin >> saldo >> a;
		
	while(a--){
		cin >> x;
		saldo += x;
		
		if(saldo > 100)
			saldo = 100;
		if(saldo < 0)
			saldo = 0;
	}
	
	cout << saldo <<endl;
	
	return 0;  
}
