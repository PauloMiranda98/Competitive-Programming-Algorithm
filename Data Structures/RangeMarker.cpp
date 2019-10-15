#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 200010;
struct Node{
	int range, ans;
	Node(){
		range = ans = 0;
	}
};

struct RangeMarker{	 
	int n;	
	vector<Node> tree;
	vector<int> lazy;
	Node neutral;
	
	RangeMarker(int mx){
		n = mx;
		tree.resize(4*mx + 10);
		lazy.resize(4*mx + 10);
	}
	
	void update(int node, int i, int j, int a, int b, int delta){
		int l = (node<<1);
		int r = l + 1;
		
		if(a<=i and j<=b){
			tree[node].range += delta;
		}else{ 
			int m = (i+j)/2;
			if(a<=m) update(l, i, m, a, b, delta);
			if(m<b) update(r, m+1, j, a, b, delta);
		}		
		if(tree[node].range > 0){
			tree[node].ans = j - i + 1;
		}else{
			tree[node].ans = 0;
			if(i < j)
				tree[node].ans = tree[l].ans + tree[r].ans;
		}
	}
	
	int query(){
		return tree[1].ans;
	}
	
	void update(int i, int j, int delta){
		update(1, 1, n, i, j, delta);
	}
};

RangeMarker st(100000);

int main() {				
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		char op;		
		cin >> op;
		if(op == 'q'){
			cout << st.query() << endl;
		}else{
			int a, b, delta;
			cin >> a >> b >> delta;
			st.update(a, b, delta);	
		}
	}
		
	return 0;
	
}
