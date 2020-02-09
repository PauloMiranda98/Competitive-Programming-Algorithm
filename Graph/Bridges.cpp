#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500010;

int n, m;
vector<int> adj[MAXN]; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

vector<pair<int, int> > bridges;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.push_back({v, to});
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main(){	
	
	cin >> n >> m;

	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	find_bridges();
	
	cout << "Has " << bridges.size() <<" Bridges: " << endl;
	
	for(auto b: bridges)
		cout << b.first << " " << b.second << endl; 
	
	return 0;	
}








