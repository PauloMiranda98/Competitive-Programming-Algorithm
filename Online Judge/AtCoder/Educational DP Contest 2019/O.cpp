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

ll memo[30][1<<22];
bool mat[30][30];

int n;

ll dp(int i, int mask){
	if(i == n)
		return 1LL;
			
	if(memo[i][mask] != -1LL)
		return memo[i][mask];
	
	ll ans = 0LL;
		
	for(int k=0; k<n; k++){
		if(mat[i][k] and (mask & (1<<k)) )
			ans = ( ans + dp(i+1, mask &(~(1<<k))) )%MOD;
	}
	
	return memo[i][mask] = ans;
}

int main() {	
	memset(memo, -1, sizeof(memo));
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> mat[i][j];
	
	cout << dp(0, (1<<n) -1) << endl;

	return 0;	
}
