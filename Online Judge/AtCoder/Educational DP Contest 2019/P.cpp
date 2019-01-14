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

ll memo[100010][2];
vector<int> adj[100010];

ll dp(int u, int l, bool is_black){
	
	if(memo[u][is_black] != -1LL)
		return memo[u][is_black];

	ll case1 = 1LL, case2=1LL;
	
	for(int v: adj[u]){
		if(v == l)
			continue;
			
		if(is_black){
			case1 = (case1 * dp(v, u, false))%MOD;
		}else{
			case1 = (case1 * dp(v, u, false) )%MOD;
			case2 = (case2 * dp(v, u, true) )%MOD;			
		}
	}
	
	if(is_black)
		memo[u][is_black] = case1;
	else
		memo[u][is_black] = (case1 + case2)%MOD;
		
	return memo[u][is_black] ;
}

int main() {	
	memset(memo, -1, sizeof(memo));
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for(int i=1; i<n; i++){
		int a, b;
		cin >> a >> b;
		
		adj[a].PB(b);
		adj[b].PB(a);		
	}
	
	cout << dp(1, 0, false) << endl;

	return 0;	
}
