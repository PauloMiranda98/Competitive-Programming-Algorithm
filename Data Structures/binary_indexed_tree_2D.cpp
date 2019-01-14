#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 2010

int n, m, mat[MAXN][MAXN], tree[MAXN][MAXN];

//Query: O(log(n*m))
int query(int i, int j){	
	int s = 0;

	for(int a=i; a > 0; a-=(a & -a))
		for(int b=j; b > 0; b-=(b & -b))
			s += tree[a][b];
		
	return s;
}

//update: O(log(n*m))
void update(int i, int j, int value){	
	mat[i][j] += value;
	
	for(int a=i; a<=n; a+=(a & -a))
		for(int b=j; b <= m; b+=(b & -b))
			tree[a][b] += value;

}

//Build: O(n*m*log(n*m))
void build(){
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			update(i, j, mat[i][j]);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n >> m;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> mat[i][j];
		}
	}
	
	build();
	
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		char op;
		
		cin >> op;
		if(op == 'q'){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			cout << query(c, d) - query(c, b-1) - query(a-1, d) + query(a-1, b-1) << endl;
		}else{
			int x, y, value;
			cin >> x >> y >> value;
			update(x, y, value);	
		}
	}
		
	return 0;
	
}
