#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int me = 30;

struct GaussXOR {
	int table[me];

	GaussXOR() {
		for(int i = 0; i < me; i++) {
			table[i] = 0;
		}
	}

	int size() {
		int ans = 0;
		for(int i = 0; i < me; i++) {
			if(table[i]) ans++;
		}
		return ans;
	}

	bool is_comb(int x) {
		for(int i = me-1; i >= 0; i--) {
			x = std::min(x, x ^ table[i]);
		}
		return x == 0;
	}

	void add(int x) {
		for(int i = me-1; i >= 0; i--) {
			if(table[i] == 0) {
				table[i] = x;
				x = 0;
			} else {
				x = std::min(x, x ^ table[i]);
			}
		}
	}

	int max(){
		sort(table, table + me);
		for(int i = me-1; i >= 0; i--) {
			for(int j=me-1; j >= 0; j--){
				if(i != j)
					table[j] = std::min(table[j], table[j] ^ table[i]);
			}
		}
		
		int ans = 0;
		for(int i = 0; i < me; i++) {
			ans ^= table[i];
		}
		
		return ans;		
	}
	
};

int n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	GaussXOR g;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		
		g.add(x);
	}

	cout << "Base dimension is " << g.size() << endl;
			
	return 0;
}

