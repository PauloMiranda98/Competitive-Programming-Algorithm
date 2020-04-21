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

vector<int> v1, v2;
int n, t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> t;

	int z = 0;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		if(x==0)
			z++;
		else if(x < 0)
			v1.push_back(-x);
		else
			v2.push_back(x);
	}
	reverse(all(v1));
	int ans = z;
	for(int i=0; i<(int)v1.size() and v1[i]<=t; i++){
		int aux = z + i+1;
		int p = upper_bound(all(v2), t-2*v1[i]) - v2.begin();
		ans = max(ans, aux + p);
	}
	for(int i=0; i<(int)v2.size() and v2[i]<=t; i++){
		int aux = z + i+1;
		int p = upper_bound(all(v1), t-2*v2[i]) - v1.begin();
		ans = max(ans, aux + p);
	}

	cout << ans << endl;
	return 0;
}
