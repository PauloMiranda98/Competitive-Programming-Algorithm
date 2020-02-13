#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

long int max_sum(vector<long int> s){
	
	long int resp=0, maior=0;
	
	for(long int i=0;i< (long int)s.size();i++){
		
		maior = max((long int)0,maior+s[i]);
		
		resp = max(resp,maior);
	}
	
	return resp;
}

int main(){
	long int n;
	cin >> n;
	
	vector<long int> v(n);
	
	
	for(long int i=0; i < n; i++){
		cin >> v[i];
	}
	
	cout << max_sum(v) << endl;
	
	return 0;
}