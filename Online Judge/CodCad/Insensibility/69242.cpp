#include <iostream>
#include <string.h>

using namespace std;

int main(){
	
	int soma = 0;
	
	int x1, y1, x2, y2;
	int n;
	
	cin >> n;
	
	while(n--){
		cin >> x1 >> y1 >> x2 >> y2;
		soma += ( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
	}
	
	cout << soma << endl;
	
	return 0;
}
