#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	long long int x;
	bool res = true;
	
	cin >> x;
	
	int r = sqrtl(x);
		
	for(int i = 2; i <= r; i++){
		if(x%i == 0){
			res = false;
			break;
		}	
	}
	
	if(!res)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
    return 0;
}


