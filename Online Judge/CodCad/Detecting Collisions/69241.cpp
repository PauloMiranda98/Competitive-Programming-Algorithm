#include <iostream>
#include <string.h>

using namespace std;

double abs(double a){
	
	return (a >= 0)? a : (-1*a); 
}

int main(){


	long int x[4], y[4];
	
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	cin >> x[2] >> y[2] >> x[3] >> y[3];

	double x1 = (x[0]+x[1])/2.0;
	double x2 = (x[2]+x[3])/2.0;
	double y1 = (y[0]+y[1])/2.0;
	double y2 = (y[2]+y[3])/2.0;

	if( (abs(x1-x2) <= (x[1] - x1 + x[3]-x2)) &&  (abs(y1-y2) <= (y[1] - y1 + y[3]-y2)) )
		cout << "1" << endl;
	else
		cout << "0" << endl;
		
	return 0;
}
