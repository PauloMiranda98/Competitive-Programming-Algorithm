#include <iostream> 

using namespace std;

int main(){

	int t, cont=0;
	string a, b;

	cin >> t;
	cin >> a >> b;
	
	for(int i=0; i < t; i++)
		if(a[i] == b[i])
			cont++;
			
	cout << cont << endl;
		
	return 0;  
}
