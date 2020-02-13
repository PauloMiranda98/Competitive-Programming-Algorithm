#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	

	int n;

	cin >> n;
		
	while(n--){
		long double x, r;
		cin >> x;
		
		r = sqrtl(x);
		cout.precision(4);
		cout << fixed;
		
		cout << r << endl;
		
	}
	
    return 0;
}


