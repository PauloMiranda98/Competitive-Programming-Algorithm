#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
int n;

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

ll determinantMOD(vector < vector<ll> > a, ll M) {
	ll det = 1;
	for(int i=0; i<n; ++i) {
		int k = i;
		for(int j=i+1; j<n; ++j)
			if (abs(a[j][i]) > abs(a[k][i]))
				k = j;
		if(a[k][i] == 0)
			return 0;
		
		swap(a[i], a[k]);
		
		if(i != k)
			det = (det*(M-1))%M;
		det = (det*a[i][i])%M;
		
		for(int j=i+1; j<n; ++j)
			a[i][j] = modDiv(a[i][j], a[i][i], M);
		for(int j=0; j<n; ++j)
			if( (j != i) && ( a[j][i] > 0) )
				for(int k=i+1; k<n; ++k)
					a[j][k] = ((a[j][k] - (a[i][k] * a[j][i])%M)+M)%M;
	}

	return det;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll mod;
	cin >> n >> mod;
	
	vector<vector<ll> > A;		
	A.resize(n, vector<ll>(n, 0));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> A[i][j];
			A[i][j] = A[i][j]%mod;
		}
	}
	
	cout << "Determinant is " << determinantMOD(A, mod) << endl;
	
	return 0;
}

