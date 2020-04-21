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
int v[4];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);		
	for(int i=0; i<4; i++){
		cin >> v[i];
	}
	sort(v, v+4);
	do{
		if(v[0]+v[1] == v[2] + v[3]){
			cout << "YES" << endl;
			return 0;		
		}		
	}while(next_permutation(v, v+4));
	
	cout << "NO" << endl;

	return 0;
}
