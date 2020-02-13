#include <iostream> 

using namespace std;

int main(){

	int a[100][100];
	int b[100][100];
	int n;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> b[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		cout << a[i][0] + b[i][0];
		for(int j=1; j<n; j++){
			cout << " " << (a[i][j] + b[i][j]);
		}
		cout << endl;
	}

	
	return 0;  
}
