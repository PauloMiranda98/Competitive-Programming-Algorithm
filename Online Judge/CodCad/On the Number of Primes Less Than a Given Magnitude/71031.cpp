#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	int n;
	
	cin >> n;
	
	if(n >= 2){
		cout << "2";
	}
	
	for(int x = 3; x <= n; x++){	
		bool res = true;
		int r = sqrt(x);
		
		for(int i = 2; i <= r; i++){
			if(x%i == 0){
				res = false;
				break;
			}	
		}
		
		if(res)
			cout << " " << x;
    }	   		
	cout << endl;

    return 0;
}


