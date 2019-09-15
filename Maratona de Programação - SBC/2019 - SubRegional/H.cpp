#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < int(b);i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define MOD 1000000007
#define endl '\n'
#define mdc(a,b) (__gcd((a),(b)))
#define mmc(a,b) (((a)/mdc(a,b)) * b)

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n, v;
	cin >> n >> v;
	
	
	for(ll i=10; i<100; i+=10){
		if(i > 10)
			cout << " ";
		cout << ((n*v)*i + 99)/100;
	}
	cout << endl;
	return 0;
}
