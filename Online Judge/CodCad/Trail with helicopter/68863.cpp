#include <iostream>

using namespace std;

int main() {
	
	int h, p, f, d;
	
	cin >> h >> p >> f >> d;
	
	while( (f != h) && (f != p) ){
		f = (f+d)%16;
		if(f == -1)
			f = 15;
	}
	
	if(f == h)
		cout << "S" << endl;
	else
		cout << "N" << endl;
			
	return 0;
		
}