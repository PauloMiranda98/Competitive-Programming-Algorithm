#include <iostream>
#include <math.h>

using namespace std;

bool eh_primo(int n){
	if(n<5 || n%2==0 || n% 3==0)
		return (n==2 || n==3);
	
	int maxp = sqrt(n) + 2;
	
	for(int i=5; i<=maxp; i+=6){
		if(n%i==0 || n%(i+2)==0)
			return false;
	}
	
	return true;
}

int main(){
	int x;

	cin>>x;

	if(eh_primo(x)){
		cout<<"S"<<"\n";
	}else{
		cout<<"N"<<"\n";
	}
}