#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < int(b);i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define MOD 1000000007
#define endl '\n'
#define mdc(a,b) (__gcd((a),(b)))
#define mmc(a,b) (((a)/mdc(a,b)) * b)
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << endl
const int MAXN = 100010;

int tin[2*MAXN];
int tout[2*MAXN];
int v[2*MAXN];
int aux[2*MAXN];
int tempo=0;

vector<int> adj[MAXN];
int pai[MAXN];
bool mark[MAXN];

void dfs(int u, int d){
	tin[u] = ++tempo;
	v[tempo] = d;
	aux[tempo] = u;
	for(int to: adj[u])
		dfs(to, d+1);
	tout[u] = ++tempo;
	v[tempo] = d;	
	aux[tempo] = u;
}
struct SegTree{
	int n;
	pii tree[8*MAXN];
	int lazy[8*MAXN];
	pii neutral = pii(-INF, -1);
	inline pii join(pii a, pii b){
		return max(a, b);
	}
	inline void uplazy(int &node, int i, int j){
		if(lazy[node] != 0){
			tree[node].F += lazy[node];
			if(i != j){
				lazy[(node<<1)] += lazy[node];
				lazy[(node<<1) + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	
	void build(int node, int i, int j){
		lazy[node] = 0;
		if(i == j){
			tree[node] = pii(v[i], i);
			return;
		}

		int m = (i + j)/2;
		int l = (node<<1);
		int r = l + 1;
		build(l, i, m);
		build(r, m+1, j);
		tree[node] = join(tree[l], tree[r]);
	}
	
	pii query(int node, int i, int j, int a, int b){
		uplazy(node, i, j);
		
		if( (i>b) or (j < a) )
			return neutral;
		if( (a <= i) and (j <= b) )
			return tree[node];
		int m = (i + j)/2;
		int l = (node<<1);
		int r = l +  1;
		return join(query(l, i, m, a, b), query(r, m+1, j, a, b));
	}

	void update(int node, int i, int j, int a, int b, int value){
		uplazy(node, i, j);
		
		if( (i > j) or (i>b) or (j < a) )
			return;
		if( (a <= i) and (j <= b) ){
			lazy[node] = value;
			uplazy(node, i, j);
			return;
		}
		int m = (i + j)/2;
		int l = (node<<1);
		int r = l +  1;
		update(l, i, m, a, b, value);
		update(r, m+1, j, a, b, value);
		tree[node] = join(tree[l], tree[r]);
	}

};

int n, k;
SegTree st;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	
	for(int i=2; i<=n; i++){
		int p;
		cin >> p;
		pai[i] = p;
		adj[p].PB(i);
	}
	dfs(1, 1);

	st.build(1, 1, tempo);

	int ans = 0;
	for(int i=0; i<k; i++){
		int pos = st.query(1, 1, tempo, 1, tempo).S;
		int u = aux[pos];
		while( (u >= 1) and !mark[u]){
			st.update(1, 1, tempo, tin[u], tout[u], -1);
			ans++;
			mark[u] = true;
			u = pai[u];
		}
	}
	
	cout << ans << endl;
	return 0;
}
