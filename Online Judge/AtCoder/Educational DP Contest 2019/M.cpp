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

ll memo[110][100010];
ll sum[110][100010];

int v[110];
int n;

ll solve(int k){
	for(int j=0; j<=v[0]; j++){
		memo[0][j] = 1LL;
		sum[0][j] = j+1; 	
	}
	
	for(int j=v[0]+1; j<=k; j++){
		memo[0][j] = 0LL;
		sum[0][j] = sum[0][j-1]; 			
	}
		
	for(int i=1; i<n; i++){		
		memo[i][0] = sum[i-1][0];
		sum[i][0] = memo[i][0]; 	
		for(int j=1; j<=v[i]; j++){
			memo[i][j] = sum[i-1][j];
			sum[i][j] = (sum[i][j-1] + memo[i][j])%MOD; 	
		}
		
		for(int j=v[i]+1; j<=k; j++){
			memo[i][j] = (MOD+(sum[i-1][j] - sum[i-1][j-v[i]-1])%MOD)%MOD;
			sum[i][j] = (sum[i][j-1] + memo[i][j])%MOD; 	
		}
		
	}
	
	return memo[n-1][k];
}

int main() {	
	memset(memo, -1, sizeof(memo));
	cin.sync_with_stdio(0);
	cin.tie(0);
	int k;
	
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	cout << solve(k) << endl;

	return 0;	
}
