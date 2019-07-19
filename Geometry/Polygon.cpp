#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef ll ftype;

const double PI = acos(-1);
const double EPS = 1e-9;

//Point2D
struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y): x(x), y(y) {}

};

bool cmp(point2d a, point2d b) {
	return (a.x < b.x) or ((a.x == b.x) and (a.y < b.y));
}

bool eq(point2d a, point2d b) {
	return (a.x == b.x) and (a.y == b.y);
}

ftype cross(point2d a, point2d b) {
	return a.x * b.y - a.y * b.x;
}

point2d operator -(point2d a, point2d b){
	return point2d(a.x-b.x, a.y-b.y);
}

//If accept collinear points then change for <=
bool cw(point2d a, point2d b, point2d c) {
    return cross(b - a, c - b) < 0;
}

//If accept collinear points then change for >=
bool ccw(point2d a, point2d b, point2d c) {
    return cross(b - a, c - b) > 0;
}

vector<point2d> convex_hull(vector<point2d> a) {
    sort(a.begin(), a.end(), cmp);
    a.erase(unique(a.begin(), a.end(), eq), a.end());

    if(a.size() == 1)
        return a;
    
    vector<point2d> up, down;

    point2d p1 = a[0], p2 = a.back();
    up.push_back(p1);
    down.push_back(p1);
    
    for (int i = 1; i < (int)a.size(); i++) {
        if ( (i == int(a.size() - 1)) || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if ((i == int(a.size() - 1)) || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for(int i = 0; i < (int)up.size(); i++){
        a.push_back(up[i]);
    }
    for(int i = down.size() - 2; i > 0; i--){
        a.push_back(down[i]);
    }
    return a;
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
double angle(point2d a, point2d b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}


bool pointInTriangle(point2d a, point2d b, point2d c, point2d p){
    ftype s1 = abs(cross(b-a, c-a));
    ftype s2 = abs(cross(a-p, b-p)) + abs(cross(b-p, c-p)) + abs(cross(c-p, a-p));
    return s1 == s2;
}

int sgn(ftype val){
    return val > 0 ? 1 : (val == 0 ? 0 : -1);
}

struct Polygon{
	vector<point2d> vp;
	
	Polygon(vector<point2d> aux){
		vp = aux;
	}
	
	void to_convex_hull(){
		vp = convex_hull(vp);
	}
	
	bool pointInConvex(point2d point){					
		if(cross(vp[1]-vp[0], point-vp[0]) != 0 && sgn(cross(vp[1]-vp[0], point-vp[0]) ) != sgn(cross(vp[1]-vp[0], vp.back()-vp[0])) )
			return false;
		if(cross(vp.back()-vp[0], point-vp[0]) != 0 && sgn(cross(vp.back()-vp[0], point-vp[0]) ) != sgn(cross(vp.back() - vp[0], vp[1]-vp[0])) )
			return false;

		if(cross(vp[1]-vp[0], point-vp[0]) == 0)
			return norm(vp[1]-vp[0]) >= norm(point-vp[0]);

		int pos = 1, l = 1, r = vp.size() - 2;
		
		while(l <= r){
			int mid = (l + r)/2;

			if(cross(vp[mid] - vp[0], point - vp[0]) <= 0){
				pos = mid;
				l = mid+1;
			}else{ 
				r = mid-1;
			}
		}
		
		return pointInTriangle(vp[0], vp[pos], vp[pos+1], point);
	}	

	bool pointInConcave(point2d point){					
		int sz = vp.size();
		if(sz == 0)
			return false;

		double sum = 0;
		vp.push_back(vp[0]);

		for(int i=0; i<sz; i++){
			if(ccw(point, vp[i], vp[i+1]))
				sum += angle(vp[i]-point, vp[i+1]-point);
			else
				sum -= angle(vp[i]-point, vp[i+1]-point);
		}
		
		vp.pop_back();
		return fabs(fabs(sum) - 2*PI) < EPS;
	}


};

int main() {
	
	int n;
	
	cin >> n;
	vector<point2d> v(n);
	
	for(int i=0; i<n; i++){
		cin >> v[i].x >> v[i].y;
	}
	Polygon pol(v);

	pol.to_convex_hull();

	cout << "Convex Hull: ";
	cout << pol.vp.size() << endl;

	for(point2d p: pol.vp)
		cout << p.x << " " << p.y << endl; 
	
	cout << "Point In Polygon: "<< endl;
	point2d p;
	cin >> p.x >> p.y;
			
	cout << pol.pointInConvex(p) << endl;
	
	return 0;
}
