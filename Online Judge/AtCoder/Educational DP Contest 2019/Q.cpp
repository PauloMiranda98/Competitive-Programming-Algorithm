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

int n, h[200010];
ll a[200010], tree[200010];

ll query(int i){	
	ll s = 0;

	while(i > 0){
		s = max(s, tree[i]);
		i -= (i & -i);
	}
	
	return s;
}

void update(int i, ll value){	
	while(i <= n){ 
		tree[i] = max(tree[i], value);
		i += (i & -i);
	}
}


ll solve(){
	
	for(int i=1; i<=n; i++){
		ll s = query(h[i]) + a[i];
		
		update(h[i], s);
	}	
	
	return query(n);
}

int main() {	
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for(int i=1; i<=n; i++)
		cin >> h[i];	
	for(int i=1; i<=n; i++)
		cin >> a[i];	
	
	
	cout << solve() << endl;

	return 0;	
}
