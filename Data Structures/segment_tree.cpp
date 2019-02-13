#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 200010

struct SegTree{

	#define NSeg MAXN
	typedef int Node;
	 
	int n, *v;
	
	Node tree[4*NSeg];
	Node neutral = 0;

	Node join(Node a, Node b){
		return (a + b);
	}

	//Build: O(4*n) -> O(n); call -> build(1, 1, n)
	void build(int node, int i, int j){
		if(i == j){
			tree[node] = v[i];
			return;
		}
		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		build(l, i, m);
		build(r, m+1, j);
		
		tree[node] = join(tree[l], tree[r]);
	}

	//Query: O(log(n)); call -> query(1, 1, n, a, b)
	Node query(int node, int i, int j, int a, int b){
		if( (i>b) or (j<a) )
			return neutral;
		if( (a<=i) and (j<=b) )
			return tree[node];
			
		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		return join( query(l, i, m, a, b), query(r, m+1, j, a, b) );
	}

	//Update: O(log(n)); call -> update(1, 1, n, index, value)
	void update(int node, int i, int j, int index, int value){
		if(i == j){
			tree[node] = v[index] = value;
			return;
		}		
		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		if(index <= m)
			update(l, i, m, index, value);
		else
			update(r, m+1, j, index, value);		
		
		tree[node] = join(tree[l], tree[r]);
	}
	
	void build(int _v[], int _n){
		n = _n;
		v = _v;
		build(1, 1, n);
	}
	
	int query(int a, int b){
		return query(1, 1, n, a, b);
	}
	
	void update(int i, int value){
		update(1, 1, n, i, value);
	}
};

SegTree st;
int n, v[MAXN];

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> v[i];
	}
	
	st.build(v, n);
	
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
