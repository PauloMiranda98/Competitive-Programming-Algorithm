#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	long long int f[1001];
	long long int a[1001];
	
	long int n, m, k, x, aux;	
	cin >> n >> k >> m;

	for(int i=1; i <= n; i++){
		cin >> a[i];
	}

	for(int i=1; i <= n; i++){
		cin >> f[i];
	}
	
	for(int i=n+1; i <= k; i++){
		f[i] = 0;
		
		for(int j=1; j <= n; j++){
			f[i] += (a[j]%m)*f[i-j];
		}
		
		f[i] = f[i]%m;
	}
	
	cout << (f[k]) << endl;
		
	return 0;
}