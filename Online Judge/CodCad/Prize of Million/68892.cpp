#include <iostream> 

using namespace std;

int main(){
	
	int a, soma = 0, x, cont = 1;
	
	cin >> a;
	
	while(a--){
		cin >> x;
		soma += x;
		
		if(soma < 1000000)
			cont++;	
	}
	
	cout << cont <<endl;
	
	return 0;  
}
