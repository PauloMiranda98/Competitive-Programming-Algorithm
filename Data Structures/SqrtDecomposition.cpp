#include <bits/stdc++.h>

using namespace std;

struct SqrtDecomposition{
	int n;
	int len;
	vector<int> b;
	vector<int> a;
	
	SqrtDecomposition(){
		
	}
	
	SqrtDecomposition(vector<int> &v){
		build(v);
	}

	void build(vector<int> &v){
		n = v.size();
		a = v;
		
		len = (int) sqrt (n + .0) + 1;
		b.resize(len);

		for(int i=0; i<n; i++)
			b[i / len] += a[i];		
	}
	
	void update(int idx, int nv){
		int d = nv - a[idx];
		a[idx] += d;
		b[idx/len] += d;
	}
	
	int query(int l, int r){
		int sum = 0;

		int c_l = l / len,   c_r = r / len;
		if (c_l == c_r){
			for (int i=l; i<=r; i++)
				sum += a[i];
		}else{
			for (int i=l, end=(c_l+1)*len-1; i<=end; i++)
				sum += a[i];
			for (int i=c_l+1; i<=c_r-1; i++)
				sum += b[i];
			for (int i=c_r*len; i<=r; i++)
				sum += a[i];
		}
		
		return sum;
	}	
	
};

int main(){	
	vector<int> v;
	int n;
	
	cin >> n;
	v.resize(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
		
	SqrtDecomposition st(v);
	
	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		
		cout << st.query(l, r) << endl;
	}
	
	return 0;
}
