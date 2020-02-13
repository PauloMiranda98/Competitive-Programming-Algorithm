#include <bits/stdc++.h>

using namespace std;

int main(){

    long int n;
    cin >> n;
    n /= 2;
    
    long int a, b, c, d;
    
    cin >> a >> b;
    cin >> c >> d;

	if((min(a, c) <= n && n < max(a,c)) || (min(b, d) <= n && n < max(b,d)))
		cout << "S" << endl;
	else
		cout << "N" << endl;

    return 0;
}

