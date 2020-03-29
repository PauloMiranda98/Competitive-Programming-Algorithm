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
int dp[1010][1010];
int song[1010];
int eliminated[1010];

int solve(int i, int pos){
	if(i == n-1)
		return true;	
	if(dp[i][pos] != -1)
		return dp[i][pos];
	int len = n-i;
	int pos1 = (pos+song[i])%len;
	int pos2 = (pos-song[i])%len;
	if(pos2 < 0)
		pos2+=len;
	bool ans = false;
	if(eliminated[i] != pos1)
		ans |= solve(i+1, pos1-(eliminated[i]<pos1));
	if(eliminated[i] != pos2)
		ans |= solve(i+1, pos2-(eliminated[i]<pos2));
	return dp[i][pos] = ans;
}

class Bit{
private:
	typedef long long t_bit;
	int nBit;
	int nLog;
	vector<t_bit> bit;	
public:
	Bit(int n){ 
		nBit = n;
		nLog = 20;
		bit.resize(nBit+1, 0);
	}	
	t_bit get(int i){	
		t_bit s = 0;
		for(; i > 0; i -= (i & -i))
			s += bit[i];		
		return s;
	}
	t_bit get(int l, int r){
		return get(r) - get(l-1);
	}	
	void add(int i, t_bit value){				
		for(; i <= nBit; i += (i & -i))
			bit[i] += value;
	}
	t_bit position(t_bit value){
		t_bit sum = 0;
		int pos = 0;
		for(int i=nLog; i>=0; i--){
			if( (pos + (1 << i) <= nBit) and (sum + bit[pos + (1 << i)] < value) ){
				sum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1;
	}
};

int main() {
	memset(dp, -1, sizeof(dp));
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int init;
	cin >> n >> init;
	
	for(int i=0; i<n-1; i++)
		cin >> song[i];

	Bit bt(n);
	for(int i=1; i<=n; i++)
		bt.add(i, 1);

	for(int i=0; i<n-1; i++){
		int x;
		cin >> x;
		eliminated[i] = bt.get(x)-1;
		bt.add(x, -1);
	}
	cout << (solve(0, init-1)?"Yes":"No") << endl;	
	return 0;
}
