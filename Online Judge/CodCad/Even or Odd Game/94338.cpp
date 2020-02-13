#include <iostream>

using namespace std;

int main(){
	bool par;
	int a,b;
	cin >> par;
	
	cin >> a >> b;
	
	if( (a+b)%2 == 0)
		cout << par << endl;
	else	
		cout << !par << endl;
	return 0;
}