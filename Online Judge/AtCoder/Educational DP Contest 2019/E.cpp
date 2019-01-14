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

ll w[110];
int v[110];
ll dp[110][100010];
int n;
ll W;

int solveI(){
	for(int j=0; j<=100000; j++)
		dp[0][j] = INFLL;

	dp[0][0] = 0LL;
	dp[0][v[0]] = w[0];
		
	for(int i=1; i<n; i++){
		for(int j=0; j<v[i]; j++)
			dp[i][j] = dp[i-1][j];
		for(int j=v[i]; j<=100000; j++)
			dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);		
	}

	int ans = 0;

	for(int i=0; i<n; i++){
		for(int j=ans; j<=100000; j++){
			if( (dp[i][j]<=W) and (j>ans))
				ans = j;
		}
	}	
	
	return ans;
}

int main() {
	
	scanf("%d %lld", &n, &W);
	
	for(int i=0; i<n; i++)
		scanf("%lld %d", &w[i], &v[i]);

	printf("%d\n", solveI());
		
	return 0;	
}
