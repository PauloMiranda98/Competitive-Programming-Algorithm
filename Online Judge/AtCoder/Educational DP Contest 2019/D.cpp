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

int w[110];
ll v[110];
ll dp[110][100010];
int n, W;

ll solveR(int i, int c){
	if(i == n)
		return 0;
		
	if(dp[i][c] != -1LL)
		return dp[i][c];
		
	if( (c + w[i]) <= W)
		return dp[i][c] = max(solveR(i+1, c), solveR(i+1, c + w[i]) + v[i]);
	else
		return dp[i][c] = solveR(i+1, c);
}

ll solveI(){
	for(int j=0; j<w[0]; j++)
		dp[0][j] = 0;
	for(int j=w[0]; j<=W; j++)
		dp[0][j] = v[0];
	
	for(int i=1; i<n; i++){
		for(int j=0; j<w[i]; j++)
			dp[i][j] = dp[i-1][j];
		for(int j=w[i]; j<=W; j++)
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);		
	}
	
	return dp[n-1][W];
}

int main() {
	
	scanf("%d %d", &n, &W);
	
	for(int i=0; i<n; i++)
		scanf("%d %lld", &w[i], &v[i]);

//	memset(dp, -1, sizeof(dp));
//	printf("%lld\n", solveR(0, 0));
	printf("%lld\n", solveI());
		
	return 0;	
}
