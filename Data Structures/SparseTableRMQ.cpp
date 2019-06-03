#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

struct SparseTableRMQ{
	typedef int t_st;
	#define MAXN 200010
	#define MAXLOG 20
	#define cmp(a, b) std::min((a), (b))
	
	t_st st[MAXN][MAXLOG];
	int log[MAXN];
	
	void build(t_st v[], int n){
		log[1] = 0;
		for (int i = 2; i < MAXN; i++)
			log[i] = log[i/2] + 1;
		for(int i=0; i<n; i++)
			st[i][0] = v[i];
		for(int j=1; j< MAXLOG; j++)
			for(int i=0; (i+(1<<(j-1))) < n; i++)
				st[i][j] = cmp(st[i][j-1], st[i+(1<<(j-1))][j-1]);					
	}
	
	int min(int a, int b){
		int j = log[b - a + 1];
		return cmp(st[a][j], st[b - (1 << j) + 1][j]);		
	}
};

SparseTableRMQ st;
int v[MAXN];
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	st.build(v, n);
	
	int q;
	cin >> q;
	
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << st.min(a, b) << endl;
	}
	
	return 0;
}

