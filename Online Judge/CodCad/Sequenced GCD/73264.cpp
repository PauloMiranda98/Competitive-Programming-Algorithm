#include <iostream>

using namespace std;

int mdc(int a, int b){
	if(b == 0)
		return a;
		
	return mdc(b, a%b);
}

int main(){
	int a, b = 0, c;
	cin >> a;
	
	while(a--){
		cin >> c;	
			
		b = mdc(b,c);
	}
	
	cout << b << endl;
	
	return 0;
}
