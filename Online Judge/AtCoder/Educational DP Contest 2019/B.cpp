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

int h[100010];
int dp[100010];
int n, k;

int solveR(int i){
	if(i == n)
		return 0;
		
	if(dp[i] != -1)
		return dp[i];
	
	dp[i] = abs(h[i]-h[i+1]) + solveR(i+1);
	for(int j=2; (j<=k) and (i+j<=n); j++)
		dp[i] = min(dp[i], abs(h[i]-h[i+j]) + solveR(i+j) );

	return dp[i];
}

int solveI(){
	dp[1] = 0;
	
	for(int i=2; i<=n; i++){
		dp[i] = abs(h[i]-h[i-1]) + dp[i-1];
		for(int j=2; (j<=k) and (i-j>=1); j++){
			dp[i] = min(dp[i], dp[i-j] + abs(h[i]-h[i-j]));
		}
	}
	return dp[n];
}

int main() {
	
	scanf("%d %d", &n, &k);
	
	for(int i=1; i<=n; i++)
		scanf("%d", &h[i]);

//	memset(dp, -1, sizeof(dp));
//	printf("%d\n", solveR(1));
	printf("%d\n", solveI());
		
	return 0;	
}
