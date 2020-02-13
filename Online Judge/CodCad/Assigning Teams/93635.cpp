#include <iostream>

using namespace std;

int main(){
	int a, b, c, d, res;
	
	cin >> a >> b >> c >> d;
	
	res = abs((a + b) - (c + d));
	
	res = min(res, abs((a + c) - (b + d)));
	res = min(res, abs((a + d) - (b + c)));
	
	cout << res << endl;
	
	return 0;
}
