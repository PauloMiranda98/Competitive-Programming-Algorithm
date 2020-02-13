#include <iostream>

using namespace std;

int main() {
	
	int h, p, f, d;
	
	cin >> h >> p >> f >> d;

	if( d == -1){
		if(h > f){
			h = h - 16;
		}
		
		if(p > f){
			p = p - 16;
		}
		
		if( (f - h) < (f - p) ){
			cout << "S" << endl;
		}else{
			cout << "N" << endl;
		}
	}else{
		if(h < f){
			h = h + 16;
		}
		
		if(p < f){
			p = p + 16;
		}
		
		if( (h - f) < (p - f) ){
			cout << "S" << endl;
		}else{
			cout << "N" << endl;
		}		
	}
		
			
	return 0;
		
}