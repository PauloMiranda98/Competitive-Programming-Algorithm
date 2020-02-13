#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;
	
long int busca(int n){
	
	if(n==1) return 1;
	
	else return 2 * busca(n-1) + 1;
}
	
int main(){

	
	int n, x=1;
	
	cin >> n;
	
	while(n){
		
		cout << "Teste "<< x<< endl;
		cout << busca (n) << endl;
		cout << endl;

		cin >> n;
		x++;
	}
		
			   					
	return 0;
}   
