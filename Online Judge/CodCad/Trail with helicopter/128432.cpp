#include <iostream>

using namespace std;

int main(){
	
	int h, p, f, d;
	
	cin >> h >> p >> f >> d;

	if(d == -1){
		if(h > f)
			h -= 16;
		if(p > f)
			p -= 16;
		
		if( (f - p) < (f - h))
			cout << "N" << endl;
		else
			cout << "S" << endl;
	}else{
		if(h < f)
			h += 16;
		if(p < f)
			p += 16;
		
		if( (p - f) < (h - f))
			cout << "N" << endl;
		else
			cout << "S" << endl;
		
	}
		
	return 0;
}
