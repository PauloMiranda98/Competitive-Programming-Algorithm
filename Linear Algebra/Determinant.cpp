#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const double EPS = 1E-9;
int n;

double determinant(vector < vector<double> > a) {
	double det = 1;
	for (int i=0; i<n; ++i) {
		int k = i;
		for (int j=i+1; j<n; ++j)
			if (abs (a[j][i]) > abs (a[k][i]))
				k = j;
		if (abs (a[k][i]) < EPS) {
			det = 0;
			break;
		}
		swap (a[i], a[k]);
		if (i != k)
			det = -det;
		det *= a[i][i];
		for (int j=i+1; j<n; ++j)
			a[i][j] /= a[i][i];
		for (int j=0; j<n; ++j)
			if (j != i && abs (a[j][i]) > EPS)
				for (int k=i+1; k<n; ++k)
					a[j][k] -= a[i][k] * a[j][i];
	}

	return det;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	vector<vector<double> > A;		
	A.resize(n, vector<double>(n, 0));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> A[i][j];
		}
	}
	
	cout << "Determinant is " << setprecision(2) << fixed << determinant(A) << endl;
	
	return 0;
}

