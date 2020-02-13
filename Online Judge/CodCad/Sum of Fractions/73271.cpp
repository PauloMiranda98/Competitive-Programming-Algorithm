#include <iostream>

using namespace std;

unsigned long long int mdc(unsigned long long int a, unsigned long long int b){
	if(b == 0)
		return a;
		
	return mdc(b, a%b);
}

int main(){
	unsigned long long int a, b, c, d;
	unsigned long long int r, s, m;
	
	cin >> a >> b >> c >> d;

	r = b*c + d*a;
	s = b*d;
	
	while((m = mdc(r, s)) != 1){
		r /= m;
		s /= m;
	}
	
	cout << r << " " << s << endl;
	
	return 0;
}
