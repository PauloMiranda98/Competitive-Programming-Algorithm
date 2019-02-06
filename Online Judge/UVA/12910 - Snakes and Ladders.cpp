#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const long double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
#define MOD 1000000007LL

//typedef long double ld;
//#define double ld

int gauss(vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int w, h, s;
	
	while(cin >> w >> h >> s){
		vector<vector<double> > A;
		vector<double> vans;
		
		A.resize(w*h, vector<double>(w*h+1, 0));

		for(int i=0; i<s; i++){
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			
			A[x][x] = 1;
			A[x][y] = -1;				
		}
		
		for(int i=0; i<w*h-1; i++){
			if(abs(A[i][i]-1) > EPS){
				A[i][i] = 1;
				for(int j=1; j<=6; j++){
					if((i+j) < w*h)
						A[i][i+j] += -1.0/6;
					else
						A[i][ (w*h-1) - ((i+j)-w*h+1)] += -1.0/6;
				}		
					
				A[i][w*h] = 1;
			}
		}
		
		A[w*h-1][w*h-1] = 1;
		
		gauss(A, vans);
		cout << setprecision(12) << fixed << vans[0] << endl;
	}
	
	return 0;
}

