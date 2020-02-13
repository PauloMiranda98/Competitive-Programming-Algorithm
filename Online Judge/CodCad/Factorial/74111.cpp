#include <iostream>

using namespace std;

unsigned long long int fat(unsigned long long int  x){

	return (x<=1) ? 1 : x*fat(x-1);
}

int main(){
	
	unsigned long long int n;

	cin >> n;
	
	cout << fat(n) << endl;
	
	return 0;
}