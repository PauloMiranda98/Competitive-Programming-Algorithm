#include <iostream>

using namespace std;

int main(){
	int a, b, c, d;
	
	cin >> a >> b >> c >> d;
	
	if(b != c){
		cout << 'N' << endl;
		return 0;
	}
	
	if( (b+c)!= d ){
		cout << 'N' << endl;
		return 0;		
	}
	
	if( (b+c+d) != a ){
		cout << 'N' << endl;
		return 0;				
	}
		
	cout << 'S' << endl;
		
	return 0;
}
