#include <iostream> 

using namespace std;

int main(){
	
	int a, menor, x;
	
	cin >> a;	
	cin >> menor;
			
	while(--a){
		cin >> x;
		if(x < menor)
			menor = x;
	}
	
	cout << menor <<endl;
	
	return 0;  
}
