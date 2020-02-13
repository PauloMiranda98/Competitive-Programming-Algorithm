#include <bits/stdc++.h>
#define MAX 99999999

using namespace std;

long long int fatorial(long int n, long int k){
	long long int x = 1;
	
	if(n <= 0){
		return x;
	}
	
	x = n;
	
	return x * fatorial(n-k, k);
	
}

int main() {

	long int x,n, k;
	string num;
	
	cin >> x;
	
	while(x--){
		stringstream ss;
		cin >> num;
		
		int p=0;
		
		for(p=0; (num[p] != '!') && (p < (int) num.size()) ; p++);

		k = num.size() - p;
		ss << num.substr(0, p);
		ss >> n;		
		
		
		cout << fatorial(n, k) << endl;
	}
	return 0;
	
}
