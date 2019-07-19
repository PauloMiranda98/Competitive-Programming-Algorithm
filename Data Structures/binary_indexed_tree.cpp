#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 200010

struct BIT{
	
	#define NBIT MAXN
	
	int tree[NBIT];
	
	//QueryV: O(log(n)), returns the sum of 1 to i
	
	BIT(){
		memset(tree, 0, sizeof(tree));
	}
	
	int queryV(int i){	
		int s = 0;

		while(i > 0){
			s += tree[i];
			i -= (i & -i);
		}
		
		return s;
	}

	int queryV(int l, int r){
		return queryV(r) - queryV(l-1);
	}	

	//QueryP: O(log(n))
	int queryP(int v){
		int sum = 0;
		int pos = 0;
		#define LOGN 19
		
		for(int i=LOGN; i>=0; i--){
			if( (pos + (1 << i) < NBIT) and (sum + tree[pos + (1 << i)] < v) ){
				sum += tree[pos + (1 << i)];
				pos += (1 << i);
			}
		}

		return pos + 1;
	}

	//update: O(log(n)), sum value in v[i]
	void update(int i, int value){				
		while(i < NBIT){ 
			tree[i] += value;
			i += (i & -i);
		}
	}
	
};

BIT bit;
int n, v[MAXN];

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n;

	for(int i=1; i <= n; i++){
		cin >> v[i];
		bit.update(i, v[i]);
	}
		
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		char op;
		
		cin >> op;
		if(op == 'q'){
			int a, b;
			cin >> a >> b;
			cout << bit.queryV(b) - bit.queryV(a-1) << endl;
		}else{
			int index, value;
			cin >> index >> value;
			bit.update(index, value);	
		}
	}
		
	return 0;
	
}
