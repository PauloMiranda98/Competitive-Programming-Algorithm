#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
int n, m;

template <typename T>
T extGcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1; y = 0; return a;
    }
    else {
        T g = extGcd(b, a % b, y, x);
        y -= a / b * x; return g;
    }
}
 
template <typename T>
T modInv(T a, T m) {
    T x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}
 
template <typename T>
T modDiv(T a, T b, T m) {
    return ((a % m) * modInv(b, m)) % m;
}

template<typename T>
T modMul(T a, T b, T m) {
	T x = 0, y = a % m;
	while (b > 0) {
		if (b % 2 == 1) x = (x + y) % m;
		y = (y * 2) % m; b /= 2;
	}
	return x % m;
}

int compute_rank(vector<vector<ll>> A, ll M) {
    int n = A.size();
    int m = A[0].size();

    int rank = max(n, m);
    vector<bool> row_selected(n, false);
    for (int i = 0; i < m; ++i) {
        int j;
        for (j = 0; j < n; ++j) {
            if (!row_selected[j] && (A[j][i] > 0))
                break;
        }

        if (j == n) {
            --rank;
        } else {
            row_selected[j] = true;
            for (int p = i + 1; p < m; ++p)
                A[j][p] = modDiv(A[j][p], A[j][i], M);
            for (int k = 0; k < n; ++k) {
                if (k != j && (A[k][i] > 0)) {
                    for (int p = i + 1; p < m; ++p)
                        A[k][p] = ((A[k][p] - (A[j][p] * A[k][i])%M)%M + M)%M;
                }
            }
        }
    }
    
    return rank;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll mod;
	cin >> n >> m >> mod;
	
	vector<vector<ll> > A;		
	A.resize(n, vector<ll>(m, 0));
		
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> A[i][j];
			A[i][j] = (A[i][j])%mod;
		}
	}
	
	cout << "Rank of the matriz is " << compute_rank(A, mod) << endl;
	
	return 0;
}

