#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int main(){
	
	long int n;
	
	unsigned long int res = 0, x;
	
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	cin >> n;
		
	for(long int i = 1; i <= n; i++){
		cin >> x;
		
		res |=x;
			
	}
	
	cout << res << endl;
	
	return 0;
}