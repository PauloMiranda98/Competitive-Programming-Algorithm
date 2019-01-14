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
int n;

int solveR(int i){
	if(i == n)
		return 0;
	if(dp[i] != -1)
		return dp[i];
		
	if( (i+2) <= n)
		return dp[i] = min(abs(h[i]-h[i+1]) + solveR(i+1), abs(h[i]-h[i+2]) + solveR(i+2));
	else
		return dp[i] = abs(h[i]-h[i+1]) + solveR(i+1);
}

int solveI(){
	dp[1] = 0;
	dp[2] = abs(h[1] - h[2]);
	
	for(int i=3; i<=n; i++)
		dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
	
	return dp[n];
}

int main() {
	
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++)
		scanf("%d", &h[i]);

//	memset(dp, -1, sizeof(dp));
//	printf("%d\n", solveR(1));
	printf("%d\n", solveI());
		
	return 0;	
}
