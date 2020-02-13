#include <iostream>

using namespace std;

int main(){
	
	int h, p, f, d;
	
	cin >> h >> p >> f >> d;

	while( (f != p) and (f != h) ){
		f = f + d;

		if(f == -1){
			f = 15;
		}else if(f == 16){
			f = 0;		
		}

	}
	
	if(f == h){
		cout << "S" << endl;
	}else{
		cout << "N" << endl;
	}
	
	return 0;
}
