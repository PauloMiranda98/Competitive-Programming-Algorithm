#include <bits/stdc++.h>

using namespace std;

//Circle-Line Intersection
typedef long long ll;
typedef double ftype;

const double EPS = 1e-9;

struct Circle{
	ftype x, y, r;
	Circle() {}
	Circle(ftype x, ftype y, ftype r): x(x), y(y), r(r){};		
};

struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y): x(x), y(y) {}

    point2d& operator=(const point2d &t) {
        x = t.x;
        y = t.y;
        return *this;
    }

    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(ftype t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(ftype t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(ftype t) const {
        return point2d(*this) /= t;
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

ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}
ftype norm(point2d a) {
    return a.x*a.x + a.y*a.y;
}
double abs(point2d a) {
    return sqrt(norm(a));
}
double dist(point2d a, point2d b){
	return abs(a - b);
}

Circle circumCircle(point2d a, point2d b, point2d c){
	point2d u( (b-a).y, -((b-a).x) );
	point2d v( (c-a).y, -((c-a).x) );
	point2d n = (c-b)*0.5;

	double t = cross(u, n)/cross(v, u);
	point2d ct = (((a+c)*0.5) + (v*t));
	double r = dist(ct, a);

	return Circle(ct.x, ct.y, r);
}

Circle inCircle(point2d a, point2d b, point2d c){
	double m1 = dist(a, b);
	double m2 = dist(a, c);
	double m3 = dist(b, c);
	point2d ct = ((c*m1) + (b*m2) + a*(m3))/(m1+m2+m3);
	
	double sp = 0.5*(m1+m2+m3);
	double r = sqrt(sp*(sp-m1)*(sp-m2)*(sp-m3))/sp;

	return Circle(ct.x, ct.y, r);
}

int circle_line_intersection(Circle circ, LineFloat line, double &ax, double &ay, double &bx, double &by){
	double r = circ.r;	
	double a = line.a, b = line.b, c = line.c + line.a*circ.x + line.b*circ.y; //take a circle to the (0, 0) 

	double x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b); //(x0, y0) is the shortest distance point of the line for (0, 0)

	if( (c*c) > (r*r*(a*a+b*b)+EPS) ){
		return 0;
	}else if(abs (c*c - r*r*(a*a+b*b)) < EPS) {		
		ax = bx = x0 + circ.x;
		ay = by = y0 + circ.y;

		return 1;
	}else{
		double d_2 = r*r - c*c/(a*a+b*b);
		double mult = sqrt (d_2 / (a*a+b*b));

		ax = x0 + b * mult + circ.x;
		bx = x0 - b * mult + circ.x;
		ay = y0 - a * mult + circ.y;
		by = y0 + a * mult + circ.y;
		
		return 2;
	}
}

int circle_intersection(Circle c1, Circle c2, double &ax, double &ay, double &bx, double &by){

	if( (c1.x == c2.x) and (c1.y == c2.y) ){		
		if(abs(c1.r-c2.r) < EPS)
			return -1; //INF
		else
			return 0;		
	}else{
		Circle circ(0, 0, c1.r);
		LineFloat line;
		
		line.a = 2*(c1.x - c2.x);
		line.b = 2*(c1.y - c2.y);
		line.c = (c1.x - c2.x)*(c1.x - c2.x) + (c1.y - c2.y)*(c1.y - c2.y) + c1.r*c1.r - c1.r*c2.r;

		int sz = circle_line_intersection(circ, line, ax, ay, bx, by);
		ax += c1.x;
		bx += c1.x;
		ay += c1.y;
		by += c1.y;		

		return sz;
	}

}

double sqr (double a) {
    return a * a;
}

void tangents(point2d c, double r1, double r2, vector<LineFloat> & ans) {
    double r = r2 - r1;
    double z = sqr(c.x) + sqr(c.y);
    double d = z - sqr(r);
    if (d < -EPS)  return;
    d = sqrt (abs (d));
    LineFloat l;
    l.a = (c.x * r + c.y * d) / z;
    l.b = (c.y * r - c.x * d) / z;
    l.c = r1;
    ans.push_back (l);
}

vector<LineFloat> tangents(Circle a, Circle b) {
    vector<LineFloat> ans;
    for (int i=-1; i<=1; i+=2)
        for (int j=-1; j<=1; j+=2)
            tangents(point2d(b.x-a.x, b.y-a.y), a.r*i, b.r*j, ans);
    for(size_t i=0; i<ans.size(); ++i){
        ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
		ans[i].normalize();
	}
    return ans;
}

int main() {
	Circle c;
	Circle c2;
	LineFloat l;
	cout << "Circle 1(x, y, r):" << endl;
	cin >> c.x >> c.y >> c.r;
	cout << "Circle 2(x, y, r):" << endl;
	cin >> c2.x >> c2.y >> c2.r;
	cout << "Line(a, b, c):" << endl;
	cin >> l.a >> l.b >> l.c;
	
	double x1, y1, x2, y2; 
	int qtd = circle_line_intersection(c, l, x1, y1, x2, y2);
	
	cout << "Intersection line and circle: ";
	if(qtd == 0){
		cout << "no points" << '\n';
	}else if(qtd == 1){
		cout << "1 point" << endl;
		cout << x1 << ' ' << y1 << '\n';		
	}else{
		cout << "2 points" << endl;
		cout << x1 << ' ' << y1 << '\n' << x2 << ' ' << y2 << '\n';		
	}
	
	qtd = circle_intersection(c, c2, x1, y1, x2, y2);

	cout << "Intersection circle and circle: ";
	if(qtd == -1){
		cout << "infinity points" << '\n';
	}else if(qtd == 0){
		cout << "no points" << '\n';
	}else if(qtd == 1){
		cout << "1 point" << endl;
		cout << x1 << ' ' << y1 << '\n';		
	}else{
		cout << "2 points" << endl;
		cout << x1 << ' ' << y1 << '\n' << x2 << ' ' << y2 << '\n';		
	}

	vector<LineFloat> v = tangents(c, c2);

	cout << "Number of the tangents: " << v.size() << endl;
	for(LineFloat li : v){
		cout << "Tangente: " << li.a << " " << li.b << " " << li.c << endl;
	}

	
	return 0;
}
