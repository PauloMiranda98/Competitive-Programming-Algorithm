#include <iostream>
#include <list>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int c, res=0,i;
	char pista[1000001];
	
	cin >> c;
	cin >> pista;
	
	for(i=0;pista[i]; i++){
		if(pista[i]=='P' || pista[i]=='C')
			res +=2;
		else if(pista[i]=='A')
			res++;
	}
		   	
	cout << res << endl;
							   					
	return 0;
}