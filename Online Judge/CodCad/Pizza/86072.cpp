#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

long int max_sum(vector<long int> s, long int n){
	
	long int it = 1;
	
	long int resp = 0, maior = 0;
	
	for(long int i=0; i < (long int) s.size(); i++){
		
		maior = max((long int)0, maior + s[i]);
		
		if(maior == 0){
			it = 1;
		}
		
		resp = max(resp, maior);
		
		if(it == n){
			i = i - n + 1;
			it = 1;
			maior = 0;
		}else{
			it++;			
		}	
		
	}
	
	return resp;
}

int main(){
	long int n;
	cin >> n;
	
	vector<long int> v(2*n);	
	
	for(long int i=0; i < (n); i++){
		cin >> v[i];
		v[n+i] = v[i];
	}
	
	v.pop_back();
	
	cout << max_sum(v, n) << endl;
	
	return 0;
}
