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

string a, b;
int dp[3010][3010];

int solveR(int i, int j){
	if( (i < 0) or (j < 0) )
		return 0;
	
	if(dp[i][j] != -1)
		return dp[i][j];
		
	if(a[i] == b[j])
		return dp[i][j] = 1 + solveR(i-1, j-1);

	return dp[i][j] = max(solveR(i, j-1), solveR(i-1, j));
}

string recover(int x){
	string r;
	
	int i = sz(a)-1;
	int j = sz(b)-1;
	
	while( (i>=0) and (j>=0) ){
		if(a[i]==b[j]){
			r += a[i];
			i--;
			j--;			
		}else if( (j>0) and (dp[i][j] == dp[i][j-1])){
			j--;
		}else{
			i--;
		}
	}
	
	return r;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;
	string res = recover(solveR(sz(a)-1, sz(b)-1) );
	reverse(all(res));
	
	cout << res << endl;
		
	return 0;	
}
