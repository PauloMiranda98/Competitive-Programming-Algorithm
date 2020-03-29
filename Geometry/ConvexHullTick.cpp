#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

typedef int ftype;

//Point2D
struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y): x(x), y(y) {}
    
    point2d operator-(const point2d &t) {
        return point2d(x - t.x, y - t.y);
    }

};

ftype dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}

ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}

point2d perpL(point2d a) {
    return point2d(-a.y, a.x);
}

point2d perpR(point2d a) {
    return point2d(a.y, -a.x);
}

struct Line{
    ftype k, b;
    Line() {}
    Line(ftype k, ftype b): k(k), b(b) {}
};

struct ConvexHullTick{
	vector<point2d> hull, vecs;
	ConvexHullTick(){		
	}
		
	void add_line(Line l) {
		point2d nw(l.k, l.b);

//		while(!vecs.empty() && dot(vecs.back(), nw - hull.back()) > 0) {//Max
		while(!vecs.empty() && dot(vecs.back(), nw - hull.back()) < 0) {//Min
			hull.pop_back();
			vecs.pop_back();
		}
		if(!hull.empty()) {
//			vecs.push_back(perpR(nw - hull.back())); //Max
			vecs.push_back(perpL(nw - hull.back())); //Min
		}
		hull.push_back(nw);
	}
	
	int get(ftype x) {
		point2d query(x, 1);
		auto it = lower_bound(vecs.begin(), vecs.end(), query, [](point2d a, point2d b) {
			return cross(a, b) > 0;
		});
		return dot(query, hull[it - vecs.begin()]);
	}

	
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Line> vl;
	
	for(int i=0; i<n; i++){
		int k, b;
		cin >> k >> b;
		vl.emplace_back(k, b);
	}
	
	ConvexHullTick cht(vl);
	
	for(int i=0; i<5; i++)
		cout << "x = "<< i << ": " << cht.get(i) << endl;
		
	
	return 0;
}

