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

int n;

struct M{
	ll m[52][52];
	
	M mult(M x){
		M aux;
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				aux.m[i][j] = 0LL;				
				for(int k=0; k<n; k++)
					aux.m[i][j] = (aux.m[i][j] + ((m[i][k] * x.m[k][j])%MOD) )%MOD;				
			}
		}
		
		return aux;
	}	
};

M base;

M solve(M x, ll k){
	if(k == 1LL)
		return x;
		
	if((k%2LL) == 0LL){
		M r = solve(x, k/2LL);
		return r.mult(r);
	}else{
		M r = solve(x, k/2LL);
		r = r.mult(r);
		return r.mult(x);
	}
}

int main() {	
	cin.sync_with_stdio(0);
	cin.tie(0);
	ll k;
	
	cin >> n >> k;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> base.m[j][i];
	
	ll ans = 0LL;
	M mAns = solve(base, k);
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			ans = (ans + mAns.m[i][j])%MOD;
		
	cout << ans << endl;

	return 0;	
}
