#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double a, b, c, r;

	cin >> a >> b >> c >> r;
	
	double d, t;
	d = (a*a + b*b)/4;
	
	t = sqrt( (c*c)/4 + d );
	
	if(t <= r)
		cout << "S" << endl;
	else
		cout << "N" << endl;
		
    return 0;
}

