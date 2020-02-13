#include <iostream> 

using namespace std;

int main(){
	
	int a, saldo, x, y;
	
	cin >> a;
	
	saldo = 0;
		
	while(a--){
		cin >> x >> y;
		if(x > y)
			saldo += y;
	}
	
	cout << saldo <<endl;
	
	return 0;  
}
