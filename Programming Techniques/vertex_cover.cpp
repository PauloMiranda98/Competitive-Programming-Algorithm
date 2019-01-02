#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 200010

int dp[MAXN][2];
int ancestral[MAXN];
int n;
vector<int> adj[MAXN];

//VertexCover: O(2*N) -> O(N) 
int vertexCover(int x, bool color){
	
	if(dp[x][color] != -1) 
		return dp[x][color]; 
	
	int case1 = 1, case2 = 0;
	
	for(int v: adj[x]){ 
		
		if(v == ancestral[x])
			continue;
		
		ancestral[v] = x;
		case1 += vertexCover(v, true);
		case2 += vertexCover(v, false);
	}
	
	if(color) 
		dp[x][color] = min(case1, case2);
	else 
		dp[x][color] = case1; 
	
	return dp[x][color];
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dp, -1, sizeof(dp));
	memset(ancestral, -1, sizeof(ancestral));
	
	cin >> n;
	
	for(int i=0; i<(n-1); i++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	cout << vertexCover(1, true) << endl;
					
	return 0;
	
}
