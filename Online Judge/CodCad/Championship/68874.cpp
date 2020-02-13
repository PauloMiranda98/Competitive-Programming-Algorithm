#include <iostream>
#include <list>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c;
	cin >> d >> e >> f;

	if( (a*3 + b) > (d*3+e))
		cout << 'C' << endl;
	else if( (a*3 + b) < (d*3+e))
		cout << 'F' << endl;
	else 
		if(c > f)
			cout << 'C' << endl;
		else if(c < f)
			cout << 'F' << endl;
		else
			cout << '=' << endl;
							   					
	return 0;
}