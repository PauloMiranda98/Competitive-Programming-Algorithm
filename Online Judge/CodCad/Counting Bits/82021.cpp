#include <iostream>

using namespace std;

int main(){
	
	long long int n;
	int cont = 0;	
	
	cin >> n;
	
	while(n){
		if(n%2 == 1)
			cont++;
		
		n /= 2;
	}

	cout << cont << endl;
		
	return 0;
}