#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

struct SparseTable{
	typedef int t_st;
	#define MAXN 200010
	#define MAXLOG 20
	#define cmp(a, b) ((a) + (b))
	#define neutral 0
	
	t_st st[MAXN][MAXLOG];
	
	void build(t_st v[], int n){
		for(int i=0; i<n; i++)
			st[i][0] = v[i];
		for(int j=1; j< MAXLOG; j++)
			for(int i=0; (i+(1<<(j-1))) < n; i++)
				st[i][j] = cmp(st[i][j-1], st[i+(1<<(j-1))][j-1]);					
	}
		
	t_st sum(int a, int b){
		int d = b - a + 1;
		t_st ans = neutral;
		for(int j=MAXLOG-1; j>=0; j--){
			if(d & (1<<j)){
				ans = cmp(ans, st[a][j]);
				a = a + (1<<(j));
			}
		}
		
		return ans;
		
	}
	

};

SparseTable st;
int v[MAXN];
int n;
int main() {	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	st.build(v, n);
	
	int q;
	cin >> q;
	
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << st.sum(a, b) << endl;
	}
	
	return 0;
}

