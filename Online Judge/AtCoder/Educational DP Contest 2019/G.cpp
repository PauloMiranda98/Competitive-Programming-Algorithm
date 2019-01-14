#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<int,int> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii > vpi;

//#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define cl(x, v) memset((x), (v), sizeof(x))
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define MOD 1000000007LL
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (( (a)/__gcd((a), (b)) )*(b))

vector<int> adj[100010];
int memo[100010];
int n, m;

int dfs(int u){
	int r = 0;
	
	if(memo[u] != -1)	
		return memo[u];
	
	for(int v: adj[u]){
		r = max(r, 1 + dfs(v));
	}
	
	return memo[u] = r;
}

int main() {
	
	memset(memo, -1, sizeof(memo));
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		
		adj[a].PB(b);		
	}
	
	int r = 0;
	for(int i=1; i<=n; i++)
		r = max(r, dfs(i));

	cout << r << endl;

	return 0;	
}
