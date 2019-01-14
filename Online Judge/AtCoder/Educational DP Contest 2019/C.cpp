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

int a[100010];
int b[100010];
int c[100010];

int dp[100010][4];
int n, k;

int solveR(int i, int l){
	if(i == n)
		return 0;
		
	if(dp[i][l] != -1)
		return dp[i][l];
	
	int ans = 0;

	if(l != 0)
		ans = max(ans, a[i] + solveR(i+1, 0));
	if(l != 1)
		ans = max(ans, b[i] + solveR(i+1, 1));
	if(l != 2)
		ans = max(ans, c[i] + solveR(i+1, 2));
		
	return dp[i][l] = ans;
}

int solveI(){
	dp[0][0] = a[0];
	dp[0][1] = b[0];	
	dp[0][2] = c[0];
	
	for(int i=1; i<n; i++){		
		dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);		
	}
	
	return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}

int main() {
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
		scanf("%d %d %d", &a[i], &b[i], &c[i]);

//	memset(dp, -1, sizeof(dp));
//	printf("%d\n", solveR(0, 3));
	printf("%d\n", solveI());
		
	return 0;	
}
