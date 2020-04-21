#include <bits/stdc++.h>

#define X first
#define Y second
#define EB emplace_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define all(x) x.begin(),x.end()
#define endl '\n'
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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
		bit.resize(nBit + 1, 0);
	}
	//1-indexed
	t_bit get(int i){
		t_bit s = 0;
		for (; i > 0; i -= (i & -i))
			s += bit[i];
		return s;
	}
	//1-indexed [l, r]
	t_bit get(int l, int r){
		if(l > r)
			return 0;
		return get(r) - get(l - 1);
	}
	//1-indexed
	void add(int i, t_bit value){
		assert(i > 0);
		for (; i <= nBit; i += (i & -i))
			bit[i] += value;
	}
	t_bit lower_bound(t_bit value){
		t_bit sum = 0;
		int pos = 0;
		for (int i = nLog; i >= 0; i--){
			if ((pos + (1 << i) <= nBit) and (sum + bit[pos + (1 << i)] < value)){
				sum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1;
	}
};

const int MAXN = 100010;
pii v[MAXN];
int n;
ll k;

vector<int> cc;
int getP(int x){
	return lower_bound(all(cc), x) - cc.begin();
}

ll solve(int dist){	
	ll ans = 0;
	Bit bit(cc.size());
	int x, y;
	for(int i=0, j=0; i<n; i++){
		tie(x, y) = v[i]; 
		while(j<n and cc[v[j].X]-cc[x] <= dist){
			bit.add(v[j].Y, +1);
			j++;
		}
		int a = getP(cc[y]-dist);
		int b = upper_bound(all(cc), cc[y]+dist) - cc.begin() - 1;
		ans += bit.get(y+1, b);
		ans += bit.get(max(1, a), y-1);				
		ans += bit.get(y, y)-1;				
		bit.add(y, -1);
	}	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	cc.push_back(-INF);
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
		v[i] = pii(x+y, x-y);
		cc.push_back(v[i].X);
		cc.push_back(v[i].Y);
	}
	sort(all(cc));
	cc.erase(unique(all(cc)), cc.end());

	for(int i=0; i<n; i++){	
		v[i].X = getP(v[i].X);
		v[i].Y = getP(v[i].Y);
	}	
	sort(v, v+n);
	int lo=0, hi=INF, ans=0;
	while(lo <= hi){
		ll mid = (lo+hi)/2LL;
		if(solve(mid) >= k){
			ans = mid;
			hi = mid-1LL;
		}else{
			lo = mid+1LL;
		}
	}
	cout << ans << endl;
	return 0;
}
