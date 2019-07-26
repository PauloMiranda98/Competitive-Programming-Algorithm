#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 2000;
const int INF = 0x3f3f3f3f;

bool test(int v[], int init, int size, int lim){
	for(int i=init; i<lim; i++)
		if(v[init + ((i-init)%size)] != v[i])
			return false;
	return true;
}

void identifyPattern(int v[], int lim){
	for(int init=0; init<lim; init++){
		for(int size=1; size<500; size++){
			if(test(v, init, size, lim)){
				cout << init << " " << size << endl;				
				break;
			}
		}
	}
}
int v[MAXN];

int main() {	
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	identify_stand(v, MAXN);
	
	return 0;	
}

