#include <iostream>

using namespace std;

int main(){
	
	unsigned long long int n;

	cin >> n;
	int cont = 0;
	while(n != 1){
		if(n%2 == 0){
			n = n/2;
		}else{
			n = n*3 + 1;
		}
		
		cont++;
	}
	cout << cont << endl;
	
	return 0;
}