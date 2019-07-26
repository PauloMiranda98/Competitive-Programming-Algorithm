#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1010;

map<int, int> mapa;

int f(int x){		
	return mapa[x];
}

pii floydCycleFinding(int x0){
	int tortoise = f(x0), hare = f(f(x0));
	while(tortoise != hare){
		tortoise = f(tortoise);
		hare = f(f(hare));
	}
	int mu = 0;
	hare = x0;
	while(tortoise != hare){
		tortoise = f(tortoise);
		hare = f(hare);
		mu++;
	}	
	int lambda = 1;
	hare = f(tortoise);
	while(tortoise != hare){
		hare = f(hare);
		lambda++;
	}
	return pii(mu, lambda);
}

int main() {		
	pii stand = floydCycleFinding(0);
	
	cout << stand.first << " " << stand.second << endl;
		
	return 0;
	
}

