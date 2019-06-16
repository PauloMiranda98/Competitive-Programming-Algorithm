#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

typedef ll ftype;

//Point2D
struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y): x(x), y(y) {}

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

point2d operator*(ftype a, point2d b) {
    return b * a;
}
ftype dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}
ftype norm(point2d a) {
    return dot(a, a);
}
double abs(point2d a) {
    return sqrt(norm(a));
}
double proj(point2d a, point2d b) {
    return dot(a, b) / abs(b);
}
double angle(point2d a, point2d b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}
ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}
//Line parameterized: r1 = a1 + t*d1
point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}
double dist(point2d a, point2d b){
	return abs(a - b);
}

double dist(point2d a, point2d pl1, point2d pl2){
	//crs = parallelogram area
	double crs = cross(point2d(a - pl1), point2d(pl2 - pl1));
	//h = area/base
	return abs(crs/dist(pl1, pl2));
}

double area(vector <point2d> p){
	double ret = 0;

	for(int i = 2; i < int(p.size()); i++)
		ret += cross(p[i] - p[0], p[i - 1] - p[0])/2.0;

	return abs(ret);
}

int signed_area_parallelogram(point2d p1, point2d p2, point2d p3) {
    return cross(p2 - p1, p3 - p2);
}

double triangle_area(point2d p1, point2d p2, point2d p3) {
    return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;
}

bool pointInTriangle(point2d a, point2d b, point2d c, point2d p){
    long long s1 = abs(cross(b-a, c-a));
    long long s2 = abs(cross(a-p, b-p)) + abs(cross(b-p, c-p)) + abs(cross(c-p, a-p));
    return s1 == s2;
}

bool clockwise(point2d p1, point2d p2, point2d p3) {
    return signed_area_parallelogram(p1, p2, p3) < 0;
}

bool counter_clockwise(point2d p1, point2d p2, point2d p3) {
    return signed_area_parallelogram(p1, p2, p3) > 0;
}
	
//Point3D
struct point3d {
    ftype x, y, z;
    point3d() {}
    point3d(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}
    point3d& operator+=(const point3d &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(ftype t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(ftype t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const {
        return point3d(*this) -= t;
    }
    point3d operator*(ftype t) const {
        return point3d(*this) *= t;
    }
    point3d operator/(ftype t) const {
        return point3d(*this) /= t;
    }
};

point3d operator*(ftype a, point3d b) {
    return b * a;
}
ftype dot(point3d a, point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
ftype norm(point3d a) {
    return dot(a, a);
}
double abs(point3d a) {
    return sqrt(norm(a));
}
double proj(point3d a, point3d b) {
    return dot(a, b) / abs(b);
}
double angle(point3d a, point3d b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}
point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}
ftype triple(point3d a, point3d b, point3d c) {
    return dot(a, cross(b, c));
}
point3d intersect(point3d a1, point3d n1, point3d a2, point3d n2, point3d a3, point3d n3) {
    point3d x(n1.x, n2.x, n3.x);
    point3d y(n1.y, n2.y, n3.y);
    point3d z(n1.z, n2.z, n3.z); 
    point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return point3d(triple(d, y, z),
                   triple(x, d, z),
                   triple(x, y, d)) / triple(n1, n2, n3);
}

int main() {
	
	point2d p(-50, 1);
	point2d l1(0, 0);
	point2d l2(4, 0);
		
	cout << dist(p, l1, l2) << endl;
	
	return 0;
}
