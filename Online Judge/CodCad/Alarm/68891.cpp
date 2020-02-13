#include <iostream> 

using namespace std;

int main(){
	
	int a, b, c, d;
	
	cin >> a >> b >> c >> d;
	
	while(a || b || c || d ){
		
		if( c < a || ( (c == a) && (d < b) ) )
			c += 24;
		
		int res = (c-a)*60 + (d-b);
	
		cout << res << endl;
		
		cin >> a >> b >> c >> d;	  
	}
	return 0;  
}
