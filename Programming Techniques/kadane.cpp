#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//Kadane: O(N)

ll kadane(vector<int> v){
	
	ll resp = 0LL, maior = 0;
	
	for(int i=0; i < int(v.size()); i++){
		maior = max(0LL, maior + ll(v[i]));		
		resp = max(resp, maior);
	}
	
	return resp;
}

//Circular Kadane: O(N)

ll circular_kadane(vector<int> v){
	ll resp1 = kadane(v);
	
	ll sum = 0LL;
	for(int i=0; i < int(v.size()); i++){
		sum += v[i];
		v[i] *= -1;
	}
	
	ll resp2 = sum + kadane(v);

	return max(resp1, resp2);
	
}

vector<int> v;
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	
	cin >> n;
	v.resize(n);
	
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	cout << kadane(v) << endl;
	cout << circular_kadane(v) << endl;
					
	return 0;
	
}
