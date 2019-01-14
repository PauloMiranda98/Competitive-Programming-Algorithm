#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 1024010

int n, v[MAXN], tree[4*MAXN];
int lazy[4*MAXN]; // 0-with, 1-set, 2-clear, 3-inverse
int neutral = 0;

int join(int a, int b){
	return a+b;
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
int query(int node, int i, int j, int a, int b){
	int l = (node<<1);
	int r = l + 1;
	
	if(lazy[node] != 0){
		if(lazy[node] == 1){
			tree[node] = (j-i+1);
			
			if(i != j){
				lazy[l] = lazy[node];
				lazy[r] = lazy[node];			
			}			
		}else if(lazy[node] == 2){
			tree[node] = 0;
			
			if(i != j){
				lazy[l] = lazy[node];
				lazy[r] = lazy[node];			
			}						
		}else{
			tree[node] = (j-i+1) - tree[node];
			
			if(i != j){
				if(lazy[l] == 1)
					lazy[l] = 2;
				else if(lazy[l] == 2){
					lazy[l] = 1;
				}else if(lazy[l] == 3){
					lazy[l] = 0;
				}else{
					lazy[l] = 3;
				}
				
				if(lazy[r] == 1)
					lazy[r] = 2;
				else if(lazy[r] == 2){
					lazy[r] = 1;
				}else if(lazy[r] == 3){
					lazy[r] = 0;
				}else{
					lazy[r] = 3;
				}
				
			}									
		}
		
		lazy[node] = 0;
	}
	
	if( (i>b) or (j<a) )
		return neutral;

	if( (a<=i) and (j<=b) ){
		return tree[node];
	}

	int m = (i+j)/2;
	
	return join( query(l, i, m, a, b), query(r, m+1, j, a, b) );
}

//Update: O(log(n)); call -> update(1, 1, n, a, b, value)
void update(int node, int i, int j, int a, int b, int value){
	int l = (node<<1);
	int r = l + 1;
	
	if(lazy[node] != 0){
		if(lazy[node] == 1){
			tree[node] = (j-i+1);
			
			if(i != j){
				lazy[l] = lazy[node];
				lazy[r] = lazy[node];			
			}			
		}else if(lazy[node] == 2){
			tree[node] = 0;
			
			if(i != j){
				lazy[l] = lazy[node];
				lazy[r] = lazy[node];			
			}						
		}else{
			tree[node] = (j-i+1) - tree[node];
			
			if(i != j){
				if(lazy[l] == 1)
					lazy[l] = 2;
				else if(lazy[l] == 2){
					lazy[l] = 1;
				}else if(lazy[l] == 3){
					lazy[l] = 0;
				}else{
					lazy[l] = 3;
				}
				
				if(lazy[r] == 1)
					lazy[r] = 2;
				else if(lazy[r] == 2){
					lazy[r] = 1;
				}else if(lazy[r] == 3){
					lazy[r] = 0;
				}else{
					lazy[r] = 3;
				}
				
			}									
		}
		
		lazy[node] = 0;
	}

	if( (i>j) or (i>b) or (j<a) )
		return;

	if( (a<=i) and (j<=b) ){
		if(value != 0){
			if(value == 1){
				tree[node] = (j-i+1);
				
				if(i != j){
					lazy[l] = value;
					lazy[r] = value;			
				}			
			}else if(value == 2){
				tree[node] = 0;
				
				if(i != j){
					lazy[l] = value;
					lazy[r] = value;			
				}						
			}else{
				tree[node] = (j-i+1) - tree[node];
				
				if(i != j){
					if(lazy[l] == 1)
						lazy[l] = 2;
					else if(lazy[l] == 2){
						lazy[l] = 1;
					}else if(lazy[l] == 3){
						lazy[l] = 0;
					}else{
						lazy[l] = 3;
					}
					
					if(lazy[r] == 1)
						lazy[r] = 2;
					else if(lazy[r] == 2){
						lazy[r] = 1;
					}else if(lazy[r] == 3){
						lazy[r] = 0;
					}else{
						lazy[r] = 3;
					}
					
				}									
			}
			
		}
		
	}else{
		int m = (i+j)/2;
		
		update(l, i, m, a, b, value);
		update(r, m+1, j, a, b, value);		
		
		tree[node] = join(tree[l], tree[r]);
	}	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	for(int k=1; k<=t; k++){
		n = 0;
		
		int m;
		cin >> m;
		while(m--){
			int f;
			cin >> f;
			
			string s;
			cin >> s;
			
			while(f--){
				for(char c : s){
					v[++n] = int(c-'0');
				}		
			}			
		}
		
		int q;
		cin >> q;

		build(1, 1, n);
		
		cout << "Case " << k << ":" << endl;
		int nq = 1;
		
		for(int i=1; i<=q; i++){
			char op;
			int a, b;
			cin >> op >> a >> b;
			a++;
			b++;
			
			if(op == 'S'){
				cout << "Q" << nq++ << ": " << query(1, 1, n, a, b) << endl;				
			}else if(op == 'F'){
				update(1, 1, n, a, b, 1);
			}else if(op == 'E'){
				update(1, 1, n, a, b, 2);				
			}else{
				update(1, 1, n, a, b, 3);								
			}
		}
		
	}
	
	return 0;
	
}
