#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100010;
typedef long long f_type;

struct BIT_Range{
	vector<int> ft1, ft2;

	BIT_Range(int n) {
		ft1.assign(n + 1, 0);
		ft2.assign(n + 1, 0);
	}

	int query(vector<int> & ft, int i) {
		int sum = 0;
		for(; i; i -= (i & -i)) sum += ft[i];
		return sum;
	}
	void update(vector<int> & ft, int i, int v) {
		for(; i < (int)ft.size(); i += (i & -i))
			ft[i] += v;
	}
	void update(int i, int j, int v) {
		update(ft1, i, v);
		update(ft1, j+1, -v);
		update(ft2, i, v*(i-1));
		update(ft2, j+1, -v*j);
	}
	int query(int i) {
		return query(ft1, i)*i - query(ft2, i);
	}
	int query(int i, int j) {
		return query(j) - query(i-1);
	}
};

BIT_Range bit(MAXN);

int n, v[MAXN];

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n;

	for(int i=1; i <= n; i++){
		cin >> v[i];
		bit.update(i, i, v[i]);
	}
		
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		char op;
		
		cin >> op;
		if(op == 'q'){
			int a, b;
			cin >> a >> b;
			cout << bit.query(a, b) << endl;
		}else{
			int a, b;
			f_type value;
			cin >> a >> b >> value;
			bit.update(a, b, value);	
		}
	}
		
	return 0;
	
}
