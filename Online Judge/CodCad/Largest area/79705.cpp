
#include <iostream>

using namespace std;

int main(){
	int b1, b2;
	int h1, h2;
	int a1, a2;
	cin >> b1 >> h1;
	cin >> b2 >> h2;
	a1 = b1 * h1;
	a2 = b2 * h2;
	
	if(a1 > a2){
		cout << "Primeiro" << endl;
	}
	else if(a1 < a2){
		cout << "Segundo" << endl;
	}
	else{
		cout << "Empate" << endl;
	}
	return 0;
}

