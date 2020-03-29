#include <bits/stdc++.h>

#define F first
#define S second
#define EB emplace_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define all(x) x.begin(),x.end()
#define endl '\n'
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const int MAXN = 1000010;

int v[MAXN];
int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;	
	for(int i=0; i<n; i++)
		cin >> v[i];
	ll g = 0;
	for(int i=0; i<m; i++){
		ll x;
		cin >> x;
		g = __gcd(g, x);
	}
	for(int i=1; i<n; i++){
		if(abs(v[i]-v[i-1])%g!=0){
			cout << "No" << endl;
			return 0;
		}			
	}
	cout << "Yes" << endl;
	
	return 0;
}
