#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll, ll> pll;
const double EPS = 1e-9;

typedef double ftype;

//Check intersect segment INT

struct pt {
	ftype x, y;
    
	pt(){}
	pt(ftype x, ftype y): x(x), y(y){}

	bool operator<(const pt& p) const{
		return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
	}
};

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

double dist(LineFloat m, ftype x, ftype y){
	return abs(m.a*x + m.b*y + m.c)/sqrt(m.a*m.a + m.b*m.b);
}

ftype det(ftype a, ftype b, ftype c, ftype d){
    return a * d - b * c;
}

inline bool betw(ftype l, ftype r, ftype x){
    return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_1d(ftype a, ftype b, ftype c, ftype d){
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

bool intersect(pt a, pt b, pt c, pt d, pt& left, pt& right){
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
        return false;
    LineFloat m(a.x, a.y, b.x, b.y);
    LineFloat n(c.x, c.y, d.x, d.y);
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS) { //It is parallel
        if (abs(dist(m, c.x, c.y)) > EPS || abs(dist(n, a.x, a.y)) > EPS) //No equivalent
            return false;
        if (b < a)
            swap(a, b);
        if (d < c)
            swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    } else { //No parallel
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
               betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
}

int main() {
	
	pt a(0, 0);
	pt b(4, 4);

	pt c(2, 2);
	pt d(8, 8);
	
	pt l(0, 0);
	pt r(0, 0);
	if(intersect(a, b, c, d, l, r)){
		cout << "Intersect: ";
		cout << "(" <<l.x << ", " << l.y << ") ";
		cout << "(" <<r.x << ", " << r.y << ")" << endl;
	}else{
		cout << "No intersect!" << endl;
	}
	c.y = 4;
	if(intersect(a, b, c, d, l, r)){
		cout << "Intersect: ";
		cout << "(" <<l.x << ", " << l.y << ") ";
		cout << "(" <<r.x << ", " << r.y << ")" << endl;
	}else{
		cout << "No intersect!" << endl;
	}

	c.x = 4;
	if(intersect(a, b, c, d, l, r)){
		cout << "Intersect: ";
		cout << "(" <<l.x << ", " << l.y << ") ";
		cout << "(" <<r.x << ", " << r.y << ")" << endl;
	}else{
		cout << "No intersect!" << endl;
	}
	
	return 0;
}
