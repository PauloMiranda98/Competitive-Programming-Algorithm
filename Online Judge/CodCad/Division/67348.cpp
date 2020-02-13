#include <iostream>

using namespace std;

int main() {
	float a,b;
	
	cin >> a >> b;
	
	cout.precision(2);
	cout.setf(ios::fixed);
	
	cout << a/b << endl;
	
	return 0;
		
}