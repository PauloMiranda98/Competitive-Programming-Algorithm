#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

struct CentroidDecomposition {
	vector<set<int>> adj;
	vector<int> dad;
	vector<int> sub;

	CentroidDecomposition(vector<set<int>> &adj) : adj(adj) {
		int n = adj.size();
		dad.resize(n);
		sub.resize(n);
		build(0, -1);
	}

	void build(int u, int p = -1) {
		int n = dfs(u, p); 
		int centroid = dfs(u, p, n); 
		if (p == -1) p = centroid;
		dad[centroid] = p;

		for(auto v : adj[centroid]){
			adj[v].erase(centroid);
			build(v, centroid);
		}
		adj[centroid].clear();
	}

	int dfs(int u, int p) {
		sub[u] = 1;

		for(auto v : adj[u])
			if (v != p) sub[u] += dfs(v, u);

		return sub[u];
	}

	int dfs(int u, int p, int n) {
		for (auto v : adj[u])
			if (v != p and sub[v] > n/2) return dfs(v, u, n);

		return u;
	}

	int operator[](int i) {
		return dad[i];
	}
};

int n;
vector<set<int> > adj;

int main(){   
	cin >> n;
	for(int i=1; i<n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	CentroidDecomposition cd(adj);
	
    return 0;
}
