#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 200010

int n, v[MAXN], tree[4*MAXN];
int neutral = 1;

int join(int a, int b){
	ll r = ll(a)*ll(b);
	
	if(r > 0)
		return 1;
	if(r < 0)
		return -1;

	return 0;
}

//Build: O(4*n) -> O(n); call -> build(1, 1, n)
void build(int node, int i, int j){
	if(i == j){
		tree[node] = join(v[i], neutral);
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
int query(int node, int i, int j, int a, int b){
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
		v[index] = value;
		tree[node] = join(value, neutral);
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

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
		
	while(cin >> n >> q){
		for(int i=1; i<=n; i++){
			cin >> v[i];
		}
		
		build(1, 1, n);
				
		for(int i=0; i<q; i++){
			char op;
			
			cin >> op;
			if(op == 'P'){
				int a, b;
				cin >> a >> b;
				int r = query(1, 1, n, a, b);
				
				if(r == 0)
					cout << "0";
				else if(r > 0)
					cout << "+";
				else
					cout << "-";
			}else{
				int index, value;
				cin >> index >> value;
				update(1, 1, n, index, value);	
			}
		}
		cout << endl;
	}
	return 0;
	
}
