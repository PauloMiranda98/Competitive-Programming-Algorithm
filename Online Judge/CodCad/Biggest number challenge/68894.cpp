#include <iostream>
#include <list>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int c, maior=0;
	
	do{
		cin >> c;
		if(c > maior) maior = c;
    }while(c);
	
			   	
	cout << maior << endl;
							   					
	return 0;
}