#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010
#define INF 0x3f3f3f3f
typedef long long ll;

typedef pair<int, ll> pil;
vector<pil> adjList[MAXN];

namespace n_lca{
	const int MAXLOGN = 20;
	typedef ll lca_t;
	typedef pair<int, lca_t> lca_p;

	const lca_t neutral = 0;

	int level[MAXN], n;
	int P[MAXN][MAXLOGN];
	lca_t D[MAXN][MAXLOGN];

	lca_t join(lca_t a, lca_t b){
		return a + b;
	}
	void dfs(int u) {
		for(int i=0; i < (int)adjList[u].size(); i++) {
			int v = adjList[u][i].first;
			ll w = adjList[u][i].second;
			
			if(v == P[u][0]) continue;
			P[v][0] = u; D[v][0] = w;
			level[v] = 1 + level[u];
			dfs(v);
		}
	}

	void build(int root, int _n) {
		n = _n;
		level[root] = 0;
		P[root][0] = root; D[root][0] = neutral;
		dfs(root);
		for(int j = 1; j < MAXLOGN; j++)
			for(int i = 1; i <= n; i++) {
				P[i][j] = P[P[i][j-1]][j-1];
				D[i][j] = join(D[P[i][j-1]][j-1], D[i][j-1]);
			}
	}

	lca_p lca(int u, int v) {
		if (level[u] > level[v]) swap(u, v);
		int d = level[v] - level[u];
		lca_t ans = neutral;
		for(int i = 0; i < MAXLOGN; i++) {
			if (d & (1<<i)) {
				ans = join(ans, D[v][i]);
				v = P[v][i];
			}
		}	
		if (u == v) return lca_p(u, ans);
		for(int i = MAXLOGN-1; i >= 0; i--){
			while(P[u][i] != P[v][i]) {
				ans = join(ans, D[v][i]);
				ans = join(ans, D[u][i]);
				u = P[u][i]; v = P[v][i];
			}
		}
		ans = join(ans, D[v][0]);
		ans = join(ans, D[u][0]);
		
		return lca_p(P[u][0], ans);
	}
};

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for(int i=0; i<(n-1); i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		adjList[u].push_back(pil(v, w));
		adjList[v].push_back(pil(u, w));
	}	
	
	n_lca::build(1, n);
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		int a, b;
		cin >> a >> b;
		
		cout << n_lca::lca(a, b).second << endl;
	}	
	
	
	return 0;
}
