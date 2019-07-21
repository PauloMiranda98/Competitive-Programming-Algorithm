#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

typedef int ftype;

struct Line{
    ftype k, b;
    Line() {}
    Line(ftype k, ftype b): k(k), b(b) {}
    
    bool operator <(Line &t){
		if(k == t.k)
			return b > t.b;
		return k < t.b;
	}
};

ftype dot(Line a, Line b) {
    return a.k * b.k + a.b * b.b;
}

ftype f(Line a,  ftype x) {
    return dot(a, Line(x, 1));
}


const int INF = 0x3f3f3f3f;
const int MAXN = 2e5;

struct LiChaoTree{

	Line line[4 * MAXN];
	LiChaoTree(){
		for(int i=0; i<4*MAXN; i++){
			line[i] = Line(0, INF);
		}
	}

	void add_line(Line nw, int v = 1, int l = 0, int r = MAXN) {
		int m = (l + r) / 2;
		bool lef = f(nw, l) < f(line[v], l);
		bool mid = f(nw, m) < f(line[v], m);
		if(mid) {
			swap(line[v], nw);
		}
		if(r - l == 1) {
			return;
		} else if(lef != mid) {
			add_line(nw, 2 * v, l, m);
		} else {
			add_line(nw, 2 * v + 1, m, r);
		}
	}	
	
	int get(int x, int v = 1, int l = 0, int r = MAXN) {
		int m = (l + r) / 2;
		if(r - l == 1) {
			return f(line[v], x);
		} else if(x < m) {
			return min(f(line[v], x), get(x, 2 * v, l, m));
		} else {
			return min(f(line[v], x), get(x, 2 * v + 1, m, r));
		}
	}	
};

int main() {
	int n;
	cin >> n;
	vector<Line> vl;
	LiChaoTree lct;
	for(int i=0; i<n; i++){
		int k, b;
		cin >> k >> b;
		
		lct.add_line(Line(k, b));
	}
	
	for(int i=0; i<5; i++)
		cout << "x = "<< i << ": " << lct.get(i) << endl;
		
	
	return 0;
}

