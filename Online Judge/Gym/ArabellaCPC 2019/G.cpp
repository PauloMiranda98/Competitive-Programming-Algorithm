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
int n;

double solve(int turn, int st1, int st2, int x, int y){
	if(turn == 0){
		return x;
	}
	double ans=0;
	int qtd = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if( ((st1>>i)&1) and ((st2>>j)&1) ){
				qtd++;
				if(i > j)
					ans += solve(turn-1, st1^(1<<i), st2^(1<<j), x+i+1, y);
				else if(i < j)
					ans += solve(turn-1, st1^(1<<i), st2^(1<<j), x, y+j+1);
				else
					ans += solve(turn-1, st1^(1<<i), st2^(1<<j), x, y);
			}
		}
	}		
	return ans/qtd;	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
/*BruteForce
	for(n=1; n<=6; n++){
		double p = solve(n, (1<<n)-1, (1<<n)-1, 0, 0);
		cout << n << ": " << p << endl;
	}
*/
	cin >> n;
	ll sum = 0;
	for(int i=2; i<=n; i++){
		sum += (i*2)-1;
	}
	cout << fixed << setprecision(10) << (double)sum/3 << endl;

	return 0;
}
