#include <iostream>

using namespace std;

int mdc(int a, int b){
	if(b == 0)
		return a;
	else
		return mdc(b, a%b);	
}

int mmc(int a, int b){
	return (a * b) / mdc(a, b);
}

int main(){
	int n, a, b;
	
	cin >> n;
	
	cin >> a;
	for(int i = 0; i < n-1; i++){
		cin >> b;
		a = mdc(a, b);
	}
	
	cout << a << endl;
			
	return 0;
}