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

double memo[3010][3010];
bool calc[3010][3010];
double v[3010];
int n;

double dp(int h, int t){
	if((h+t) == n){
		if(h>t)
			return 1.0;
		else
			return 0.0;
	}
	
	if(calc[h][t])
		return memo[h][t];

	calc[h][t] = true;
	
	return memo[h][t] = v[h+t]*dp(h+1, t) + (1.0-v[h+t])*dp(h, t+1);
}

int main() {	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	cout << setprecision(12) << fixed << dp(0, 0) << endl;

	return 0;	
}
