#include <iostream>

using namespace std;

unsigned long long int mdc(unsigned long long int a, unsigned long long int b){
	if(b == 0)
		return a;
		
	return mdc(b, a%b);
}

int main(){
	unsigned long long int a, b;
	
	cin >> a >> b;
	
	cout << ((a*b)/mdc(a,b)) << endl;
	
	return 0;
}
