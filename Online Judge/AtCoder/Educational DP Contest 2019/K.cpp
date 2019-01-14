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

bool memo[100010];
bool calc[100010];
int vet[110];
int n, k;

bool dp(int v){
	if(v == 0)
		return false;
		
	if(calc[v])
		return memo[v];
	
	calc[v] = true;
	
	memo[v] = false;
	
	for(int i=0; i<n; i++)
		if(vet[i] <= v)
			memo[v] |= !dp(v - vet[i]);
		
	return memo[v];
}

int main() {	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> vet[i];
	}
	
	if(dp(k))
		cout << "First" << endl;
	else
		cout << "Second" << endl;

	return 0;	
}
