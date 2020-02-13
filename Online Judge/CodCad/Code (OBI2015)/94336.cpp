#include <iostream>

using namespace std;

int main(){
	long int n, cont = 0;
	char a;
	string res;
	
	cin >> n;
	
	while(n != 0){
		cin >> a;
		res.push_back(a);
		
		n--;
	}
	
	for(long int i=0; i<(long)res.size()-2; i++){
		string aux;
		aux += res[i];
		aux += res[i+1];
		aux += res[i+2];
		
		if(aux == "100")
			cont++;
	}
	
	cout << cont << endl;
		
	return 0;
}