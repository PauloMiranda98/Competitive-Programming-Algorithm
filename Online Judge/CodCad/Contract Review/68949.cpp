#include <iostream> 

using namespace std;

int main(){

	char r;
	string a;
	
	cin >> r >> a;

	while( (r != '0') || (a != "0") ){
		for(int i=0; i < a.size();){
			if(a[i] == r)
				a.erase(i, 1);			
			else
				i++;
		}
		
		while( (a.size() > 0) && (a[0] == '0') ){
			a.erase(0,1);
		}	
		
		if(a.size() == 0){
			a.push_back('0');
		}
					
		cout << a << endl;
		
		cin >> r >> a;
	}
	return 0;  
}
