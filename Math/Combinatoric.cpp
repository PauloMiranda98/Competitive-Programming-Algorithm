#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int N = 5010;

int n_max;
ll comb[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n_max;
	
	comb[0][0] = 1LL;
	for(int i=1; i<=n_max; i++){
		comb[i][i] = 1LL; 
		comb[i][0] = 1LL; 		
		for(int j=1; j<=i; j++)
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];		
	}
	int q;
	cin >> q;
	
	while(q--){
		int n, k;
		cin >> n >> k;
		cout << comb[n][k] << endl;
	}
    
	return 0;
}

