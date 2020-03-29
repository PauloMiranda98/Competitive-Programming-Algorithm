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
const int MAXN = 300010;

int v[MAXN];
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	
	for(int i=0; i<n; i++)
		cin >> v[i];
	sort(v, v+n);
	int i=1, j=0;
	ll ans = 0;
	ll pre=v[0], suf=0;
	while(i+j<n){
		if(i<=j){
			ans += (v[i]*1LL*i)-pre;
			ans += suf - (v[i]*1LL*j); 
			pre += v[i];
			i++;
		}else{
			ans += (v[n-j-1]*1LL*i)-pre;
			ans += suf - (v[n-j-1]*1LL*j); 
			suf += v[n-j-1];
			j++;			
		}
		cout << ans << " ";
	}
	cout << endl;
	return 0;
}
