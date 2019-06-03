#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll, ll> pll;
const double EPS = 1e-9;

typedef ll ftype;

//Check intersect segment INT
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

ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}

int sgn(const ll& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(ll a, ll b, ll c, ll d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const point2d& a, const point2d& b, const point2d& c, const point2d& d) {
    if (cross(a-c, d-c) == 0 && cross(b-c, d-c) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(cross(b-a, c-a)) != sgn(cross(b-a, d-a)) &&
           sgn(cross(d-c, a-c)) != sgn(cross(d-c, b-c));
}

int main() {
	
	point2d a(0, 0);
	point2d b(0, 4);

	point2d c(0, 2);
	point2d d(0, 8);
	
	cout << check_inter(a, b, c, d) << endl;

	c.y = 4;
	cout << check_inter(a, b, c, d) << endl;

	c.y = 5;
	cout << check_inter(a, b, c, d) << endl;
	
	return 0;
}
