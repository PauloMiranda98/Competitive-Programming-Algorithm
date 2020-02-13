#include <iostream> 

using namespace std;

int main(){

	int n, p, cont = 0;
	
	cin >> n >> p;
	
	while(n--){
		
		int x , y;
		cin >> x >> y;
		
		if( (x+y) >= p )
			cont++;
		
	}
	
	cout << cont << endl;
	
	return 0;  
}
