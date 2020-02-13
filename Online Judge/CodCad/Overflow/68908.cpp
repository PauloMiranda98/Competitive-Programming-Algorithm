#include <iostream>
#include <list>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	long int x, y, n;
	char o;
	
	cin >> n;
	cin >> x >> o >> y;
	
	if( (o == '+' && x+y<=n) || (o == '*' && x*y<=n))
		cout << "OK" << endl;
	else 
		cout << "OVERFLOW" << endl;
							   					
	return 0;
}