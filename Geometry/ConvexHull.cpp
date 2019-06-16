#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

typedef ll ftype;

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

//If accept collinear points then change for <=
bool cw(point2d a, point2d b, point2d c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

//If accept collinear points then change for >=
bool ccw(point2d a, point2d b, point2d c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<point2d> convex_hull(vector<point2d> a) {
    if (a.size() == 1)
        return a;

    sort(a.begin(), a.end(), cmp);

    a.erase(unique(a.begin(), a.end(), eq), a.end());
    
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

int main() {
	
	int n;
	
	cin >> n;
	vector<point2d> v(n);
	
	for(int i=0; i<n; i++){
		cin >> v[i].x >> v[i].y;
	}
	
	vector<point2d> ch = convex_hull(v);

	cout << ch.size() << endl;
	for(point2d p: ch)
		cout << p.x << " " << p.y << endl; 
	
	return 0;
}
