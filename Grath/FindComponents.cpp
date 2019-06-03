#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500010;

int n, m;
vector<int> adj[MAXN];
bool used[MAXN] ;
vector<int> comp ;

void dfs(int u) {
    used[u] = true ;
    comp.push_back(u);
    for(int to : adj[u]) {
        if (!used[to])
            dfs(to);
    }
}

void find_comps() {
    for (int i = 1; i <= n ; ++i)
        used [i] = false;
    for (int i = 1; i <= n ; ++i)
        if (!used[i]) {
            comp.clear();
            dfs(i);
            cout << "Component:" ;
            for (size_t j = 0; j < comp.size(); ++j)
                cout << ' ' << comp[j];
            cout << endl ;
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
	
	find_comps();
	
	return 0;	
}








