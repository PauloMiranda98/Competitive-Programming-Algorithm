#include <iostream>
#include <queue>

using namespace std;

int main(){
	
	queue<char> fila;

	for(char i = 'A';i <= 'P';i++){	 
		fila.push(i);
	}
		
	for(int i = 1;i <= 15;i++){	 
		int a, b;
		cin >> a >> b;
		
		if(a > b){
			fila.push(fila.front());
			fila.pop();
			fila.pop();
		}else{
			fila.pop();
			fila.push(fila.front());		
			fila.pop();
		}
	}
	
	cout << fila.front() << endl;
	
	return 0;
}
