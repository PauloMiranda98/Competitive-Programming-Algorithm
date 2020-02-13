#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	long double x, y, r;
	cin >> x >> y;
	
	r = powl(x, y);
	cout.precision(4);
	cout << fixed;
	
	cout << r << endl;
	
    return 0;
}


