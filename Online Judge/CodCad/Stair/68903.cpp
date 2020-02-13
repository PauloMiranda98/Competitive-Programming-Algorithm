#include <iostream>
#include <list>
#include <stdio.h>

using namespace std;

int main(){

	int n, i, x;
	long int quant =0, tempo=0;
	
	cin >> n;
	
	cin >> x;
	
	tempo = x + 10;
	quant = 10;
	
	for(i=1; i<n; i++){
		cin >> x;
		if(x<tempo)
			quant += 10 + x - tempo;
		else
			quant += 10;
		
	   	tempo = x + 10;
	}
		
	cout << quant << endl;
	    		    			 				   				
	return 0;
	
}   
   
