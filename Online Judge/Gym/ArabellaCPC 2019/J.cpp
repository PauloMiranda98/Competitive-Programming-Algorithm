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

int dp[100010][2];
string s;
int n;
int solve(int i, bool nine){
	if(i == n)
		return 0;
	if(dp[i][nine] != -1)
		return dp[i][nine];
	if(nine)
		return dp[i][nine] = min(solve(i+1, true) + min(2+s[i]-'0', '9'-s[i]), solve(i+1, false) + min('9'-s[i], s[i]-'0'));		
	else
		return dp[i][nine] = min(solve(i+1, true) + 2 + min(s[i]-'0', '9'-s[i]), solve(i+1, false) + min(2+'9'-s[i], s[i]-'0'));			
}

int main() {
	memset(dp, -1, sizeof(dp));
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	n = s.size();
	cout << min(solve(0, false), 2+solve(0, true)) << endl;
	return 0;
}
