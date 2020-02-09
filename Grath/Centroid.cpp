#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
typedef pair<int, int> pii;
vector<int> adj[MAXN];
int sub[MAXN];
int n;

int dfs(int u, int p){
	sub[u] = 1;
	for(int to: adj[u]){
		if(to != p)
			sub[u] += dfs(to, u);
	}
	return sub[u];
}

pii centroid(int u, int p){
	for(int to : adj[u]){
		if(to != p and sub[to] > n/2)
			return centroid(to, u);		
	}	

	for(int to : adj[u]){
		if(to != p and (sub[to]*2) == n)
			return pii(u, to);
	}	

	return pii(u, u);
}

int main(){   
	cin >> n;
	for(int i=1; i<n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(1, -1);
	pii c = centroid(1, -1);
	cout << c.first << " " << c.second << endl;
	
    return 0;
}
