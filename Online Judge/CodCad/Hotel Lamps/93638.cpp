#include <iostream>

using namespace std;

int main(){
	bool a, b, c, d;
	
	cin >> a >> b >> c >> d;
	
	if( (a == c) && (b == d))
		cout << 0 << endl;
	else if( (a == !c) && (b == !d))
		cout << 1 << endl;
	else if ( b == d)
		cout << 1 << endl;
	else
		cout << 2 << endl;
	
	return 0;
}
