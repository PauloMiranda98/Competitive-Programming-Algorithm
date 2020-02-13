
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAXN 100100

using namespace std;

vector<long> vizinhos[MAXN];
vector<long> memo[MAXN];

long pos(long p, long a){	
	return lower_bound(vizinhos[p].begin(), vizinhos[p].end(), a+1) - vizinhos[p].begin();
}

long BFS(long u, long a){	
		
	if(a == (long) vizinhos[u].size())
		return 1;
	if(memo[u][a])
		return memo[u][a];
		
	return memo[u][a] = max( BFS( vizinhos[u][a], pos(vizinhos[u][a], u)  ) + 1, BFS(u, a+1) );
	
}

int main(){
	
	long n, m;
	long a, b;
	
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	cin >> n >> m;
	
	while(m--){
		cin >> a >> b;
		
		vizinhos[a].push_back(b);
		memo[a].push_back(0);
		
		vizinhos[b].push_back(a);
		memo[b].push_back(0);
	}

	for(long i=1; i<=n; i++){
		sort(vizinhos[i].begin(), vizinhos[i].end());
	}
			
	for(long i=1; i<n; i++){
		cout << BFS(i, 0) << " ";
	}
	
	cout << BFS(n, 0) << endl;
	
	return 0;
}
