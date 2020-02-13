#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int abs(int a){
	
	return (a>=0)? a : -1*a;
}

int main(){

	int a, b, c, d;
	
	cin >> a >> b >> c >> d;

	cout << (abs(c-a) + abs(d - b)) << endl;
	
	return 0;
}
