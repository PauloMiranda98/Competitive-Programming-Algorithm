#include <bits/stdc++.h>

using namespace std;

int main() {
	
	long int n, m, m1, m2, soma = 0;
	
	cin >> n >> m;
	
	if(3*m < n){
		cout << 0 << endl;
		return 0;
	}
	
	m1 = n - m;
	
	if(m1 > m){
		m2 = m1 - m;
		m1 = m; 
	}else{
		m1 -= 1;
		m2 = 1;
	}
	
	if(m1 < m){
		soma = ( (m1-m2+1 + m-m2)*(m-m1) ) /2;
	}
	
	soma += ( (m-m1+1 + m-m2+1)*(m1-m2+1) ) /2;
	
	cout << soma << endl;
	
	return 0;
	
}
