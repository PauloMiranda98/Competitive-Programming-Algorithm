#include <iostream>

using namespace std;

int main(){
	int n, aux, cont = 0;
		
	cin >> n;

	aux = n/100;	
	cont += aux;
	n -= aux*100;

	aux = n/50;	
	cont += aux;
	n -= aux*50;

	aux = n/25;	
	cont += aux;
	n -= aux*25;

	aux = n/10;	
	cont += aux;
	n -= aux*10;
	
	aux = n/5;	
	cont += aux;
	n -= aux*5;

	cont += n;
	
	cout << cont << endl;
	
    return 0;
}
