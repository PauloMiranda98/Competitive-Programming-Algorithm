#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int N = 500010;
const int INF = 0x3f3f3f3f;

vector<pii> adj[N];
bool used[N];
int d[N];
int p[N];

void bfs_01(int s, int n){
	for(int i=0; i<=n; i++){
		d[i] = INF;
	}
	d[s] = 0;
	p[s] = -1;
	deque<int> q;
	q.push_front(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (auto edge : adj[v]) {
			int u = edge.first;
			int w = edge.second;
			if (d[v] + w < d[u]) {
				p[u] = v;
				d[u] = d[v] + w;
				if (w == 1)
					q.push_back(u);
				else
					q.push_front(u);
			}
		}
	}	
}

int main() {
	int n, m, s;
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		
		adj[a].emplace_back(b, w);		
		adj[b].emplace_back(a, w);		
	}
	
	cin >> s;
	bfs_01(s, n);
	
	for(int i=1; i<=n; i++)
		cout << d[i] << ((i<n) ? ' ': '\n');	
			
	return 0;	
}
