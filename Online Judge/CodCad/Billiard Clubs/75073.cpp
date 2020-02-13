#include <iostream>
#include <set>

using namespace std;

int main(){
	long int n;
	long int cont = 0;
	
	cin >> n;
	
	set<long int> c1;
		
	for(long int i=0; i < n; i++){
		long int x;
		cin >> x;
		
		set<long int>::iterator it = c1.find(x);	  		
		if(it == c1.end()){
			cont +=2 ;
			c1.insert(x);
		}else{
			c1.erase(it);
		}

	}
	
	cout << cont << endl;
   
	return 0;
}