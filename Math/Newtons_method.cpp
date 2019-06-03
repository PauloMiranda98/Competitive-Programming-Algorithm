#include <bits/stdc++.h>

using namespace std;

//Newton's method

double f(double x){	
	return (x*x) - 4;
}

double df(double x){	
	return 2*x;
}

double root(double x0){
    const double eps = 1E-15;
    double x = x0;

    for (;;) {
        double nx = x - (f(x)/df(x));
        if (abs(x - nx) < eps)
            break;
        x = nx;

    }
    return x;	
}

int main(){	
	double n;
	cin >> n;
	
	cout << root(n) << endl;
	
	return 0;	
}








