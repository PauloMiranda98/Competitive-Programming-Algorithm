#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;
	
	cin >> a >> b >> c >> d;
	
	if( (a * b) == (c * d))	
		cout << "Empate" << endl;
	else if( (a * b) > (c * d) )
		cout << "Primeiro" << endl;
	else
		cout << "Segundo" << endl;
	return 0;
		
}