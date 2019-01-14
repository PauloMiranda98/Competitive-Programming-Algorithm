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

ll memo[1010][1010];
char mat[1010][1010];
int n, m;

int dp(int i, int j){
	if(mat[i][j] == '#')
		return 0LL;
	
	if((i == n) and (j == m))
		return 1LL;
		
	if(memo[i][j] != -1LL)	
		return memo[i][j];
	
	return memo[i][j] = (dp(i+1, j) + dp(i, j+1))%MOD;
}

int main() {
	memset(mat, '#', sizeof(mat));
	memset(memo, -1, sizeof(memo));
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin >> mat[i][j];
	
	cout << dp(1, 1) << endl;

	return 0;	
}
