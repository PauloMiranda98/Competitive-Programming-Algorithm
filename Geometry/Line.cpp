#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll, ll> pll;
const double EPS = 1e-9;

typedef ll ftype;

// Ax + By + C = 0

ftype det(ftype a, ftype b, ftype c, ftype d) {
	return a*d - b*c;
}

struct LineInt{
	ftype a, b, c;
	LineInt() {}
	LineInt(ftype a, ftype b, ftype c): a(a), b(b), c(c) {
		normalize();
	}
	LineInt(ftype x1, ftype y1, ftype x2, ftype y2){
		a = y1 - y2;
		b = x2 - x1;
		c = -a*x1 - b*y1;		
		normalize();
	}
	
	void normalize(){
		int mdc = __gcd(abs(a), __gcd(abs(b), abs(c)));
		a /= mdc; b /= mdc; c /= mdc;
		
		if( (a < 0) or ((a==0) and (b < 0)) ){
			a = -a; 
			b = -b; 
			c = -c;
		}		
	}
	
};

bool intersect(LineInt m, LineInt n, pdd & res) {
	ftype zn = det(m.a, m.b, n.a, n.b);
	if (zn == 0)
		return false;
	res.first = -det(m.c, m.b, n.c, n.b) / (double)zn;
	res.second = -det(m.a, m.c, n.a, n.c) / (double)zn;
	return true;
}

bool parallel(LineInt m, LineInt n) {
	return det(m.a, m.b, n.a, n.b) == 0;
}

bool equivalent(LineInt m, LineInt n) {
	return (det(m.a, m.b, n.a, n.b) == 0)
		&& (det(m.a, m.c, n.a, n.c) == 0)
		&& (det(m.b, m.c, n.b, n.c) == 0);
}

double dist(LineInt m, ftype x, ftype y){
	return abs(m.a*x + m.b*y + m.c)/sqrt(m.a*m.a + m.b*m.b);
}


struct LineFloat{
	ftype a, b, c;
	LineFloat() {}
	LineFloat(ftype a, ftype b, ftype c): a(a), b(b), c(c) {
		normalize();
	}
	LineFloat(ftype x1, ftype y1, ftype x2, ftype y2){
		a = y1 - y2;
		b = x2 - x1;
		c = -a*x1 - b*y1;		
		normalize();
	}

	void normalize(){		
		ftype z = sqrt(a*a + b*b);
		a /= z; b /= z; c /= z;
		
		if( (a < -EPS) or ((abs(a) < EPS) and (b < -EPS)) ){
			a = -a; 
			b = -b; 
			c = -c;
		}		
	}

};

bool intersect(LineFloat m, LineFloat n, pdd & res) {
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.first = -det(m.c, m.b, n.c, n.b) / zn;
    res.second = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

bool parallel(LineFloat m, LineFloat n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS;
}

bool equivalent(LineFloat m, LineFloat n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS
        && abs(det(m.a, m.c, n.a, n.c)) < EPS
        && abs(det(m.b, m.c, n.b, n.c)) < EPS;
}

double dist(LineFloat m, ftype x, ftype y){
	return abs(m.a*x + m.b*y + m.c);
}

int main() {
	LineInt l1(10, 5, 10);
	LineInt l2(10, 5, 20);
		
	cout << parallel(l1, l2) << endl;
	cout << equivalent(l1, l2) << endl;

	l2.c = 10;		
	cout << parallel(l1, l2) << endl;
	cout << equivalent(l1, l2) << endl;

	l2.a = 5;
	cout << parallel(l1, l2) << endl;
	cout << equivalent(l1, l2) << endl;

	pdd pt;
	cout << intersect(l1, l2, pt) << endl;
	cout << pt.first << " " << pt.second << endl;
	
	
	return 0;
}
