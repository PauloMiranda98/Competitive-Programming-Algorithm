#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 200010

struct UnionFind{
	#define NUF MAXN 
	int anc[NUF], w[NUF], sz[NUF];

	UnionFind(){
		for(int i=1; i<NUF; i++){
			anc[i] = i;
			w[i] = 1;
			sz[i] = 1;
		}		
	}

	//find: O(1)
	int find(int x){    
		if(anc[x] == x)
			return x;		
		return anc[x] = find(anc[x]);
	}

	//isSame: O(1) 
	bool isSame(int x, int y){
		return find(x) == find(y);
	}

	//join: O(1) 
	void join(int x, int y){    
		x = find(x);
		y = find(y);
		
		if(x == y)
			return;
		
		if(w[x] < w[y]){
			anc[x] = y;
			sz[y] += sz[x];
		}else if(w[x] > w[y]){
			anc[y] = x;
			sz[x] += sz[y];
		}else{        
			anc[x] = y;
			sz[y] += sz[x];
			
			w[y]++;
		}
	}
	
	int size(int x){
		return sz[find(x)];
	}
};

UnionFind uf;
int n;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n;
	
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		int a, b;
		cin >> a >> b;
		uf.join(a, b);
		
		cout << uf.size(a) << endl;
	}
		
	return 0;
	
}
