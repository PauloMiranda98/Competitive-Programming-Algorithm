#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MOD = 1000000007;
const int N = 110;

inline int modMul(int a, int b) {
	return (int) ((long long) a * b % MOD);
}

inline int modSum(int a, int b) {
	int x = a+b;

	if(x >= MOD)
		return x-MOD;
	else
		return x;
}

inline int modSub(int a, int b) {
	int x = a-b;

	if(x < 0) 
		return x+MOD;
	else
		return x;
}

struct Mat{
	int m[N][N];

	Mat(bool identity = false){
		memset(m, 0, sizeof(m));

		if(identity){
			for(int i=0; i<N; i++)
				m[i][i] = 1;
		}
	}

	Mat sum(Mat a, Mat b){
		Mat ans;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				ans.m[i][j] = modSum(a.m[i][j], b.m[i][j]);
		return ans;		
	}

	Mat sub(Mat a, Mat b){
		Mat ans;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				ans.m[i][j] = modSub(a.m[i][j], b.m[i][j]);
		return ans;		
	}

	Mat mul(Mat a, Mat b){
		Mat ans;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				for(int k=0; k<N; k++)
					ans.m[i][j] = modSum(ans.m[i][j], modMul(a.m[i][k], b.m[k][j]));
		return ans;		
	}
	
	Mat fastExp(Mat b, ll exp){
		Mat ans(true);
		
		while(exp){
			if(exp & 1LL)
				ans = ans.mul(ans, b);
			b = b.mul(b, b);
			exp >>= 1;
		}

		return ans;		
	}
};

int main() {
	int n;
	ll k;
	Mat A;
	cin >> n >> k;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> A.m[i][j];
		}
	}
	
	A = A.fastExp(A, k);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j > 0)
				cout << " ";
			cout << A.m[i][j];
		}
		cout << endl;
	}

	
	return 0;	
}
