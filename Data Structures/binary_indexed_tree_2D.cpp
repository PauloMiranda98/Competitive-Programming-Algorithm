#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 2010
#define MAXM 2010

struct BIT2D{
	#define NBIT MAXN
	#define MBIT MAXN
	
	int tree[NBIT][MBIT];

	//Query: O(log(n*m))
	int query(int i, int j){	
		int s = 0;

		for(int a=i; a > 0; a-=(a & -a))
			for(int b=j; b > 0; b-=(b & -b))
				s += tree[a][b];
			
		return s;
	}

	//Query: O(log(n*m))
	int query2(int a, int b, int c, int d){				
		return query(c, d) - query(c, b-1) - query(a-1, d) + query(a-1, b-1);
	}


	//update: O(log(n*m))
	void update(int i, int j, int value){				
		for(int a=i; a < NBIT; a+=(a & -a))
			for(int b=j; b < MBIT; b+=(b & -b))
				tree[a][b] += value;

	}
	
};

BIT2D bit;

int mat[MAXN][MAXM];
int n, m;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> mat[i][j];
			bit.update(i, j, mat[i][j]);
		}
	}
		
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		char op;
		
		cin >> op;
		if(op == 'q'){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			cout << bit.query2(a, b, c, d) << endl;
		}else{
			int x, y, value;
			cin >> x >> y >> value;
			bit.update(x, y, value);	
		}
	}
		
	return 0;
	
}
