#include <iostream> 
#include <string.h> 

using namespace std;

int main(){

	int a[1001], b[1001], c[1001];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	
	int n, m, maior;
	cin >> m >> n;
	
	maior = max(n, m);

	for(int i=0; i<m; i++)
		cin >> a[i];
	for(int i=0; i<n; i++)
		cin >> b[i];
	
	int carry=0;
			
	for(int i=maior-1; i>=0; i--){
		switch(a[i] + b[i] + carry){
			case 0:
				c[i] = 0;
				carry = 0;
				break;
			case 1:
				c[i] = 1;
				carry = 0;
				break;
			case 2:
				c[i] = 0;
				carry = 1;
				break;
			case 3:
				c[i] = 1;
				carry = 1;
				break;
		}		
			
	}
	
	while( (c[maior-1] == 0) && (maior > 0) )
		maior--;
		
	cout << c[0];
	for(int i=1; i<maior; i++)
		cout << " " << c[i];
	cout << endl;
	
	return 0;  
}
