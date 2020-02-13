#include <iostream> 
#include <string.h> 

using namespace std;

int main(){
	
	char a;
	double b, c;
	
	cin >> a;
	cin >> b >> c;
	
	cout.precision(2);
	cout << fixed;
	
	if(a == 'M')
		cout << (b*c) << endl;
	else
		cout << (b/c) << endl;
	return 0;  
}
