#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAXN 200010
 
struct SegTreeLazy{

	#define NSeg 4*MAXN
	typedef int Node;
	
	int n;
	int *v;

	Node tree[NSeg];
	Node neutral = 0;
	int lazy[NSeg];
		
	inline Node join(Node a, Node b){
		return a+b;
	}
	
	inline void upLazy(int &node, int &i, int &j){
		if(lazy[node] != 0){
			tree[node] += lazy[node]*(j-i+1);		
			//tree[node] += lazy[node];
			
			if(i != j){				
				lazy[(node<<1)] += lazy[node];
				lazy[(node<<1)+1] += lazy[node];			
			}
			lazy[node] = 0;
		}
	}
	//Build: O(4*n) -> O(n); call -> build(1, 1, n)
	void build(int node, int i, int j){
		lazy[node] = 0;
		
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
		upLazy(node, i, j);
				
		if( (i>b) or (j<a) )
			return neutral;

		if( (a<=i) and (j<=b) ){
			return tree[node];
		}

		int m = (i+j)/2;
		int l = (node<<1);
		int r = l + 1;
		
		return join( query(l, i, m, a, b), query(r, m+1, j, a, b) );
	}

	//Update: O(log(n)); call -> update(1, 1, n, a, b, value)
	void update(int node, int i, int j, int a, int b, int value){		
		upLazy(node, i, j);

		if( (i>j) or (i>b) or (j<a) )
			return;

		if( (a<=i) and (j<=b) ){
			lazy[node] = value;
			upLazy(node, i, j);
		}else{
			int m = (i+j)/2;
			int l = (node<<1);
			int r = l + 1;
			
			update(l, i, m, a, b, value);
			update(r, m+1, j, a, b, value);		
			
			tree[node] = join(tree[l], tree[r]);
		}	
	}
	
	inline void build(int _v[], int _n){
		n = _n;
		v = _v;
		build(1, 1, n);
	}
	
	inline int query(int a, int b){
		return query(1, 1, n, a, b);
	}
	inline void update(int a, int b, int value){
		update(1, 1, n, a, b, value);		
	}
	
};

int n, v[MAXN];
SegTreeLazy st;

int main() {		
	cin >> n;

	for(int i=1; i<=n; i++)
		cin >> v[i];	
	
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
			int a, b, value;
			cin >> a >> b >> value;
			st.update(a, b, value);	
		}
	}
		
	return 0;
	
}
