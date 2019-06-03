#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int N = 500010;

pii parent[N];
int _rank[N];
int bipartite[N];

void make_set(int v) {
    parent[v] = pii(v, 0);
    _rank[v] = 0;
    bipartite[v] = true;
}

pii find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

void add_edge(int a, int b) {
    pii pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            bipartite[a] = false;
    }else{
        if (_rank[a] < _rank[b])
            swap (a, b);
        parent[b] = pii(a, x^y^1);
        bipartite[a] &= bipartite[b];
        if (_rank[a] == _rank[b])
            ++_rank[a];
    }
}

bool is_bipartite(int v) {
    return bipartite[find_set(v).first];
}

int main() {
	int n, q;
	cin >> n >> q;
	
	for(int i=1; i<=n; i++)
		make_set(i);
	
	while(q--){
		int op;
		cin >> op;
		
		//criar aresta
		if(op == 1){
			int a, b;
			cin >> a >> b;
			add_edge(a, b);
		}else{
			int u;
			cin >> u;
			
			if(is_bipartite(u))
				cout << "S" << "\n";
			else
				cout << "N" << "\n";
		}
	}
		
	return 0;	
}
