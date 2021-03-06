#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(void) {
	long int a, b, c, d, n = ~(1<<31), lim;
	
	cin >> a >> b >> c >> d;
	
	lim = c/a;
				
	for(int x = 1; x <= (sqrtl(lim)+2); x++){	

		if(lim % x == 0){				
			long int aux = x*a;
						
			if( (aux%b != 0) && (d%aux != 0) && (c%aux==0) ){
				n = min(aux, n);
			}
			
			aux = (lim/x)*a;
						
			if( (aux%b != 0) && (d%aux != 0) && (c%aux==0) ){
				n = min(aux, n);
			}
		}
    }	   		
    if(n == ~(1<<31))
		cout << "-1" << endl;
	else	
		cout << n << endl;

    return 0;
}