#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

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
	int n;
	cin >> n;
	vi v(n);
	REP(i,0,n){
		cin >> v[i];
		if(v[i] > v[0]){
			cout << "N" << endl;
			return 0;
		}
	}
	cout << "S" << endl;
	return 0;
}
