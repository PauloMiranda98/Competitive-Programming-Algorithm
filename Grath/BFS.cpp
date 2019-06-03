#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int N = 500010;
const int INF = 0x3f3f3f3f;

vector<int> adj[N];
bool used[N];
int d[N];
int p[N];

void bfs(int s, int n){
	for(int i=0; i<=n; i++){
		used[i] = false;
		d[i] = INF;
		p[i] = -1; 
	}

	queue<int> q;
	q.push(s);
	used[s] = true;
	d[s] = 0;
	p[s] = -1;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (!used[u]) {
				used[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
				p[u] = v;
			}
		}
	}	
}

int main() {
	int n, m, s;
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);		
		adj[b].push_back(a);		
	}
	
	cin >> s;
	bfs(s, n);
	
	for(int i=1; i<=n; i++)
		cout << d[i] << ((i<n) ? ' ': '\n');	
			
	return 0;	
}
