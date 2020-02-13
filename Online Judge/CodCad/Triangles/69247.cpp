#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int abs(int a){
	
	return (a>=0)? a : -1*a;
}

int main(){

	int a, b, c;
	
	cin >> a >> b >> c;
	
	if( (abs(b-c) < a) && (a < (b+c)) && (abs(a-c) < b) && (b < (a+c)) && (abs(b-a) < c) && (c < (b+a)) ){
		if( (a*a == b*b + c*c) || (b*b == a*a + c*c) || (c*c == b*b + a*a) ){
			cout << "r" << endl;
		}else if( (c*c < (b*b + a*a) ) && (a*a < (c*c + b*b) ) && (b*b < (c*c + a*a) ) ){
			cout << "a" << endl;			
		}else{
			cout << "o" << endl;
		}
		
	}else{
		cout << "n" << endl;
	}
	
	return 0;
}
