#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 200010

int n, v[MAXN], tree[MAXN];

//Query: O(log(n)), returns the sum of 1 to i
int query(int i){	
	int s = 0;

	while(i > 0){
		s += tree[i];
		i -= (i & -i);
	}
	
	return s;
}

//Query2: O(log(n))
int query2(int v){
	int sum = 0;
	int pos = 0;
	#define LOGN 19
	
	for(int i=LOGN; i>=0; i--){
		if( (pos + (1 << i) <= n) and (sum + tree[pos + (1 << i)] < v) ){
			sum += tree[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1;
}

//update: O(log(n)), sum value in v[i]
void update(int i, int value){	
	v[i] += value;
	
	while(i <= n){ 
		tree[i] += value;
		i += (i & -i);
	}
}

//Build: O(n*log(n))
void build(){
	for(int i=1; i<=n; i++)
		update(i, v[i]);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> v[i];
	}
	
	build();
	
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		char op;
		
		cin >> op;
		if(op == 'q'){
			int a, b;
			cin >> a >> b;
			cout << query(b) - query(a-1) << endl;
		}else{
			int index, value;
			cin >> index >> value;
			update(index, value);	
		}
	}
		
	return 0;
	
}
