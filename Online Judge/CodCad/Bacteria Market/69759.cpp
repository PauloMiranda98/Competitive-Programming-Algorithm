#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, posm;
	double b, d;
	double maior;
	
	cin >> n;

	cin >> b >> d;
	
	maior = log10(b)*d;
	posm = 0;
	
	for(int i=1; i<n; i++){
		cin >> b >> d;		
		double x = log10(b)*d;
		if(x  > maior){
			maior = x;
			posm = i;
		}
	}
	
	cout << posm << endl;
	
    return 0;
}

