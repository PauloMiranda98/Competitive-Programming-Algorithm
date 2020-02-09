#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 100000000

struct Dinic {
	struct FlowEdge {
		int v, u;
		long long cap, flow = 0;
		FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
	};

	const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.push_back(FlowEdge(v, u, cap));
        edges.push_back(FlowEdge(u, v, 0));
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long max_flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
    
    vector<pii> recover_cut() {
		fill(level.begin(), level.end(), 0);

		vector<pii> rc;
		q.push(s);
		level[s] = 1;
		
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (int id : adj[v]) {
				if( (id&1) == 1)
					continue;
					
                if (edges[id].cap == edges[id].flow){					
					rc.push_back(pii(edges[id].v, edges[id].u));
                }else{
					if(level[edges[id].u] == 0){
						q.push(edges[id].u);
						level[edges[id].u] = 1;
					}
				}
            }
        }
        
		vector<pii> ans;
        for(pii p : rc){
			if( (level[p.first] == 0) or (level[p.second] == 0)  ){
				ans.push_back(p);
			}
		}
                
        return ans;
    }	
    
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Dinic fluxo(8, 0, 7);
	int x, y, z;
	int a, b, c;
	
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	fluxo.add_edge(0, 1, x);		
	fluxo.add_edge(0, 2, y);
	fluxo.add_edge(0, 3, z);

	fluxo.add_edge(1, 4, INF);		
	fluxo.add_edge(2, 4, INF);		
	fluxo.add_edge(2, 5, INF);		
	fluxo.add_edge(3, 4, INF);		
	fluxo.add_edge(3, 5, INF);		
	fluxo.add_edge(3, 6, INF);		
	
	fluxo.add_edge(4, 7, a);		
	fluxo.add_edge(5, 7, b);
	fluxo.add_edge(6, 7, c);
	
	cout << fluxo.max_flow() << endl;
	return 0;
}

