#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef int Node;
const Node neutral = 0;

struct SegmentTreeI{
	vector<Node> a;
	int n;

	inline Node join(Node a, Node b){
		return a + b;
	}

	SegmentTreeI(vector<Node> &v) {
		int sz = v.size();
		for (n = 1; n < sz; n <<= 1);
		a.assign(n << 1, neutral);
		for(int i=0; i<sz; i++) a[i+n] = v[i];
		for(int i=n+sz-1; i>1; i--)
			a[i>>1] = join(a[i>>1], a[i]);
	}	
	//0-index
	void update(int i, Node x) {
		a[i += n] = x;
		for (i >>= 1; i; i >>= 1)
			a[i] = join(a[i<<1], a[1+(i<<1)]);
	}
	//0-index
	Node query(int l, int r) {
		Node ans = neutral;
		for (l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
			if (l & 1) ans = join(ans, a[l++]);
			if (r & 1) ans = join(ans, a[--r]);
		}
		return ans;
	}
};

int n;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n;
	vector<int> v(n);

	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	SegmentTreeI st(v);
	
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		char op;
		
		cin >> op;
		if(op == 'q'){
			int a, b;
			cin >> a >> b;
			cout << st.query(a, b) << endl;
		}else{
			int index, value;
			cin >> index >> value;
			st.update(index, value);	
		}
	}
		
	return 0;
	
}
