#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 200010

int n, anc[MAXN], w[MAXN], size[MAXN];


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
        size[y] += size[x];
    }else if(w[x] > w[y]){
        anc[y] = x;
        size[x] += size[y];
    }else{        
        anc[x] = y;
        size[y] += size[x];
        
        w[y]++;
    }
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n;

	for(int i=1; i<=n; i++){
		anc[i] = i;
		w[i] = 1;
		size[i] = 1;
	}
	
	int q;
	cin >> q;
	
	for(int i=0; i<q; i++){
		int a, b;
		cin >> a >> b;
		join(a, b);
		
		cout << size[find(a)] << endl;
	}
		
	return 0;
	
}
