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

ll memo[410][410];
ll v[410];
ll sum[410];

int n;

ll dp(int i, int j){
	if(i == j)
		return 0LL;
		
	if( (i+1) == j)	
		return v[i] + v[j];
	
	if(memo[i][j] != -1LL)
		return memo[i][j];
	
	ll ans = INFLL;
		
	for(int k=i; k<j; k++){
		if(k == i)
			ans = min(ans, sum[j] - sum[i-1] + dp(i,k+1) + dp(k+2, j) );		
		else if(k == j-1)
			ans = min(ans, sum[j] - sum[i-1] + dp(i,k-1) + dp(k, j) );				
		else
			ans = min(ans, sum[j] - sum[i-1] + min(dp(i,k+1) + dp(k+2, j), dp(i,k-1) + dp(k, j)) );		
	}
	
	return memo[i][j] = ans;
}

int main() {	
	memset(memo, -1, sizeof(memo));
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> v[i];
		sum[i] = sum[i-1] + v[i];
	}
	
	cout << dp(1, n) << endl;

	return 0;	
}
