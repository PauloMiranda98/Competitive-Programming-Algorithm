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

string k;
ll memo[100010][110][2];
int n, d;

ll dp(int i, int r, bool limite){
	if(i == n){
		if(r == 0)
			return 1LL;
		else
			return 0LL;
	}
	
	if(memo[i][r][limite] != -1LL)
		return memo[i][r][limite];
	
	ll ans = 0LL;
		
	if(limite){
		for(int j=0; j < int(k[i]-'0'); j++)
			ans = (ans + dp(i+1, (r+j)%d, false) )%MOD;
			
		ans = (ans + dp(i+1, (r + int(k[i]-'0'))%d, true) )%MOD;
	}else{
		for(int j=0; j<10; j++)
			ans = (ans + dp(i+1, (r+j)%d, false) )%MOD;
	}
	
	return memo[i][r][limite] = ans;
}

int main() {	
	memset(memo, -1, sizeof(memo));
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;
	cin >> d;
	
	n = sz(k);
		
	cout << (MOD + dp(0, 0, true)-1LL)%MOD << endl;

	return 0;	
}
