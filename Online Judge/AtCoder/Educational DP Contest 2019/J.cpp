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

double memo[310][310][310];
bool calc[310][310][310];
char mat[1010][1010];
int n, m;

double dp(int i, int j, int k){
	if( (i<0) or (j<0) or (k<0) )
		return 0;
		
	if( (i == 0) and (j==0) and (k==0))
		return 0;
	if(calc[i][j][k])
		return memo[i][j][k];
	
	calc[i][j][k] = true;
	
	return memo[i][j][k] = (i*(dp(i-1, j, k) + 1) + j*(dp(i+1, j-1, k) + 1) + k*(dp(i, j+1, k-1) + 1) + n - i - j - k)/double(i+j+k);
}

int main() {
	memset(mat, '#', sizeof(mat));
	memset(memo, -1, sizeof(memo));
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int a=0, b=0, c=0;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		if(x == 1)
			a++;
		if(x == 2)
			b++;
		if(x == 3)
			c++;		
	}
	
	cout << setprecision(12) << fixed << dp(a, b, c) << endl;

	return 0;	
}
