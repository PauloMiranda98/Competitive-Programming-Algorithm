#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200010;

vector<int> adj_rev[MAXN];

bool winning[MAXN];
bool losing[MAXN];
bool visited[MAXN];
int degree[MAXN];

void dfs(int v) {
    visited[v] = true;
    for (int u : adj_rev[v]) {
        if (!visited[u]) {
            if (losing[v])
                winning[u] = true;
            else if (--degree[u] == 0)
                losing[u] = true;
            else
                continue;
            dfs(u);
        }
    }
}

int game(int x, int n){
	for(int i=0; i<n; i++)
		if( (losing[i] or winning[i]) and !visited[i])
			dfs(i);	
	if(winning[x])
		return 1; //Winning
	if(losing[x])
		return 0; //Losing
	return -1;	  //Draw	
}

int main() {			
		
	return 0;
	
}

