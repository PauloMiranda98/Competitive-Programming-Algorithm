#include <iostream>

using namespace std;

int main(){
	long int n, i;
	bool a = false, b = false;
	
	cin >> n;
	
	while(n != 0){
		cin >> i;
		
		a ^= 1;
		if(i == 2){
			b ^= 1;
		}
		
		n--;
	}
	cout << a << endl;
	cout << b << endl;
		
	return 0;
}